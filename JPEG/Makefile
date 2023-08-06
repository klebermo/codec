all: libjpeg

export cpp_flags := -Wall -pedantic -fPIC -std=c++11

libjpeg: ${obj_dir}/libjpeg.o
	ar rcs ${release_dir}/libjpeg.a ${obj_dir}/libjpeg.o
	g++ ${cpp_flags} -shared -o ${release_dir}/libjpeg.so ${obj_dir}/libjpeg.o ${ld_flags}

${obj_dir}/libjpeg.o: src/jpeg.cpp
	g++ ${cpp_flags} -c src/jpeg.cpp -o ${obj_dir}/libjpeg.o
