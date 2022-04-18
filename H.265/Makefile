all: libh265

libh265: ${obj_dir}/libh265.o
	g++ -Wall -shared -o ${release_dir}/libh265.so ${obj_dir}/libh265.o -Wl,--out-implib,${release_dir}/libh265.a

${obj_dir}/libh265.o: src/h265.cpp
	g++ -Wall -fPIC -c src/h265.cpp -o ${obj_dir}/libh265.o
