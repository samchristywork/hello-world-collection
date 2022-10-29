CC := gcc

CFLAGS := -Wall -Wextra -Wpedantic -g

all: build/hello build/mymalloc.so

build/hello: hello.c
	mkdir -p build/
	gcc hello.c -o $@

build/mymalloc.so: mymalloc.c
	mkdir -p build/
	gcc mymalloc.c -fPIC -shared -o $@

run: all
	LD_PRELOAD=./build/mymalloc.so build/hello

clean:
	rm -rf build/

.PHONY: all clean run
