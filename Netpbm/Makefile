all: libnetpbm

libnetpbm: ${obj_dir}/netpbm.o ${obj_dir}/bitmap.o ${obj_dir}/graymap.o ${obj_dir}/pixmap.o
	ar rcs ${release_dir}/libnetpbm.a ${obj_dir}/netpbm.o ${obj_dir}/bitmap.o ${obj_dir}/graymap.o ${obj_dir}/pixmap.o
	g++ -Wall -pedantic -g -shared -o ${release_dir}/libnetpbm.so ${obj_dir}/netpbm.o ${obj_dir}/bitmap.o ${obj_dir}/graymap.o ${obj_dir}/pixmap.o

${obj_dir}/netpbm.o: src/netpbm.cpp
	g++ -Wall -pedantic -g -fPIC -c src/netpbm.cpp -o ${obj_dir}/netpbm.o

${obj_dir}/bitmap.o: src/bitmap.cpp
	g++ -Wall -pedantic -g -fPIC -c src/bitmap.cpp -o ${obj_dir}/bitmap.o

${obj_dir}/graymap.o: src/graymap.cpp
	g++ -Wall -pedantic -g -fPIC -c src/graymap.cpp -o ${obj_dir}/graymap.o

${obj_dir}/pixmap.o: src/pixmap.cpp
	g++ -Wall -pedantic -g -fPIC -c src/pixmap.cpp -o ${obj_dir}/pixmap.o
