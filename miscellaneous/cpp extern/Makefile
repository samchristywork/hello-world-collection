CFLAGS := -Wall -Wextra -Wpedantic -g

all: build/hello

build/libhello.so: build/libhello.o
	mkdir -p build/
	gcc -shared -Wl,-soname,libhello.so -o build/libhello.so build/libhello.o

build/libhello.o: libhello.cpp
	mkdir -p build/
	g++ ${CFLAGS} -c libhello.cpp -o $@

build/hello: main.c build/libhello.so libhello.h
	mkdir -p build/
	gcc ${CFLAGS} main.c -L build/ -o $@ -lhello

run: all
	LD_LIBRARY_PATH=./build:${LD_LIBRARY_PATH} ./build/hello

clean:
	rm -rf build/

.PHONY: all clean run
