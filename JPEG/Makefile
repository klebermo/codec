all: libjpeg

export cpp_flags := -Wall -pedantic -g -fsanitize=address -fPIC

libjpeg: ${obj_dir}/libjpeg.o
	ar rcs ${release_dir}/libjpeg.a ${obj_dir}/libjpeg.o
	g++ ${cpp_flags} -shared -o ${release_dir}/libjpeg.so ${obj_dir}/libjpeg.o -Wl,--out-implib,${release_dir}/libjpeg.a

${obj_dir}/libjpeg.o: src/jpeg.cpp
	g++ ${cpp_flags} -c src/jpeg.cpp -o ${obj_dir}/libjpeg.o
