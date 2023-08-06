all: libavi

export cpp_flags := -Wall -pedantic -fPIC -std=c++11

libavi: ${obj_dir}/libavi.o
	ar rcs ${release_dir}/libavi.a ${obj_dir}/libavi.o
	g++ ${cpp_flags} -shared -o ${release_dir}/libavi.so ${obj_dir}/libavi.o ${ld_flags}

${obj_dir}/libavi.o: src/avi.cpp
	g++ ${cpp_flags} -c src/avi.cpp -o ${obj_dir}/libavi.o
