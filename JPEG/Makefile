all: libjpeg

libjpeg: ${obj_dir}/libjpeg.o
	g++ -Wall -shared -o ${release_dir}/libjpeg.so ${obj_dir}/libjpeg.o -Wl,--out-implib,${release_dir}/libjpeg.a

${obj_dir}/libjpeg.o: src/jpeg.cpp
	g++ -Wall -fPIC -c src/jpeg.cpp -o ${obj_dir}/libjpeg.o
