all: libpng

export cpp_flags := -Wall -pedantic -fPIC -std=c++11

libpng: ${obj_dir}/libpng.o
	ar rcs ${release_dir}/libpng.a ${obj_dir}/libpng.o
	g++ ${cpp_flags} -shared -o ${release_dir}/libpng.so ${obj_dir}/libpng.o

${obj_dir}/libpng.o: src/png.cpp
	g++ ${cpp_flags} -c src/png.cpp -o ${obj_dir}/libpng.o
