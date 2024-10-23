#include "sim.h"
#include <memory>

#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/CodeGen.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

int main(int argc, char* argv[]) {
  LLVMContext context;
  auto module = std::make_unique<Module>(
      "app.c", context);
  auto& M = *module;
  IRBuilder builder(context);
  auto initFuncTy =
      FunctionType::get(builder.getVoidTy(), {builder.getPtrTy()}, false);
  auto initFunc =
      Function::Create(initFuncTy, Function::ExternalLinkage, "init", &M);

  auto clearFuncTy =
      FunctionType::get(builder.getVoidTy(), {builder.getPtrTy()}, false);
  auto clearFunc =
      Function::Create(clearFuncTy, Function::ExternalLinkage, "clear", &M);

  auto dumpFuncTy =
      FunctionType::get(builder.getVoidTy(), {builder.getPtrTy()}, false);
  auto dumpFunc =
      Function::Create(dumpFuncTy, Function::ExternalLinkage, "dump", &M);

  auto simPutPixelFuncTy = FunctionType::get(
      builder.getVoidTy(),
      {builder.getIntNTy(32), builder.getIntNTy(32), builder.getIntNTy(32)},
      false);
  auto simPutPixelFunc = Function::Create(
      simPutPixelFuncTy, Function::ExternalLinkage, "simPutPixel", &M);

  auto simFlushFuncTy = FunctionType::get(builder.getVoidTy(), {}, true);
  auto simFlushFunc = Function::Create(
      simFlushFuncTy, Function::ExternalLinkage, "simFlush", &M);

  auto getFuncTy =
      FunctionType::get(builder.getIntNTy(32),
                        {builder.getIntNTy(32), builder.getIntNTy(32)}, false);
  auto getFunc =
      Function::Create(getFuncTy, Function::ExternalLinkage, "get", &M);

  auto next_generationFuncTy = FunctionType::get(
      builder.getVoidTy(),
      {builder.getPtrTy(), builder.getPtrTy(), builder.getPtrTy()}, false);
  auto next_generationFunc = Function::Create(
      next_generationFuncTy, Function::ExternalLinkage, "next_generation", &M);

  auto appFuncTy = FunctionType::get(builder.getVoidTy(), {}, false);
  auto appFunc =
      Function::Create(appFuncTy, Function::ExternalLinkage, "app", &M);

  BasicBlock* _0 = BasicBlock::Create(context, "", initFunc);
  BasicBlock* _1 = BasicBlock::Create(context, "", initFunc);
  BasicBlock* _2 = BasicBlock::Create(context, "", initFunc);
  BasicBlock* _3 = BasicBlock::Create(context, "", initFunc);
  BasicBlock* _4 = BasicBlock::Create(context, "", initFunc);
  BasicBlock* _5 = BasicBlock::Create(context, "", initFunc);
  BasicBlock* _6 = BasicBlock::Create(context, "", initFunc);
  BasicBlock* _7 = BasicBlock::Create(context, "", initFunc);
  BasicBlock* _8 = BasicBlock::Create(context, "", initFunc);
  BasicBlock* _135 = BasicBlock::Create(context, "", clearFunc);
  BasicBlock* _136 = BasicBlock::Create(context, "", clearFunc);
  BasicBlock* _137 = BasicBlock::Create(context, "", clearFunc);
  BasicBlock* _138 = BasicBlock::Create(context, "", clearFunc);
  BasicBlock* _139 = BasicBlock::Create(context, "", clearFunc);
  BasicBlock* _140 = BasicBlock::Create(context, "", clearFunc);
  BasicBlock* _141 = BasicBlock::Create(context, "", clearFunc);
  BasicBlock* _142 = BasicBlock::Create(context, "", clearFunc);
  BasicBlock* _143 = BasicBlock::Create(context, "", clearFunc);
  BasicBlock* _162 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _163 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _164 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _165 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _166 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _167 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _168 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _169 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _170 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _171 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _172 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _173 = BasicBlock::Create(context, "", dumpFunc);
  BasicBlock* _202 = BasicBlock::Create(context, "", getFunc);
  BasicBlock* _212 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _213 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _214 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _215 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _216 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _217 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _218 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _219 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _220 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _221 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _222 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _223 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _224 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _225 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _226 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _227 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _228 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _229 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _230 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _231 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _232 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _233 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _234 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _235 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _236 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _237 = BasicBlock::Create(context, "", next_generationFunc);
  BasicBlock* _437 = BasicBlock::Create(context, "", appFunc);
  BasicBlock* _438 = BasicBlock::Create(context, "", appFunc);
  BasicBlock* _439 = BasicBlock::Create(context, "", appFunc);
  BasicBlock* _440 = BasicBlock::Create(context, "", appFunc);

  // init
  builder.SetInsertPoint(_0);
  //   %2 = alloca ptr, align 8
  auto _9 = builder.CreateAlloca(builder.getPtrTy());
  //   %3 = alloca i32, align 4
  auto _10 = builder.CreateAlloca(builder.getIntNTy(32));
  //   %4 = alloca i32, align 4
  auto _11 = builder.CreateAlloca(builder.getIntNTy(32));
  //   store ptr %0, ptr %2, align 8
  builder.CreateStore(initFunc->getArg(0), _9);
  //   store i32 0, ptr %3, align 4
  builder.CreateStore(builder.getIntN(32, 0), _10);
  //   br label %5
  builder.CreateBr(_1);

  builder.SetInsertPoint(_1);
  //   %6 = load i32, ptr %3, align 4
  auto _12 = builder.CreateLoad(builder.getIntNTy(32), _10);
  //   %7 = icmp ne i32 %6, 512
  auto _13 =
      builder.CreateICmp(CmpInst::ICMP_NE, _12, builder.getIntN(32, 512));
  //   br i1 %7, label %8, label %27
  builder.CreateCondBr(_13, _2, _8);

  builder.SetInsertPoint(_2);
  //   store i32 0, ptr %4, align 4
  builder.CreateStore(builder.getIntN(32, 0), _11);
  //   br label %9
  builder.CreateBr(_3);

  builder.SetInsertPoint(_3);
  //   %10 = load i32, ptr %4, align 4
  auto _14 = builder.CreateLoad(builder.getIntNTy(32), _11);
  //   %11 = icmp ne i32 %10, 256
  auto _15 =
      builder.CreateICmp(CmpInst::ICMP_NE, _14, builder.getIntN(32, 256));
  //   br i1 %11, label %12, label %23
  builder.CreateCondBr(_15, _4, _6);

  builder.SetInsertPoint(_4);
  //   %13 = load ptr, ptr %2, align 8
  auto _16 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %14 = load i32, ptr %3, align 4
  auto _17 = builder.CreateLoad(builder.getIntNTy(32), _10);
  //   %15 = sext i32 %14 to i64
  auto _18 = builder.CreateSExt(_17, builder.getIntNTy(64));
  //   %16 = getelementptr inbounds [256 x i8], ptr %13, i64 %15
  auto _19 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _16, {_18});
  //   %17 = load i32, ptr %4, align 4
  auto _20 = builder.CreateLoad(builder.getIntNTy(32), _11);
  //   %18 = sext i32 %17 to i64
  auto _21 = builder.CreateSExt(_20, builder.getIntNTy(64));
  //   %19 = getelementptr inbounds [256 x i8], ptr %16, i64 0, i64 %18
  auto _22 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _19,
                               {builder.getIntN(64, 0), _21});
  //   store i8 0, ptr %19, align 1
  builder.CreateStore(builder.getIntN(8, 0), _22);
  //   br label %20
  builder.CreateBr(_5);

  builder.SetInsertPoint(_5);
  //   %21 = load i32, ptr %4, align 4
  auto _23 = builder.CreateLoad(builder.getIntNTy(32), _11);
  //   %22 = add nsw i32 %21, 1
  auto _24 = builder.CreateAdd(_23, builder.getIntN(32, 1));
  //   store i32 %22, ptr %4, align 4
  builder.CreateStore(_24, _11);
  //   br label %9, !llvm.loop !5
  builder.CreateBr(_3);

  builder.SetInsertPoint(_6);
  //   br label %24
  builder.CreateBr(_7);

  builder.SetInsertPoint(_7);
  //   %25 = load i32, ptr %3, align 4
  auto _25 = builder.CreateLoad(builder.getIntNTy(32), _10);
  //   %26 = add nsw i32 %25, 1
  auto _26 = builder.CreateAdd(_25, builder.getIntN(32, 1));
  //   store i32 %26, ptr %3, align 4
  builder.CreateStore(_26, _10);
  //   br label %5, !llvm.loop !7
  builder.CreateBr(_1);

  builder.SetInsertPoint(_8);
  //   %28 = load ptr, ptr %2, align 8
  auto _27 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %29 = getelementptr inbounds [256 x i8], ptr %28, i64 1
  auto _28 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _27,
                               {builder.getIntN(64, 1)});
  //   %30 = getelementptr inbounds [256 x i8], ptr %29, i64 0, i64 6
  auto _29 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _28,
                        {builder.getIntN(64, 0), builder.getIntN(64, 6)});
  //   store i8 1, ptr %30, align 1
  builder.CreateStore(builder.getIntN(8, 1), _29);
  //   %31 = load ptr, ptr %2, align 8
  auto _30 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %32 = getelementptr inbounds [256 x i8], ptr %31, i64 1
  auto _31 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _30,
                               {builder.getIntN(64, 1)});
  //   %33 = getelementptr inbounds [256 x i8], ptr %32, i64 0, i64 7
  auto _32 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _31,
                        {builder.getIntN(64, 0), builder.getIntN(64, 7)});
  //   store i8 1, ptr %33, align 1
  builder.CreateStore(builder.getIntN(8, 1), _32);
  //   %34 = load ptr, ptr %2, align 8
  auto _33 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %35 = getelementptr inbounds [256 x i8], ptr %34, i64 2
  auto _34 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _33,
                               {builder.getIntN(64, 2)});
  //   %36 = getelementptr inbounds [256 x i8], ptr %35, i64 0, i64 6
  auto _35 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _34,
                        {builder.getIntN(64, 0), builder.getIntN(64, 6)});
  //   store i8 1, ptr %36, align 1
  builder.CreateStore(builder.getIntN(8, 1), _35);
  //   %37 = load ptr, ptr %2, align 8
  auto _36 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %38 = getelementptr inbounds [256 x i8], ptr %37, i64 2
  auto _37 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _36,
                               {builder.getIntN(64, 2)});
  //   %39 = getelementptr inbounds [256 x i8], ptr %38, i64 0, i64 7
  auto _38 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _37,
                        {builder.getIntN(64, 0), builder.getIntN(64, 7)});
  //   store i8 1, ptr %39, align 1
  builder.CreateStore(builder.getIntN(8, 1), _38);
  //   %40 = load ptr, ptr %2, align 8
  auto _39 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %41 = getelementptr inbounds [256 x i8], ptr %40, i64 11
  auto _40 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _39,
                               {builder.getIntN(64, 11)});
  //   %42 = getelementptr inbounds [256 x i8], ptr %41, i64 0, i64 6
  auto _41 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _40,
                        {builder.getIntN(64, 0), builder.getIntN(64, 6)});
  //   store i8 1, ptr %42, align 1
  builder.CreateStore(builder.getIntN(8, 1), _41);
  //   %43 = load ptr, ptr %2, align 8
  auto _42 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %44 = getelementptr inbounds [256 x i8], ptr %43, i64 11
  auto _43 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _42,
                               {builder.getIntN(64, 11)});
  //   %45 = getelementptr inbounds [256 x i8], ptr %44, i64 0, i64 7
  auto _44 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _43,
                        {builder.getIntN(64, 0), builder.getIntN(64, 7)});
  //   store i8 1, ptr %45, align 1
  builder.CreateStore(builder.getIntN(8, 1), _44);
  //   %46 = load ptr, ptr %2, align 8
  auto _45 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %47 = getelementptr inbounds [256 x i8], ptr %46, i64 11
  auto _46 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _45,
                               {builder.getIntN(64, 11)});
  //   %48 = getelementptr inbounds [256 x i8], ptr %47, i64 0, i64 8
  auto _47 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _46,
                        {builder.getIntN(64, 0), builder.getIntN(64, 8)});
  //   store i8 1, ptr %48, align 1
  builder.CreateStore(builder.getIntN(8, 1), _47);
  //   %49 = load ptr, ptr %2, align 8
  auto _48 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %50 = getelementptr inbounds [256 x i8], ptr %49, i64 12
  auto _49 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _48,
                               {builder.getIntN(64, 12)});
  //   %51 = getelementptr inbounds [256 x i8], ptr %50, i64 0, i64 5
  auto _50 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _49,
                        {builder.getIntN(64, 0), builder.getIntN(64, 5)});
  //   store i8 1, ptr %51, align 1
  builder.CreateStore(builder.getIntN(8, 1), _50);
  //   %52 = load ptr, ptr %2, align 8
  auto _51 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %53 = getelementptr inbounds [256 x i8], ptr %52, i64 12
  auto _52 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _51,
                               {builder.getIntN(64, 12)});
  //   %54 = getelementptr inbounds [256 x i8], ptr %53, i64 0, i64 9
  auto _53 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _52,
                        {builder.getIntN(64, 0), builder.getIntN(64, 9)});
  //   store i8 1, ptr %54, align 1
  builder.CreateStore(builder.getIntN(8, 1), _53);
  //   %55 = load ptr, ptr %2, align 8
  auto _54 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %56 = getelementptr inbounds [256 x i8], ptr %55, i64 13
  auto _55 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _54,
                               {builder.getIntN(64, 13)});
  //   %57 = getelementptr inbounds [256 x i8], ptr %56, i64 0, i64 4
  auto _56 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _55,
                        {builder.getIntN(64, 0), builder.getIntN(64, 4)});
  //   store i8 1, ptr %57, align 1
  builder.CreateStore(builder.getIntN(8, 1), _56);
  //   %58 = load ptr, ptr %2, align 8
  auto _57 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %59 = getelementptr inbounds [256 x i8], ptr %58, i64 13
  auto _58 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _57,
                               {builder.getIntN(64, 13)});
  //   %60 = getelementptr inbounds [256 x i8], ptr %59, i64 0, i64 10
  auto _59 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _58,
                        {builder.getIntN(64, 0), builder.getIntN(64, 10)});
  //   store i8 1, ptr %60, align 1
  builder.CreateStore(builder.getIntN(8, 1), _59);
  //   %61 = load ptr, ptr %2, align 8
  auto _60 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %62 = getelementptr inbounds [256 x i8], ptr %61, i64 14
  auto _61 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _60,
                               {builder.getIntN(64, 14)});
  //   %63 = getelementptr inbounds [256 x i8], ptr %62, i64 0, i64 4
  auto _62 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _61,
                        {builder.getIntN(64, 0), builder.getIntN(64, 4)});
  //   store i8 1, ptr %63, align 1
  builder.CreateStore(builder.getIntN(8, 1), _62);
  //   %64 = load ptr, ptr %2, align 8
  auto _63 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %65 = getelementptr inbounds [256 x i8], ptr %64, i64 14
  auto _64 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _63,
                               {builder.getIntN(64, 14)});
  //   %66 = getelementptr inbounds [256 x i8], ptr %65, i64 0, i64 10
  auto _65 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _64,
                        {builder.getIntN(64, 0), builder.getIntN(64, 10)});
  //   store i8 1, ptr %66, align 1
  builder.CreateStore(builder.getIntN(8, 1), _65);
  //   %67 = load ptr, ptr %2, align 8
  auto _66 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %68 = getelementptr inbounds [256 x i8], ptr %67, i64 15
  auto _67 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _66,
                               {builder.getIntN(64, 15)});
  //   %69 = getelementptr inbounds [256 x i8], ptr %68, i64 0, i64 7
  auto _68 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _67,
                        {builder.getIntN(64, 0), builder.getIntN(64, 7)});
  //   store i8 1, ptr %69, align 1
  builder.CreateStore(builder.getIntN(8, 1), _68);
  //   %70 = load ptr, ptr %2, align 8
  auto _69 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %71 = getelementptr inbounds [256 x i8], ptr %70, i64 16
  auto _70 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _69,
                               {builder.getIntN(64, 16)});
  //   %72 = getelementptr inbounds [256 x i8], ptr %71, i64 0, i64 5
  auto _71 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _70,
                        {builder.getIntN(64, 0), builder.getIntN(64, 5)});
  //   store i8 1, ptr %72, align 1
  builder.CreateStore(builder.getIntN(8, 1), _71);
  //   %73 = load ptr, ptr %2, align 8
  auto _72 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %74 = getelementptr inbounds [256 x i8], ptr %73, i64 16
  auto _73 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _72,
                               {builder.getIntN(64, 16)});
  //   %75 = getelementptr inbounds [256 x i8], ptr %74, i64 0, i64 9
  auto _74 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _73,
                        {builder.getIntN(64, 0), builder.getIntN(64, 9)});
  //   store i8 1, ptr %75, align 1
  builder.CreateStore(builder.getIntN(8, 1), _74);
  //   %76 = load ptr, ptr %2, align 8
  auto _75 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %77 = getelementptr inbounds [256 x i8], ptr %76, i64 17
  auto _76 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _75,
                               {builder.getIntN(64, 17)});
  //   %78 = getelementptr inbounds [256 x i8], ptr %77, i64 0, i64 6
  auto _77 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _76,
                        {builder.getIntN(64, 0), builder.getIntN(64, 6)});
  //   store i8 1, ptr %78, align 1
  builder.CreateStore(builder.getIntN(8, 1), _77);
  //   %79 = load ptr, ptr %2, align 8
  auto _78 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %80 = getelementptr inbounds [256 x i8], ptr %79, i64 17
  auto _79 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _78,
                               {builder.getIntN(64, 17)});
  //   %81 = getelementptr inbounds [256 x i8], ptr %80, i64 0, i64 7
  auto _80 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _79,
                        {builder.getIntN(64, 0), builder.getIntN(64, 7)});
  //   store i8 1, ptr %81, align 1
  builder.CreateStore(builder.getIntN(8, 1), _80);
  //   %82 = load ptr, ptr %2, align 8
  auto _81 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %83 = getelementptr inbounds [256 x i8], ptr %82, i64 17
  auto _82 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _81,
                               {builder.getIntN(64, 17)});
  //   %84 = getelementptr inbounds [256 x i8], ptr %83, i64 0, i64 8
  auto _83 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _82,
                        {builder.getIntN(64, 0), builder.getIntN(64, 8)});
  //   store i8 1, ptr %84, align 1
  builder.CreateStore(builder.getIntN(8, 1), _83);
  //   %85 = load ptr, ptr %2, align 8
  auto _84 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %86 = getelementptr inbounds [256 x i8], ptr %85, i64 18
  auto _85 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _84,
                               {builder.getIntN(64, 18)});
  //   %87 = getelementptr inbounds [256 x i8], ptr %86, i64 0, i64 7
  auto _86 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _85,
                        {builder.getIntN(64, 0), builder.getIntN(64, 7)});
  //   store i8 1, ptr %87, align 1
  builder.CreateStore(builder.getIntN(8, 1), _86);
  //   %88 = load ptr, ptr %2, align 8
  auto _87 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %89 = getelementptr inbounds [256 x i8], ptr %88, i64 21
  auto _88 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _87,
                               {builder.getIntN(64, 21)});
  //   %90 = getelementptr inbounds [256 x i8], ptr %89, i64 0, i64 6
  auto _89 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _88,
                        {builder.getIntN(64, 0), builder.getIntN(64, 6)});
  //   store i8 1, ptr %90, align 1
  builder.CreateStore(builder.getIntN(8, 1), _89);
  //   %91 = load ptr, ptr %2, align 8
  auto _90 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %92 = getelementptr inbounds [256 x i8], ptr %91, i64 21
  auto _91 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _90,
                               {builder.getIntN(64, 21)});
  //   %93 = getelementptr inbounds [256 x i8], ptr %92, i64 0, i64 5
  auto _92 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _91,
                        {builder.getIntN(64, 0), builder.getIntN(64, 5)});
  //   store i8 1, ptr %93, align 1
  builder.CreateStore(builder.getIntN(8, 1), _92);
  //   %94 = load ptr, ptr %2, align 8
  auto _93 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %95 = getelementptr inbounds [256 x i8], ptr %94, i64 21
  auto _94 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _93,
                               {builder.getIntN(64, 21)});
  //   %96 = getelementptr inbounds [256 x i8], ptr %95, i64 0, i64 4
  auto _95 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _94,
                        {builder.getIntN(64, 0), builder.getIntN(64, 4)});
  //   store i8 1, ptr %96, align 1
  builder.CreateStore(builder.getIntN(8, 1), _95);
  //   %97 = load ptr, ptr %2, align 8
  auto _96 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %98 = getelementptr inbounds [256 x i8], ptr %97, i64 22
  auto _97 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _96,
                               {builder.getIntN(64, 22)});
  //   %99 = getelementptr inbounds [256 x i8], ptr %98, i64 0, i64 6
  auto _98 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _97,
                        {builder.getIntN(64, 0), builder.getIntN(64, 6)});
  //   store i8 1, ptr %99, align 1
  builder.CreateStore(builder.getIntN(8, 1), _98);
  //   %100 = load ptr, ptr %2, align 8
  auto _99 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %101 = getelementptr inbounds [256 x i8], ptr %100, i64 22
  auto _100 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _99,
                                {builder.getIntN(64, 22)});
  //   %102 = getelementptr inbounds [256 x i8], ptr %101, i64 0, i64 5
  auto _101 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _100,
                        {builder.getIntN(64, 0), builder.getIntN(64, 5)});
  //   store i8 1, ptr %102, align 1
  builder.CreateStore(builder.getIntN(8, 1), _101);
  //   %103 = load ptr, ptr %2, align 8
  auto _102 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %104 = getelementptr inbounds [256 x i8], ptr %103, i64 22
  auto _103 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _102,
                                {builder.getIntN(64, 22)});
  //   %105 = getelementptr inbounds [256 x i8], ptr %104, i64 0, i64 4
  auto _104 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _103,
                        {builder.getIntN(64, 0), builder.getIntN(64, 4)});
  //   store i8 1, ptr %105, align 1
  builder.CreateStore(builder.getIntN(8, 1), _104);
  //   %106 = load ptr, ptr %2, align 8
  auto _105 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %107 = getelementptr inbounds [256 x i8], ptr %106, i64 23
  auto _106 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _105,
                                {builder.getIntN(64, 23)});
  //   %108 = getelementptr inbounds [256 x i8], ptr %107, i64 0, i64 3
  auto _107 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _106,
                        {builder.getIntN(64, 0), builder.getIntN(64, 3)});
  //   store i8 1, ptr %108, align 1
  builder.CreateStore(builder.getIntN(8, 1), _107);
  //   %109 = load ptr, ptr %2, align 8
  auto _108 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %110 = getelementptr inbounds [256 x i8], ptr %109, i64 23
  auto _109 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _108,
                                {builder.getIntN(64, 23)});
  //   %111 = getelementptr inbounds [256 x i8], ptr %110, i64 0, i64 7
  auto _110 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _109,
                        {builder.getIntN(64, 0), builder.getIntN(64, 7)});
  //   store i8 1, ptr %111, align 1
  builder.CreateStore(builder.getIntN(8, 1), _110);
  //   %112 = load ptr, ptr %2, align 8
  auto _111 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %113 = getelementptr inbounds [256 x i8], ptr %112, i64 25
  auto _112 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _111,
                                {builder.getIntN(64, 25)});
  //   %114 = getelementptr inbounds [256 x i8], ptr %113, i64 0, i64 2
  auto _113 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _112,
                        {builder.getIntN(64, 0), builder.getIntN(64, 2)});
  //   store i8 1, ptr %114, align 1
  builder.CreateStore(builder.getIntN(8, 1), _113);
  //   %115 = load ptr, ptr %2, align 8
  auto _114 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %116 = getelementptr inbounds [256 x i8], ptr %115, i64 25
  auto _115 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _114,
                                {builder.getIntN(64, 25)});
  //   %117 = getelementptr inbounds [256 x i8], ptr %116, i64 0, i64 3
  auto _116 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _115,
                        {builder.getIntN(64, 0), builder.getIntN(64, 3)});
  //   store i8 1, ptr %117, align 1
  builder.CreateStore(builder.getIntN(8, 1), _116);
  //   %118 = load ptr, ptr %2, align 8
  auto _117 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %119 = getelementptr inbounds [256 x i8], ptr %118, i64 25
  auto _118 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _117,
                                {builder.getIntN(64, 25)});
  //   %120 = getelementptr inbounds [256 x i8], ptr %119, i64 0, i64 7
  auto _119 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _118,
                        {builder.getIntN(64, 0), builder.getIntN(64, 7)});
  //   store i8 1, ptr %120, align 1
  builder.CreateStore(builder.getIntN(8, 1), _119);
  //   %121 = load ptr, ptr %2, align 8
  auto _120 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %122 = getelementptr inbounds [256 x i8], ptr %121, i64 25
  auto _121 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _120,
                                {builder.getIntN(64, 25)});
  //   %123 = getelementptr inbounds [256 x i8], ptr %122, i64 0, i64 8
  auto _122 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _121,
                        {builder.getIntN(64, 0), builder.getIntN(64, 8)});
  //   store i8 1, ptr %123, align 1
  builder.CreateStore(builder.getIntN(8, 1), _122);
  //   %124 = load ptr, ptr %2, align 8
  auto _123 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %125 = getelementptr inbounds [256 x i8], ptr %124, i64 35
  auto _124 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _123,
                                {builder.getIntN(64, 35)});
  //   %126 = getelementptr inbounds [256 x i8], ptr %125, i64 0, i64 4
  auto _125 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _124,
                        {builder.getIntN(64, 0), builder.getIntN(64, 4)});
  //   store i8 1, ptr %126, align 1
  builder.CreateStore(builder.getIntN(8, 1), _125);
  //   %127 = load ptr, ptr %2, align 8
  auto _126 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %128 = getelementptr inbounds [256 x i8], ptr %127, i64 35
  auto _127 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _126,
                                {builder.getIntN(64, 35)});
  //   %129 = getelementptr inbounds [256 x i8], ptr %128, i64 0, i64 5
  auto _128 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _127,
                        {builder.getIntN(64, 0), builder.getIntN(64, 5)});
  //   store i8 1, ptr %129, align 1
  builder.CreateStore(builder.getIntN(8, 1), _128);
  //   %130 = load ptr, ptr %2, align 8
  auto _129 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %131 = getelementptr inbounds [256 x i8], ptr %130, i64 36
  auto _130 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _129,
                                {builder.getIntN(64, 36)});
  //   %132 = getelementptr inbounds [256 x i8], ptr %131, i64 0, i64 4
  auto _131 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _130,
                        {builder.getIntN(64, 0), builder.getIntN(64, 4)});
  //   store i8 1, ptr %132, align 1
  builder.CreateStore(builder.getIntN(8, 1), _131);
  //   %133 = load ptr, ptr %2, align 8
  auto _132 = builder.CreateLoad(builder.getPtrTy(), _9);
  //   %134 = getelementptr inbounds [256 x i8], ptr %133, i64 36
  auto _133 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _132,
                                {builder.getIntN(64, 36)});
  //   %135 = getelementptr inbounds [256 x i8], ptr %134, i64 0, i64 5
  auto _134 =
      builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _133,
                        {builder.getIntN(64, 0), builder.getIntN(64, 5)});
  //   store i8 1, ptr %135, align 1
  builder.CreateStore(builder.getIntN(8, 1), _134);
  //   ret void
  builder.CreateRetVoid();

  // clear
  builder.SetInsertPoint(_135);
  //   %2 = alloca ptr, align 8
  auto _144 = builder.CreateAlloca(builder.getPtrTy());
  //   %3 = alloca i32, align 4
  auto _145 = builder.CreateAlloca(builder.getIntNTy(32));
  //   %4 = alloca i32, align 4
  auto _146 = builder.CreateAlloca(builder.getIntNTy(32));
  //   store ptr %0, ptr %2, align 8
  builder.CreateStore(clearFunc->getArg(0), _144);
  //   store i32 0, ptr %3, align 4
  builder.CreateStore(builder.getIntN(32, 0), _145);
  //   br label %5
  builder.CreateBr(_136);

  builder.SetInsertPoint(_136);
  //   %6 = load i32, ptr %3, align 4
  auto _147 = builder.CreateLoad(builder.getIntNTy(32), _145);
  //   %7 = icmp ne i32 %6, 512
  auto _148 =
      builder.CreateICmp(CmpInst::ICMP_NE, _147, builder.getIntN(32, 512));
  //   br i1 %7, label %8, label %27
  builder.CreateCondBr(_148, _137, _143);

  builder.SetInsertPoint(_137);
  //   store i32 0, ptr %4, align 4
  builder.CreateStore(builder.getIntN(32, 0), _146);
  //   br label %9
  builder.CreateBr(_138);

  builder.SetInsertPoint(_138);
  //   %10 = load i32, ptr %4, align 4
  auto _149 = builder.CreateLoad(builder.getIntNTy(32), _146);
  //   %11 = icmp ne i32 %10, 256
  auto _150 =
      builder.CreateICmp(CmpInst::ICMP_NE, _149, builder.getIntN(32, 256));
  //   br i1 %11, label %12, label %23
  builder.CreateCondBr(_150, _139, _141);

  builder.SetInsertPoint(_139);
  //   %13 = load ptr, ptr %2, align 8
  auto _151 = builder.CreateLoad(builder.getPtrTy(), _144);
  //   %14 = load i32, ptr %3, align 4
  auto _152 = builder.CreateLoad(builder.getIntNTy(32), _145);
  //   %15 = sext i32 %14 to i64
  auto _153 = builder.CreateSExt(_152, builder.getIntNTy(64));
  //   %16 = getelementptr inbounds [256 x i8], ptr %13, i64 %15
  auto _154 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _151,
                                {_153});
  //   %17 = load i32, ptr %4, align 4
  auto _155 = builder.CreateLoad(builder.getIntNTy(32), _146);
  //   %18 = sext i32 %17 to i64
  auto _156 = builder.CreateSExt(_155, builder.getIntNTy(64));
  //   %19 = getelementptr inbounds [256 x i8], ptr %16, i64 0, i64 %18
  auto _157 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _154,
                                {builder.getIntN(64, 0), _156});
  //   store i8 0, ptr %19, align 1
  builder.CreateStore(builder.getIntN(8, 0), _157);
  //   br label %20
  builder.CreateBr(_140);

  builder.SetInsertPoint(_140);
  //   %21 = load i32, ptr %4, align 4
  auto _158 = builder.CreateLoad(builder.getIntNTy(32), _146);
  //   %22 = add nsw i32 %21, 1
  auto _159 = builder.CreateAdd(_158, builder.getIntN(32, 1));
  //   store i32 %22, ptr %4, align 4
  builder.CreateStore(_159, _146);
  //   br label %9, !llvm.loop !5
  builder.CreateBr(_138);

  builder.SetInsertPoint(_141);
  //   br label %24
  builder.CreateBr(_142);

  builder.SetInsertPoint(_142);
  //   %25 = load i32, ptr %3, align 4
  auto _160 = builder.CreateLoad(builder.getIntNTy(32), _145);
  //   %26 = add nsw i32 %25, 1
  auto _161 = builder.CreateAdd(_160, builder.getIntN(32, 1));
  //   store i32 %26, ptr %3, align 4
  builder.CreateStore(_161, _145);
  //   br label %5, !llvm.loop !7
  builder.CreateBr(_136);

  builder.SetInsertPoint(_143);
  //   ret void
  builder.CreateRetVoid();

  // dump
  builder.SetInsertPoint(_162);
  //   %2 = alloca ptr, align 8
  auto _174 = builder.CreateAlloca(builder.getPtrTy());
  //   %3 = alloca i32, align 4
  auto _175 = builder.CreateAlloca(builder.getIntNTy(32));
  //   %4 = alloca i32, align 4
  auto _176 = builder.CreateAlloca(builder.getIntNTy(32));
  //   store ptr %0, ptr %2, align 8
  builder.CreateStore(dumpFunc->getArg(0), _174);
  //   store i32 0, ptr %3, align 4
  builder.CreateStore(builder.getIntN(32, 0), _175);
  //   br label %5
  builder.CreateBr(_163);

  builder.SetInsertPoint(_163);
  //   %6 = load i32, ptr %3, align 4
  auto _177 = builder.CreateLoad(builder.getIntNTy(32), _175);
  //   %7 = icmp ne i32 %6, 512
  auto _178 =
      builder.CreateICmp(CmpInst::ICMP_NE, _177, builder.getIntN(32, 512));
  //   br i1 %7, label %8, label %37
  builder.CreateCondBr(_178, _164, _173);

  builder.SetInsertPoint(_164);
  //   store i32 0, ptr %4, align 4
  builder.CreateStore(builder.getIntN(32, 0), _176);
  //   br label %9
  builder.CreateBr(_165);

  builder.SetInsertPoint(_165);
  //   %10 = load i32, ptr %4, align 4
  auto _179 = builder.CreateLoad(builder.getIntNTy(32), _176);
  //   %11 = icmp ne i32 %10, 256
  auto _180 =
      builder.CreateICmp(CmpInst::ICMP_NE, _179, builder.getIntN(32, 256));
  //   br i1 %11, label %12, label %33
  builder.CreateCondBr(_180, _166, _171);

  builder.SetInsertPoint(_166);
  //   %13 = load ptr, ptr %2, align 8
  auto _181 = builder.CreateLoad(builder.getPtrTy(), _174);
  //   %14 = load i32, ptr %3, align 4
  auto _182 = builder.CreateLoad(builder.getIntNTy(32), _175);
  //   %15 = sext i32 %14 to i64
  auto _183 = builder.CreateSExt(_182, builder.getIntNTy(64));
  //   %16 = getelementptr inbounds [256 x i8], ptr %13, i64 %15
  auto _184 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _181,
                                {_183});
  //   %17 = load i32, ptr %4, align 4
  auto _185 = builder.CreateLoad(builder.getIntNTy(32), _176);
  //   %18 = sext i32 %17 to i64
  auto _186 = builder.CreateSExt(_185, builder.getIntNTy(64));
  //   %19 = getelementptr inbounds [256 x i8], ptr %16, i64 0, i64 %18
  auto _187 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _184,
                                {builder.getIntN(64, 0), _186});
  //   %20 = load i8, ptr %19, align 1
  auto _188 = builder.CreateLoad(builder.getIntNTy(8), _187);
  //   %21 = sext i8 %20 to i32
  auto _189 = builder.CreateSExt(_188, builder.getIntNTy(32));
  //   %22 = icmp eq i32 %21, 1
  auto _190 =
      builder.CreateICmp(CmpInst::ICMP_EQ, _189, builder.getIntN(32, 1));
  //   br i1 %22, label %23, label %26
  builder.CreateCondBr(_190, _167, _168);

  builder.SetInsertPoint(_167);
  //   %24 = load i32, ptr %3, align 4
  auto _191 = builder.CreateLoad(builder.getIntNTy(32), _175);
  //   %25 = load i32, ptr %4, align 4
  auto _192 = builder.CreateLoad(builder.getIntNTy(32), _176);
  //   call void @simPutPixel(i32 noundef %24, i32 noundef %25, i32 noundef 0)
  auto _193 =
      builder.CreateCall(simPutPixelFunc, {_191, _192, builder.getIntN(32, 0)});
  //   br label %29
  builder.CreateBr(_169);

  builder.SetInsertPoint(_168);
  //   %27 = load i32, ptr %3, align 4
  auto _194 = builder.CreateLoad(builder.getIntNTy(32), _175);
  //   %28 = load i32, ptr %4, align 4
  auto _195 = builder.CreateLoad(builder.getIntNTy(32), _176);
  //   call void @simPutPixel(i32 noundef %27, i32 noundef %28, i32 noundef -1)
  auto _196 = builder.CreateCall(simPutPixelFunc,
                                 {_194, _195, builder.getIntN(32, -1)});
  //   br label %29
  builder.CreateBr(_169);

  builder.SetInsertPoint(_169);
  //   br label %30
  builder.CreateBr(_170);

  builder.SetInsertPoint(_170);
  //   %31 = load i32, ptr %4, align 4
  auto _197 = builder.CreateLoad(builder.getIntNTy(32), _176);
  //   %32 = add nsw i32 %31, 1
  auto _198 = builder.CreateAdd(_197, builder.getIntN(32, 1));
  //   store i32 %32, ptr %4, align 4
  builder.CreateStore(_198, _176);
  //   br label %9, !llvm.loop !5
  builder.CreateBr(_165);

  builder.SetInsertPoint(_171);
  //   br label %34
  builder.CreateBr(_172);

  builder.SetInsertPoint(_172);
  //   %35 = load i32, ptr %3, align 4
  auto _199 = builder.CreateLoad(builder.getIntNTy(32), _175);
  //   %36 = add nsw i32 %35, 1
  auto _200 = builder.CreateAdd(_199, builder.getIntN(32, 1));
  //   store i32 %36, ptr %3, align 4
  builder.CreateStore(_200, _175);
  //   br label %5, !llvm.loop !7
  builder.CreateBr(_163);

  builder.SetInsertPoint(_173);
  //   call void (...) @simFlush()
  auto _201 = builder.CreateCall(simFlushFunc, {});
  //   ret void
  builder.CreateRetVoid();

  // get
  builder.SetInsertPoint(_202);
  //   %3 = alloca i32, align 4
  auto _203 = builder.CreateAlloca(builder.getIntNTy(32));
  //   %4 = alloca i32, align 4
  auto _204 = builder.CreateAlloca(builder.getIntNTy(32));
  //   store i32 %0, ptr %3, align 4
  builder.CreateStore(getFunc->getArg(0), _203);
  //   store i32 %1, ptr %4, align 4
  builder.CreateStore(getFunc->getArg(1), _204);
  //   %5 = load i32, ptr %3, align 4
  auto _205 = builder.CreateLoad(builder.getIntNTy(32), _203);
  //   %6 = load i32, ptr %4, align 4
  auto _206 = builder.CreateLoad(builder.getIntNTy(32), _204);
  //   %7 = srem i32 %5, %6
  auto _207 = builder.CreateSRem(_205, _206);
  //   %8 = load i32, ptr %4, align 4
  auto _208 = builder.CreateLoad(builder.getIntNTy(32), _204);
  //   %9 = add nsw i32 %7, %8
  auto _209 = builder.CreateAdd(_207, _208);
  //   %10 = load i32, ptr %4, align 4
  auto _210 = builder.CreateLoad(builder.getIntNTy(32), _204);
  //   %11 = srem i32 %9, %10
  auto _211 = builder.CreateSRem(_209, _210);
  //   ret i32 %11
  builder.CreateRet(_211);

  // next_generation
  builder.SetInsertPoint(_212);
  //   %4 = alloca ptr, align 8
  auto _238 = builder.CreateAlloca(builder.getPtrTy());
  //   %5 = alloca ptr, align 8
  auto _239 = builder.CreateAlloca(builder.getPtrTy());
  //   %6 = alloca ptr, align 8
  auto _240 = builder.CreateAlloca(builder.getPtrTy());
  //   %7 = alloca i32, align 4
  auto _241 = builder.CreateAlloca(builder.getIntNTy(32));
  //   %8 = alloca i32, align 4
  auto _242 = builder.CreateAlloca(builder.getIntNTy(32));
  //   %9 = alloca i32, align 4
  auto _243 = builder.CreateAlloca(builder.getIntNTy(32));
  //   %10 = alloca i32, align 4
  auto _244 = builder.CreateAlloca(builder.getIntNTy(32));
  //   %11 = alloca i32, align 4
  auto _245 = builder.CreateAlloca(builder.getIntNTy(32));
  //   %12 = alloca i32, align 4
  auto _246 = builder.CreateAlloca(builder.getIntNTy(32));
  //   store ptr %0, ptr %4, align 8
  builder.CreateStore(next_generationFunc->getArg(0), _238);
  //   store ptr %1, ptr %5, align 8
  builder.CreateStore(next_generationFunc->getArg(1), _239);
  //   store ptr %2, ptr %6, align 8
  builder.CreateStore(next_generationFunc->getArg(2), _240);
  //   store i32 0, ptr %7, align 4
  builder.CreateStore(builder.getIntN(32, 0), _241);
  //   br label %13
  builder.CreateBr(_213);

  builder.SetInsertPoint(_213);
  //   %14 = load i32, ptr %7, align 4
  auto _247 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %15 = icmp ne i32 %14, 512
  auto _248 =
      builder.CreateICmp(CmpInst::ICMP_NE, _247, builder.getIntN(32, 512));
  //   br i1 %15, label %16, label %164
  builder.CreateCondBr(_248, _214, _225);

  builder.SetInsertPoint(_214);
  //   store i32 0, ptr %8, align 4
  builder.CreateStore(builder.getIntN(32, 0), _242);
  //   br label %17
  builder.CreateBr(_215);

  builder.SetInsertPoint(_215);
  //   %18 = load i32, ptr %8, align 4
  auto _249 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %19 = icmp ne i32 %18, 256
  auto _250 =
      builder.CreateICmp(CmpInst::ICMP_NE, _249, builder.getIntN(32, 256));
  //   br i1 %19, label %20, label %160
  builder.CreateCondBr(_250, _216, _223);

  builder.SetInsertPoint(_216);
  //   %21 = load ptr, ptr %5, align 8
  auto _251 = builder.CreateLoad(builder.getPtrTy(), _239);
  //   %22 = load i32, ptr %7, align 4
  auto _252 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %23 = sub nsw i32 %22, 1
  auto _253 = builder.CreateSub(_252, builder.getIntN(32, 1));
  //   %24 = call i32 @get(i32 noundef %23, i32 noundef 512)
  auto _254 = builder.CreateCall(getFunc, {_253, builder.getIntN(32, 512)});
  //   %25 = sext i32 %24 to i64
  auto _255 = builder.CreateSExt(_254, builder.getIntNTy(64));
  //   %26 = getelementptr inbounds [256 x i8], ptr %21, i64 %25
  auto _256 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _251,
                                {_255});
  //   %27 = load i32, ptr %8, align 4
  auto _257 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %28 = sub nsw i32 %27, 1
  auto _258 = builder.CreateSub(_257, builder.getIntN(32, 1));
  //   %29 = call i32 @get(i32 noundef %28, i32 noundef 256)
  auto _259 = builder.CreateCall(getFunc, {_258, builder.getIntN(32, 256)});
  //   %30 = sext i32 %29 to i64
  auto _260 = builder.CreateSExt(_259, builder.getIntNTy(64));
  //   %31 = getelementptr inbounds [256 x i8], ptr %26, i64 0, i64 %30
  auto _261 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _256,
                                {builder.getIntN(64, 0), _260});
  //   %32 = load i8, ptr %31, align 1
  auto _262 = builder.CreateLoad(builder.getIntNTy(8), _261);
  //   %33 = sext i8 %32 to i32
  auto _263 = builder.CreateSExt(_262, builder.getIntNTy(32));
  //   %34 = load ptr, ptr %5, align 8
  auto _264 = builder.CreateLoad(builder.getPtrTy(), _239);
  //   %35 = load i32, ptr %7, align 4
  auto _265 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %36 = sub nsw i32 %35, 1
  auto _266 = builder.CreateSub(_265, builder.getIntN(32, 1));
  //   %37 = call i32 @get(i32 noundef %36, i32 noundef 512)
  auto _267 = builder.CreateCall(getFunc, {_266, builder.getIntN(32, 512)});
  //   %38 = sext i32 %37 to i64
  auto _268 = builder.CreateSExt(_267, builder.getIntNTy(64));
  //   %39 = getelementptr inbounds [256 x i8], ptr %34, i64 %38
  auto _269 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _264,
                                {_268});
  //   %40 = load i32, ptr %8, align 4
  auto _270 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %41 = sext i32 %40 to i64
  auto _271 = builder.CreateSExt(_270, builder.getIntNTy(64));
  //   %42 = getelementptr inbounds [256 x i8], ptr %39, i64 0, i64 %41
  auto _272 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _269,
                                {builder.getIntN(64, 0), _271});
  //   %43 = load i8, ptr %42, align 1
  auto _273 = builder.CreateLoad(builder.getIntNTy(8), _272);
  //   %44 = sext i8 %43 to i32
  auto _274 = builder.CreateSExt(_273, builder.getIntNTy(32));
  //   %45 = add nsw i32 %33, %44
  auto _275 = builder.CreateAdd(_263, _274);
  //   %46 = load ptr, ptr %5, align 8
  auto _276 = builder.CreateLoad(builder.getPtrTy(), _239);
  //   %47 = load i32, ptr %7, align 4
  auto _277 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %48 = sub nsw i32 %47, 1
  auto _278 = builder.CreateSub(_277, builder.getIntN(32, 1));
  //   %49 = call i32 @get(i32 noundef %48, i32 noundef 512)
  auto _279 = builder.CreateCall(getFunc, {_278, builder.getIntN(32, 512)});
  //   %50 = sext i32 %49 to i64
  auto _280 = builder.CreateSExt(_279, builder.getIntNTy(64));
  //   %51 = getelementptr inbounds [256 x i8], ptr %46, i64 %50
  auto _281 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _276,
                                {_280});
  //   %52 = load i32, ptr %8, align 4
  auto _282 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %53 = add nsw i32 %52, 1
  auto _283 = builder.CreateAdd(_282, builder.getIntN(32, 1));
  //   %54 = call i32 @get(i32 noundef %53, i32 noundef 256)
  auto _284 = builder.CreateCall(getFunc, {_283, builder.getIntN(32, 256)});
  //   %55 = sext i32 %54 to i64
  auto _285 = builder.CreateSExt(_284, builder.getIntNTy(64));
  //   %56 = getelementptr inbounds [256 x i8], ptr %51, i64 0, i64 %55
  auto _286 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _281,
                                {builder.getIntN(64, 0), _285});
  //   %57 = load i8, ptr %56, align 1
  auto _287 = builder.CreateLoad(builder.getIntNTy(8), _286);
  //   %58 = sext i8 %57 to i32
  auto _288 = builder.CreateSExt(_287, builder.getIntNTy(32));
  //   %59 = add nsw i32 %45, %58
  auto _289 = builder.CreateAdd(_275, _288);
  //   %60 = load ptr, ptr %5, align 8
  auto _290 = builder.CreateLoad(builder.getPtrTy(), _239);
  //   %61 = load i32, ptr %7, align 4
  auto _291 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %62 = sext i32 %61 to i64
  auto _292 = builder.CreateSExt(_291, builder.getIntNTy(64));
  //   %63 = getelementptr inbounds [256 x i8], ptr %60, i64 %62
  auto _293 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _290,
                                {_292});
  //   %64 = load i32, ptr %8, align 4
  auto _294 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %65 = sub nsw i32 %64, 1
  auto _295 = builder.CreateSub(_294, builder.getIntN(32, 1));
  //   %66 = call i32 @get(i32 noundef %65, i32 noundef 256)
  auto _296 = builder.CreateCall(getFunc, {_295, builder.getIntN(32, 256)});
  //   %67 = sext i32 %66 to i64
  auto _297 = builder.CreateSExt(_296, builder.getIntNTy(64));
  //   %68 = getelementptr inbounds [256 x i8], ptr %63, i64 0, i64 %67
  auto _298 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _293,
                                {builder.getIntN(64, 0), _297});
  //   %69 = load i8, ptr %68, align 1
  auto _299 = builder.CreateLoad(builder.getIntNTy(8), _298);
  //   %70 = sext i8 %69 to i32
  auto _300 = builder.CreateSExt(_299, builder.getIntNTy(32));
  //   %71 = add nsw i32 %59, %70
  auto _301 = builder.CreateAdd(_289, _300);
  //   %72 = load ptr, ptr %5, align 8
  auto _302 = builder.CreateLoad(builder.getPtrTy(), _239);
  //   %73 = load i32, ptr %7, align 4
  auto _303 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %74 = sext i32 %73 to i64
  auto _304 = builder.CreateSExt(_303, builder.getIntNTy(64));
  //   %75 = getelementptr inbounds [256 x i8], ptr %72, i64 %74
  auto _305 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _302,
                                {_304});
  //   %76 = load i32, ptr %8, align 4
  auto _306 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %77 = add nsw i32 %76, 1
  auto _307 = builder.CreateAdd(_306, builder.getIntN(32, 1));
  //   %78 = call i32 @get(i32 noundef %77, i32 noundef 256)
  auto _308 = builder.CreateCall(getFunc, {_307, builder.getIntN(32, 256)});
  //   %79 = sext i32 %78 to i64
  auto _309 = builder.CreateSExt(_308, builder.getIntNTy(64));
  //   %80 = getelementptr inbounds [256 x i8], ptr %75, i64 0, i64 %79
  auto _310 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _305,
                                {builder.getIntN(64, 0), _309});
  //   %81 = load i8, ptr %80, align 1
  auto _311 = builder.CreateLoad(builder.getIntNTy(8), _310);
  //   %82 = sext i8 %81 to i32
  auto _312 = builder.CreateSExt(_311, builder.getIntNTy(32));
  //   %83 = add nsw i32 %71, %82
  auto _313 = builder.CreateAdd(_301, _312);
  //   %84 = load ptr, ptr %5, align 8
  auto _314 = builder.CreateLoad(builder.getPtrTy(), _239);
  //   %85 = load i32, ptr %7, align 4
  auto _315 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %86 = add nsw i32 %85, 1
  auto _316 = builder.CreateAdd(_315, builder.getIntN(32, 1));
  //   %87 = call i32 @get(i32 noundef %86, i32 noundef 512)
  auto _317 = builder.CreateCall(getFunc, {_316, builder.getIntN(32, 512)});
  //   %88 = sext i32 %87 to i64
  auto _318 = builder.CreateSExt(_317, builder.getIntNTy(64));
  //   %89 = getelementptr inbounds [256 x i8], ptr %84, i64 %88
  auto _319 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _314,
                                {_318});
  //   %90 = load i32, ptr %8, align 4
  auto _320 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %91 = sub nsw i32 %90, 1
  auto _321 = builder.CreateSub(_320, builder.getIntN(32, 1));
  //   %92 = call i32 @get(i32 noundef %91, i32 noundef 256)
  auto _322 = builder.CreateCall(getFunc, {_321, builder.getIntN(32, 256)});
  //   %93 = sext i32 %92 to i64
  auto _323 = builder.CreateSExt(_322, builder.getIntNTy(64));
  //   %94 = getelementptr inbounds [256 x i8], ptr %89, i64 0, i64 %93
  auto _324 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _319,
                                {builder.getIntN(64, 0), _323});
  //   %95 = load i8, ptr %94, align 1
  auto _325 = builder.CreateLoad(builder.getIntNTy(8), _324);
  //   %96 = sext i8 %95 to i32
  auto _326 = builder.CreateSExt(_325, builder.getIntNTy(32));
  //   %97 = add nsw i32 %83, %96
  auto _327 = builder.CreateAdd(_313, _326);
  //   %98 = load ptr, ptr %5, align 8
  auto _328 = builder.CreateLoad(builder.getPtrTy(), _239);
  //   %99 = load i32, ptr %7, align 4
  auto _329 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %100 = add nsw i32 %99, 1
  auto _330 = builder.CreateAdd(_329, builder.getIntN(32, 1));
  //   %101 = call i32 @get(i32 noundef %100, i32 noundef 512)
  auto _331 = builder.CreateCall(getFunc, {_330, builder.getIntN(32, 512)});
  //   %102 = sext i32 %101 to i64
  auto _332 = builder.CreateSExt(_331, builder.getIntNTy(64));
  //   %103 = getelementptr inbounds [256 x i8], ptr %98, i64 %102
  auto _333 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _328,
                                {_332});
  //   %104 = load i32, ptr %8, align 4
  auto _334 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %105 = sext i32 %104 to i64
  auto _335 = builder.CreateSExt(_334, builder.getIntNTy(64));
  //   %106 = getelementptr inbounds [256 x i8], ptr %103, i64 0, i64 %105
  auto _336 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _333,
                                {builder.getIntN(64, 0), _335});
  //   %107 = load i8, ptr %106, align 1
  auto _337 = builder.CreateLoad(builder.getIntNTy(8), _336);
  //   %108 = sext i8 %107 to i32
  auto _338 = builder.CreateSExt(_337, builder.getIntNTy(32));
  //   %109 = add nsw i32 %97, %108
  auto _339 = builder.CreateAdd(_327, _338);
  //   %110 = load ptr, ptr %5, align 8
  auto _340 = builder.CreateLoad(builder.getPtrTy(), _239);
  //   %111 = load i32, ptr %7, align 4
  auto _341 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %112 = add nsw i32 %111, 1
  auto _342 = builder.CreateAdd(_341, builder.getIntN(32, 1));
  //   %113 = call i32 @get(i32 noundef %112, i32 noundef 512)
  auto _343 = builder.CreateCall(getFunc, {_342, builder.getIntN(32, 512)});
  //   %114 = sext i32 %113 to i64
  auto _344 = builder.CreateSExt(_343, builder.getIntNTy(64));
  //   %115 = getelementptr inbounds [256 x i8], ptr %110, i64 %114
  auto _345 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _340,
                                {_344});
  //   %116 = load i32, ptr %8, align 4
  auto _346 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %117 = add nsw i32 %116, 1
  auto _347 = builder.CreateAdd(_346, builder.getIntN(32, 1));
  //   %118 = call i32 @get(i32 noundef %117, i32 noundef 256)
  auto _348 = builder.CreateCall(getFunc, {_347, builder.getIntN(32, 256)});
  //   %119 = sext i32 %118 to i64
  auto _349 = builder.CreateSExt(_348, builder.getIntNTy(64));
  //   %120 = getelementptr inbounds [256 x i8], ptr %115, i64 0, i64 %119
  auto _350 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _345,
                                {builder.getIntN(64, 0), _349});
  //   %121 = load i8, ptr %120, align 1
  auto _351 = builder.CreateLoad(builder.getIntNTy(8), _350);
  //   %122 = sext i8 %121 to i32
  auto _352 = builder.CreateSExt(_351, builder.getIntNTy(32));
  //   %123 = add nsw i32 %109, %122
  auto _353 = builder.CreateAdd(_339, _352);
  //   store i32 %123, ptr %9, align 4
  builder.CreateStore(_353, _243);
  //   %124 = load i32, ptr %9, align 4
  auto _354 = builder.CreateLoad(builder.getIntNTy(32), _243);
  //   %125 = icmp eq i32 %124, 3
  auto _355 =
      builder.CreateICmp(CmpInst::ICMP_EQ, _354, builder.getIntN(32, 3));
  //   br i1 %125, label %140, label %126
  builder.CreateCondBr(_355, _219, _217);

  builder.SetInsertPoint(_217);
  //   %127 = load i32, ptr %9, align 4
  auto _356 = builder.CreateLoad(builder.getIntNTy(32), _243);
  //   %128 = icmp eq i32 %127, 2
  auto _357 =
      builder.CreateICmp(CmpInst::ICMP_EQ, _356, builder.getIntN(32, 2));
  //   br i1 %128, label %129, label %148
  builder.CreateCondBr(_357, _218, _220);

  builder.SetInsertPoint(_218);
  //   %130 = load ptr, ptr %5, align 8
  auto _358 = builder.CreateLoad(builder.getPtrTy(), _239);
  //   %131 = load i32, ptr %7, align 4
  auto _359 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %132 = sext i32 %131 to i64
  auto _360 = builder.CreateSExt(_359, builder.getIntNTy(64));
  //   %133 = getelementptr inbounds [256 x i8], ptr %130, i64 %132
  auto _361 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _358,
                                {_360});
  //   %134 = load i32, ptr %8, align 4
  auto _362 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %135 = sext i32 %134 to i64
  auto _363 = builder.CreateSExt(_362, builder.getIntNTy(64));
  //   %136 = getelementptr inbounds [256 x i8], ptr %133, i64 0, i64 %135
  auto _364 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _361,
                                {builder.getIntN(64, 0), _363});
  //   %137 = load i8, ptr %136, align 1
  auto _365 = builder.CreateLoad(builder.getIntNTy(8), _364);
  //   %138 = sext i8 %137 to i32
  auto _366 = builder.CreateSExt(_365, builder.getIntNTy(32));
  //   %139 = icmp eq i32 %138, 1
  auto _367 =
      builder.CreateICmp(CmpInst::ICMP_EQ, _366, builder.getIntN(32, 1));
  //   br i1 %139, label %140, label %148
  builder.CreateCondBr(_367, _219, _220);

  builder.SetInsertPoint(_219);
  //   %141 = load ptr, ptr %6, align 8
  auto _368 = builder.CreateLoad(builder.getPtrTy(), _240);
  //   %142 = load i32, ptr %7, align 4
  auto _369 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %143 = sext i32 %142 to i64
  auto _370 = builder.CreateSExt(_369, builder.getIntNTy(64));
  //   %144 = getelementptr inbounds [256 x i8], ptr %141, i64 %143
  auto _371 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _368,
                                {_370});
  //   %145 = load i32, ptr %8, align 4
  auto _372 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %146 = sext i32 %145 to i64
  auto _373 = builder.CreateSExt(_372, builder.getIntNTy(64));
  //   %147 = getelementptr inbounds [256 x i8], ptr %144, i64 0, i64 %146
  auto _374 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _371,
                                {builder.getIntN(64, 0), _373});
  //   store i8 1, ptr %147, align 1
  builder.CreateStore(builder.getIntN(8, 1), _374);
  //   br label %156
  builder.CreateBr(_221);

  builder.SetInsertPoint(_220);
  //   %149 = load ptr, ptr %6, align 8
  auto _375 = builder.CreateLoad(builder.getPtrTy(), _240);
  //   %150 = load i32, ptr %7, align 4
  auto _376 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %151 = sext i32 %150 to i64
  auto _377 = builder.CreateSExt(_376, builder.getIntNTy(64));
  //   %152 = getelementptr inbounds [256 x i8], ptr %149, i64 %151
  auto _378 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _375,
                                {_377});
  //   %153 = load i32, ptr %8, align 4
  auto _379 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %154 = sext i32 %153 to i64
  auto _380 = builder.CreateSExt(_379, builder.getIntNTy(64));
  //   %155 = getelementptr inbounds [256 x i8], ptr %152, i64 0, i64 %154
  auto _381 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _378,
                                {builder.getIntN(64, 0), _380});
  //   store i8 0, ptr %155, align 1
  builder.CreateStore(builder.getIntN(8, 0), _381);
  //   br label %156
  builder.CreateBr(_221);

  builder.SetInsertPoint(_221);
  //   br label %157
  builder.CreateBr(_222);

  builder.SetInsertPoint(_222);
  //   %158 = load i32, ptr %8, align 4
  auto _382 = builder.CreateLoad(builder.getIntNTy(32), _242);
  //   %159 = add nsw i32 %158, 1
  auto _383 = builder.CreateAdd(_382, builder.getIntN(32, 1));
  //   store i32 %159, ptr %8, align 4
  builder.CreateStore(_383, _242);
  //   br label %17, !llvm.loop !5
  builder.CreateBr(_215);

  builder.SetInsertPoint(_223);
  //   br label %161
  builder.CreateBr(_224);

  builder.SetInsertPoint(_224);
  //   %162 = load i32, ptr %7, align 4
  auto _384 = builder.CreateLoad(builder.getIntNTy(32), _241);
  //   %163 = add nsw i32 %162, 1
  auto _385 = builder.CreateAdd(_384, builder.getIntN(32, 1));
  //   store i32 %163, ptr %7, align 4
  builder.CreateStore(_385, _241);
  //   br label %13, !llvm.loop !7
  builder.CreateBr(_213);

  builder.SetInsertPoint(_225);
  //   store i32 1, ptr %10, align 4
  builder.CreateStore(builder.getIntN(32, 1), _244);
  //   store i32 0, ptr %11, align 4
  builder.CreateStore(builder.getIntN(32, 0), _245);
  //   br label %165
  builder.CreateBr(_226);

  builder.SetInsertPoint(_226);
  //   %166 = load i32, ptr %11, align 4
  auto _386 = builder.CreateLoad(builder.getIntNTy(32), _245);
  //   %167 = icmp ne i32 %166, 512
  auto _387 =
      builder.CreateICmp(CmpInst::ICMP_NE, _386, builder.getIntN(32, 512));
  //   br i1 %167, label %168, label %223
  builder.CreateCondBr(_387, _227, _235);

  builder.SetInsertPoint(_227);
  //   store i32 0, ptr %12, align 4
  builder.CreateStore(builder.getIntN(32, 0), _246);
  //   br label %169
  builder.CreateBr(_228);

  builder.SetInsertPoint(_228);
  //   %170 = load i32, ptr %12, align 4
  auto _388 = builder.CreateLoad(builder.getIntNTy(32), _246);
  //   %171 = icmp ne i32 %170, 256
  auto _389 =
      builder.CreateICmp(CmpInst::ICMP_NE, _388, builder.getIntN(32, 256));
  //   br i1 %171, label %172, label %219
  builder.CreateCondBr(_389, _229, _233);

  builder.SetInsertPoint(_229);
  //   %173 = load ptr, ptr %5, align 8
  auto _390 = builder.CreateLoad(builder.getPtrTy(), _239);
  //   %174 = load i32, ptr %11, align 4
  auto _391 = builder.CreateLoad(builder.getIntNTy(32), _245);
  //   %175 = sext i32 %174 to i64
  auto _392 = builder.CreateSExt(_391, builder.getIntNTy(64));
  //   %176 = getelementptr inbounds [256 x i8], ptr %173, i64 %175
  auto _393 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _390,
                                {_392});
  //   %177 = load i32, ptr %12, align 4
  auto _394 = builder.CreateLoad(builder.getIntNTy(32), _246);
  //   %178 = sext i32 %177 to i64
  auto _395 = builder.CreateSExt(_394, builder.getIntNTy(64));
  //   %179 = getelementptr inbounds [256 x i8], ptr %176, i64 0, i64 %178
  auto _396 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _393,
                                {builder.getIntN(64, 0), _395});
  //   %180 = load i8, ptr %179, align 1
  auto _397 = builder.CreateLoad(builder.getIntNTy(8), _396);
  //   %181 = sext i8 %180 to i32
  auto _398 = builder.CreateSExt(_397, builder.getIntNTy(32));
  //   %182 = load ptr, ptr %6, align 8
  auto _399 = builder.CreateLoad(builder.getPtrTy(), _240);
  //   %183 = load i32, ptr %11, align 4
  auto _400 = builder.CreateLoad(builder.getIntNTy(32), _245);
  //   %184 = sext i32 %183 to i64
  auto _401 = builder.CreateSExt(_400, builder.getIntNTy(64));
  //   %185 = getelementptr inbounds [256 x i8], ptr %182, i64 %184
  auto _402 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _399,
                                {_401});
  //   %186 = load i32, ptr %12, align 4
  auto _403 = builder.CreateLoad(builder.getIntNTy(32), _246);
  //   %187 = sext i32 %186 to i64
  auto _404 = builder.CreateSExt(_403, builder.getIntNTy(64));
  //   %188 = getelementptr inbounds [256 x i8], ptr %185, i64 0, i64 %187
  auto _405 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _402,
                                {builder.getIntN(64, 0), _404});
  //   %189 = load i8, ptr %188, align 1
  auto _406 = builder.CreateLoad(builder.getIntNTy(8), _405);
  //   %190 = sext i8 %189 to i32
  auto _407 = builder.CreateSExt(_406, builder.getIntNTy(32));
  //   %191 = icmp ne i32 %181, %190
  auto _408 = builder.CreateICmp(CmpInst::ICMP_NE, _398, _407);
  //   br i1 %191, label %192, label %193
  builder.CreateCondBr(_408, _230, _231);

  builder.SetInsertPoint(_230);
  //   store i32 0, ptr %10, align 4
  builder.CreateStore(builder.getIntN(32, 0), _244);
  //   br label %193
  builder.CreateBr(_231);

  builder.SetInsertPoint(_231);
  //   %194 = load ptr, ptr %6, align 8
  auto _409 = builder.CreateLoad(builder.getPtrTy(), _240);
  //   %195 = load i32, ptr %11, align 4
  auto _410 = builder.CreateLoad(builder.getIntNTy(32), _245);
  //   %196 = sext i32 %195 to i64
  auto _411 = builder.CreateSExt(_410, builder.getIntNTy(64));
  //   %197 = getelementptr inbounds [256 x i8], ptr %194, i64 %196
  auto _412 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _409,
                                {_411});
  //   %198 = load i32, ptr %12, align 4
  auto _413 = builder.CreateLoad(builder.getIntNTy(32), _246);
  //   %199 = sext i32 %198 to i64
  auto _414 = builder.CreateSExt(_413, builder.getIntNTy(64));
  //   %200 = getelementptr inbounds [256 x i8], ptr %197, i64 0, i64 %199
  auto _415 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _412,
                                {builder.getIntN(64, 0), _414});
  //   %201 = load i8, ptr %200, align 1
  auto _416 = builder.CreateLoad(builder.getIntNTy(8), _415);
  //   %202 = load ptr, ptr %5, align 8
  auto _417 = builder.CreateLoad(builder.getPtrTy(), _239);
  //   %203 = load i32, ptr %11, align 4
  auto _418 = builder.CreateLoad(builder.getIntNTy(32), _245);
  //   %204 = sext i32 %203 to i64
  auto _419 = builder.CreateSExt(_418, builder.getIntNTy(64));
  //   %205 = getelementptr inbounds [256 x i8], ptr %202, i64 %204
  auto _420 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _417,
                                {_419});
  //   %206 = load i32, ptr %12, align 4
  auto _421 = builder.CreateLoad(builder.getIntNTy(32), _246);
  //   %207 = sext i32 %206 to i64
  auto _422 = builder.CreateSExt(_421, builder.getIntNTy(64));
  //   %208 = getelementptr inbounds [256 x i8], ptr %205, i64 0, i64 %207
  auto _423 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _420,
                                {builder.getIntN(64, 0), _422});
  //   store i8 %201, ptr %208, align 1
  builder.CreateStore(_416, _423);
  //   %209 = load ptr, ptr %6, align 8
  auto _424 = builder.CreateLoad(builder.getPtrTy(), _240);
  //   %210 = load i32, ptr %11, align 4
  auto _425 = builder.CreateLoad(builder.getIntNTy(32), _245);
  //   %211 = sext i32 %210 to i64
  auto _426 = builder.CreateSExt(_425, builder.getIntNTy(64));
  //   %212 = getelementptr inbounds [256 x i8], ptr %209, i64 %211
  auto _427 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _424,
                                {_426});
  //   %213 = load i32, ptr %12, align 4
  auto _428 = builder.CreateLoad(builder.getIntNTy(32), _246);
  //   %214 = sext i32 %213 to i64
  auto _429 = builder.CreateSExt(_428, builder.getIntNTy(64));
  //   %215 = getelementptr inbounds [256 x i8], ptr %212, i64 0, i64 %214
  auto _430 = builder.CreateGEP(ArrayType::get(builder.getIntNTy(8), 256), _427,
                                {builder.getIntN(64, 0), _429});
  //   store i8 0, ptr %215, align 1
  builder.CreateStore(builder.getIntN(8, 0), _430);
  //   br label %216
  builder.CreateBr(_232);

  builder.SetInsertPoint(_232);
  //   %217 = load i32, ptr %12, align 4
  auto _431 = builder.CreateLoad(builder.getIntNTy(32), _246);
  //   %218 = add nsw i32 %217, 1
  auto _432 = builder.CreateAdd(_431, builder.getIntN(32, 1));
  //   store i32 %218, ptr %12, align 4
  builder.CreateStore(_432, _246);
  //   br label %169, !llvm.loop !8
  builder.CreateBr(_228);

  builder.SetInsertPoint(_233);
  //   br label %220
  builder.CreateBr(_234);

  builder.SetInsertPoint(_234);
  //   %221 = load i32, ptr %11, align 4
  auto _433 = builder.CreateLoad(builder.getIntNTy(32), _245);
  //   %222 = add nsw i32 %221, 1
  auto _434 = builder.CreateAdd(_433, builder.getIntN(32, 1));
  //   store i32 %222, ptr %11, align 4
  builder.CreateStore(_434, _245);
  //   br label %165, !llvm.loop !9
  builder.CreateBr(_226);

  builder.SetInsertPoint(_235);
  //   %224 = load i32, ptr %10, align 4
  auto _435 = builder.CreateLoad(builder.getIntNTy(32), _244);
  //   %225 = icmp eq i32 %224, 1
  auto _436 =
      builder.CreateICmp(CmpInst::ICMP_EQ, _435, builder.getIntN(32, 1));
  //   br i1 %225, label %226, label %227
  builder.CreateCondBr(_436, _236, _237);

  builder.SetInsertPoint(_236);
  //   store ptr null, ptr %4, align 8
  builder.CreateStore(ConstantPointerNull::get(builder.getPtrTy()), _238);
  //   br label %227
  builder.CreateBr(_237);

  builder.SetInsertPoint(_237);
  //   ret void
  builder.CreateRetVoid();

  // app
  builder.SetInsertPoint(_437);
  //   %1 = alloca i32, align 4
  auto _441 = builder.CreateAlloca(builder.getIntNTy(32));
  //   %2 = alloca [512 x [256 x i8]], align 16
  auto _442 = builder.CreateAlloca(
      ArrayType::get(ArrayType::get(builder.getIntNTy(8), 256), 512));
  //   %3 = alloca [512 x [256 x i8]], align 16
  auto _443 = builder.CreateAlloca(
      ArrayType::get(ArrayType::get(builder.getIntNTy(8), 256), 512));
  //   store i32 1, ptr %1, align 4
  builder.CreateStore(builder.getIntN(32, 1), _441);
  //   %4 = getelementptr inbounds [512 x [256 x i8]], ptr %2, i64 0, i64 0
  auto _444 = builder.CreateGEP(
      ArrayType::get(ArrayType::get(builder.getIntNTy(8), 256), 512), _442,
      {builder.getIntN(64, 0), builder.getIntN(64, 0)});
  //   call void @init(ptr noundef %4)
  auto _445 = builder.CreateCall(initFunc, {_444});
  //   %5 = getelementptr inbounds [512 x [256 x i8]], ptr %3, i64 0, i64 0
  auto _446 = builder.CreateGEP(
      ArrayType::get(ArrayType::get(builder.getIntNTy(8), 256), 512), _443,
      {builder.getIntN(64, 0), builder.getIntN(64, 0)});
  //   call void @clear(ptr noundef %5)
  auto _447 = builder.CreateCall(clearFunc, {_446});
  //   br label %6
  builder.CreateBr(_438);

  builder.SetInsertPoint(_438);
  //   %7 = load i32, ptr %1, align 4
  auto _448 = builder.CreateLoad(builder.getIntNTy(32), _441);
  //   %8 = icmp ne i32 %7, 0
  auto _449 =
      builder.CreateICmp(CmpInst::ICMP_NE, _448, builder.getIntN(32, 0));
  //   br i1 %8, label %9, label %13
  builder.CreateCondBr(_449, _439, _440);

  builder.SetInsertPoint(_439);
  //   %10 = getelementptr inbounds [512 x [256 x i8]], ptr %2, i64 0, i64 0
  auto _450 = builder.CreateGEP(
      ArrayType::get(ArrayType::get(builder.getIntNTy(8), 256), 512), _442,
      {builder.getIntN(64, 0), builder.getIntN(64, 0)});
  //   call void @dump(ptr noundef %10)
  auto _451 = builder.CreateCall(dumpFunc, {_450});
  //   %11 = getelementptr inbounds [512 x [256 x i8]], ptr %2, i64 0, i64 0
  auto _452 = builder.CreateGEP(
      ArrayType::get(ArrayType::get(builder.getIntNTy(8), 256), 512), _442,
      {builder.getIntN(64, 0), builder.getIntN(64, 0)});
  //   %12 = getelementptr inbounds [512 x [256 x i8]], ptr %3, i64 0, i64 0
  auto _453 = builder.CreateGEP(
      ArrayType::get(ArrayType::get(builder.getIntNTy(8), 256), 512), _443,
      {builder.getIntN(64, 0), builder.getIntN(64, 0)});
  //   call void @next_generation(ptr noundef %1, ptr noundef %11, ptr noundef
  //   %12)
  auto _454 = builder.CreateCall(next_generationFunc, {_441, _452, _453});
  //   br label %6, !llvm.loop !5
  builder.CreateBr(_438);

  builder.SetInsertPoint(_440);
  //   ret void
  builder.CreateRetVoid();

  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();

  auto execEngine = EngineBuilder(std::move(module)).create();

  execEngine->InstallLazyFunctionCreator([](const std::string& fnName) -> void* {
    if (fnName == "simPutPixel") {
      return reinterpret_cast<void*>(simPutPixel);
    }
    if (fnName == "simFlush") {
      return reinterpret_cast<void*>(simFlush);
    }
    return nullptr;
  });

  execEngine->finalizeObject();
  simInit();
  execEngine->runFunction(appFunc, {});
  simExit();

  delete execEngine;
}
