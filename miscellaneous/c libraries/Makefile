CC := gcc

CFLAGS := -Wall -Wextra -Wpedantic -g

all: build/hello

build/libhello.so.1.0.1: build/libhello.o
	mkdir -p build/
	gcc -shared -Wl,-soname,libhello.so.1 -o build/libhello.so.1.0.1 build/libhello.o
	ln -sf build/libhello.so.1.0.1 build/libhello.so
#	ar rv build/libhello.a build/libhello.o
#	ranlib build/libhello.a

build/libhello.o: libhello.c
	mkdir -p build/
	${CC} ${CFLAGS} -c libhello.c -o $@

build/hello: main.c build/libhello.so.1.0.1 libhello.h
	mkdir -p build/
	${CC} ${CFLAGS} main.c -L build/ -o $@ -lhello

clean:
	rm -rf build/

.PHONY: all clean
