all: libpng

libpng: ${obj_dir}/libpng.o
	g++ -Wall -shared -o ${release_dir}/libpng.so ${obj_dir}/libpng.o -Wl,--out-implib,${release_dir}/libpng.a

${obj_dir}/libpng.o: src/png.cpp
	g++ -Wall -fPIC -c src/png.cpp -o ${obj_dir}/libpng.o
