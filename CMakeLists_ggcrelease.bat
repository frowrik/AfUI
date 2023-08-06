rmdir /s /q project2
mkdir project2
cd project2
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_MAKE_PROGRAM=mingw32-make.exe .. -G "MinGW Makefiles"
pause