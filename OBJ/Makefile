all: libobj

libobj: ${obj_dir}/libobj.o
	g++ -shared -o ${release_dir}/libobj.so ${obj_dir}/libobj.o -Wl,--out-implib,${release_dir}/libobj.a

${obj_dir}/libobj.o: src/obj.cpp
	g++ -fPIC -c src/obj.cpp -o ${obj_dir}/libobj.o
