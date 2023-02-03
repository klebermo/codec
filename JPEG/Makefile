all: libjpeg

export common_dir := ../common
export cpp_flags := -Wall -pedantic -g -fsanitize=address -fPIC
export ld_flags := -lm

libjpeg: ${obj_dir}/huffman.o ${obj_dir}/matrix.o ${obj_dir}/pixel.o ${obj_dir}/jfif.o ${obj_dir}/exif.o ${obj_dir}/libjpeg.o
	ar rcs ${release_dir}/libjpeg.a ${obj_dir}/huffman.o ${obj_dir}/matrix.o ${obj_dir}/pixel.o ${obj_dir}/jfif.o ${obj_dir}/exif.o ${obj_dir}/libjpeg.o
	g++ ${cpp_flags} -shared -o ${release_dir}/libjpeg.so  ${obj_dir}/huffman.o ${obj_dir}/matrix.o ${obj_dir}/pixel.o ${obj_dir}/jfif.o ${obj_dir}/exif.o ${obj_dir}/libjpeg.o ${ld_flags}

${obj_dir}/huffman.o: ${common_dir}/huffman.cpp
	g++ ${cpp_flags} -c ${common_dir}/huffman.cpp -o ${obj_dir}/huffman.o

${obj_dir}/matrix.o: ${common_dir}/matrix.cpp
	g++ ${cpp_flags} -c ${common_dir}/matrix.cpp -o ${obj_dir}/matrix.o

${obj_dir}/pixel.o: ${common_dir}/pixel.cpp
	g++ ${cpp_flags} -c ${common_dir}/pixel.cpp -o ${obj_dir}/pixel.o

${obj_dir}/jfif.o: src/jfif.cpp
	g++ ${cpp_flags} -c src/jfif.cpp -o ${obj_dir}/jfif.o

${obj_dir}/exif.o: src/exif.cpp
	g++ ${cpp_flags} -c src/exif.cpp -o ${obj_dir}/exif.o

${obj_dir}/libjpeg.o: src/jpeg.cpp
	g++ ${cpp_flags} -c src/jpeg.cpp -o ${obj_dir}/libjpeg.o
