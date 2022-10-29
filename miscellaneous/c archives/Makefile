CC := gcc

CFLAGS := -Wall -Wextra -Wpedantic -g

all: build/hello

build/libhello.a: build/libhello.o
	ar rv build/libhello.a build/libhello.o
	ranlib build/libhello.a

build/libhello.o: libhello.c
	mkdir -p build/
	${CC} ${CFLAGS} -c libhello.c -o $@

build/hello: main.c build/libhello.a libhello.h
	mkdir -p build/
	${CC} ${CFLAGS} main.c -L build/ -lhello -o $@

clean:
	rm -rf build/

.PHONY: all clean
