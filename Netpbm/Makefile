all: libnetpbm

export cpp_flags := -Wall -pedantic -g -fsanitize=address -fPIC

libnetpbm: ${obj_dir}/netpbm.o ${obj_dir}/bitmap.o ${obj_dir}/graymap.o ${obj_dir}/pixmap.o
	ar rcs ${release_dir}/libnetpbm.a ${obj_dir}/netpbm.o ${obj_dir}/bitmap.o ${obj_dir}/graymap.o ${obj_dir}/pixmap.o
	g++ ${cpp_flags} -shared -o ${release_dir}/libnetpbm.so ${obj_dir}/netpbm.o ${obj_dir}/bitmap.o ${obj_dir}/graymap.o ${obj_dir}/pixmap.o

${obj_dir}/netpbm.o: src/netpbm.cpp
	g++ ${cpp_flags} -c src/netpbm.cpp -o ${obj_dir}/netpbm.o

${obj_dir}/bitmap.o: src/bitmap.cpp
	g++ ${cpp_flags} -c src/bitmap.cpp -o ${obj_dir}/bitmap.o

${obj_dir}/graymap.o: src/graymap.cpp
	g++ ${cpp_flags} -c src/graymap.cpp -o ${obj_dir}/graymap.o

${obj_dir}/pixmap.o: src/pixmap.cpp
	g++ ${cpp_flags} -c src/pixmap.cpp -o ${obj_dir}/pixmap.o
