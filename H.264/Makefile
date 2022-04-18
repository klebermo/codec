all: libh264

libh264: ${obj_dir}/libh264.o
	g++ -Wall -shared -o ${release_dir}/libh264.so ${obj_dir}/libh264.o -Wl,--out-implib,${release_dir}/libh264.a

${obj_dir}/libh264.o: src/h264.cpp
	g++ -Wall -fPIC -c src/h264.cpp -o ${obj_dir}/libh264.o
