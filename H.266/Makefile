all: libh266

libh266: ${obj_dir}/libh266.o
	g++ -Wall -shared -o ${release_dir}/libh266.so ${obj_dir}/libh266.o -Wl,--out-implib,${release_dir}/libh266.a

${obj_dir}/libh266.o: src/h266.cpp
	g++ -Wall -fPIC -c src/h266.cpp -o ${obj_dir}/libh266.o
