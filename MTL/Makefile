all: libmtl

libmtl: ${obj_dir}/libmtl.o
	g++ -shared -o ${release_dir}/libmtl.so ${obj_dir}/libmtl.o -Wl,--out-implib,${release_dir}/libmtl.a

${obj_dir}/libmtl.o: src/mtl.cpp
	g++ -fPIC -c src/mtl.cpp -o ${obj_dir}/libmtl.o
