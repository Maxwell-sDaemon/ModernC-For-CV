echo "ipb arithmetic is building"
mkdir build
clang++ -I include -c src/sum.cpp -o build/sum.o
clang++ -I include -c  src/subtract.cpp -o build/subtract.o
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o
clang++ -std=c++17 src/main.cpp -I include -L build  -lipb_arithmetic -o build/test_ipb_arithmetic
