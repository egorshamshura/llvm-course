#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"

using namespace llvm;

struct UserToInstructionPass : public PassInfoMixin<UserToInstructionPass> {
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM) {
    LLVMContext &Ctx = M.getContext();
    IRBuilder<> builder(Ctx);
    Type *retType = Type::getVoidTy(Ctx);
    /*Prepare instruction logger function*/
    ArrayRef<Type*> userToInstParamTypes = {builder.getInt8Ty()->getPointerTo(), builder.getInt8Ty()->getPointerTo()};
    FunctionType *userToInstLogFuncType = FunctionType::get(retType, userToInstParamTypes, false);
    FunctionCallee userInstLogFunc = M.getOrInsertFunction("userToInstruction", userToInstLogFuncType);
    for (auto& F: M) {
      if (F.getName() == "userToInstruction") {
        continue;
      }
      for (auto &B : F) {
        for (auto &I : B) {
          if (auto* test = dyn_cast<PHINode>(&I)) {
            continue;
          }
          builder.SetInsertPoint(&I);
          Value *iName = builder.CreateGlobalString(I.getOpcodeName());
          for (auto *U: I.users()) {
            if (auto *user = dyn_cast<Instruction>(U)) {
              Value *userName = builder.CreateGlobalString(user->getOpcodeName());
              Value *args[] = {iName, userName};
              builder.CreateCall(userInstLogFunc, args);
            }
          }
        }
      }
    }
    return PreservedAnalyses::all();
  };
};

PassPluginLibraryInfo getPassPluginInfo() {
  const auto callback = [](PassBuilder &PB) {
    PB.registerOptimizerLastEPCallback([&](ModulePassManager &MPM, auto) {
      MPM.addPass(UserToInstructionPass{});
      return true;
    });
  };

  return {LLVM_PLUGIN_API_VERSION, "MyPlugin", "0.0.1", callback};
};

/* When a plugin is loaded by the driver, it will call this entry point to
obtain information about this plugin and about how to register its passes.
*/
extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return getPassPluginInfo();
}
