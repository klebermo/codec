all: libmidi

export cpp_flags := -Wall -pedantic -fPIC -std=c++11

libmidi: ${obj_dir}/libmidi.o
	ar rcs ${release_dir}/libmidi.a ${obj_dir}/libmidi.o
	g++ ${cpp_flags} -shared -o ${release_dir}/libmidi.so ${obj_dir}/libmidi.o ${ld_flags}

${obj_dir}/libmidi.o: src/midi.cpp
	g++ ${cpp_flags} -c src/midi.cpp -o ${obj_dir}/libmidi.o
