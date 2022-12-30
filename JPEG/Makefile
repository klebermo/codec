all: libjpeg

export cpp_flags := -Wall -pedantic -g -fsanitize=address -fPIC
export ld_flags := -lm

libjpeg: ${obj_dir}/jpeg_segments.o ${obj_dir}/jfif.o ${obj_dir}/exif.o ${obj_dir}/libjpeg.o
	ar rcs ${release_dir}/libjpeg.a ${obj_dir}/jpeg_segments.o ${obj_dir}/jfif.o ${obj_dir}/exif.o ${obj_dir}/libjpeg.o
	g++ ${cpp_flags} -shared -o ${release_dir}/libjpeg.so  ${obj_dir}/jpeg_segments.o ${obj_dir}/jfif.o ${obj_dir}/exif.o ${obj_dir}/libjpeg.o ${ld_flags}

${obj_dir}/jpeg_segments.o: src/jpeg_segments.cpp
	g++ ${cpp_flags} -c src/jpeg_segments.cpp -o ${obj_dir}/jpeg_segments.o

${obj_dir}/jfif.o: src/jfif.cpp
	g++ ${cpp_flags} -c src/jfif.cpp -o ${obj_dir}/jfif.o

${obj_dir}/exif.o: src/exif.cpp
	g++ ${cpp_flags} -c src/exif.cpp -o ${obj_dir}/exif.o

${obj_dir}/libjpeg.o: src/jpeg.cpp
	g++ ${cpp_flags} -c src/jpeg.cpp -o ${obj_dir}/libjpeg.o
