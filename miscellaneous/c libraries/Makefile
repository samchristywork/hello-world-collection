CC := gcc

CFLAGS := -Wall -Wextra -Wpedantic -g

all: build/hello

build/libhello.so: build/libhello.o
	mkdir -p build/
	gcc -shared -Wl,-soname,libhello.so -o build/libhello.so build/libhello.o
#	ar rv build/libhello.a build/libhello.o
#	ranlib build/libhello.a

build/libhello.o: libhello.c
	mkdir -p build/
	${CC} ${CFLAGS} -c libhello.c -o $@

build/hello: main.c build/libhello.so libhello.h
	mkdir -p build/
	${CC} ${CFLAGS} main.c -L build/ -o $@ -lhello

run: all
	LD_LIBRARY_PATH=./build:${LD_LIBRARY_PATH} ./build/hello

clean:
	rm -rf build/

.PHONY: all clean run
