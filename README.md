# llvm-course

compile pass: clang++ pass_dump.cpp -fPIC -shared -lLLVM-17 -L/usr/local/Cellar/llvm/17.0.6/lib -I$(llvm-config --includedir) -o libPass.so

compile app: clang start.c sim.c app.c -lSDL2 -I/usr/local/opt/sdl2/include -L/usr/local/opt/sdl2/lib

compile app with pass: clang start.c sim.c app.c log.c -lSDL2 -I/usr/local/opt/sdl2/include -L/usr/local/opt/sdl2/lib -fpass-plugin=../LLVM_PASS/libPass.so
