all: libwav

export cpp_flags := -Wall -pedantic -fPIC -std=c++11

libwav: ${obj_dir}/libwav.o
	ar rcs ${release_dir}/libwav.a ${obj_dir}/libwav.o
	g++ ${cpp_flags} -shared -o ${release_dir}/libwav.so ${obj_dir}/libwav.o ${ld_flags}

${obj_dir}/libwav.o: src/wav.cpp
	g++ ${cpp_flags} -c src/wav.cpp -o ${obj_dir}/libwav.o
