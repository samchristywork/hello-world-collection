CC := gcc

CFLAGS := -Wall -Wextra -Wpedantic -g

all: build/hello build/mywrite.so

build/hello: hello.c
	mkdir -p build/
	gcc hello.c -o $@

build/mywrite.so: mywrite.c
	mkdir -p build/
	gcc mywrite.c -fPIC -shared -o $@

run: all
	LD_PRELOAD=./build/mywrite.so build/hello

clean:
	rm -rf build/

.PHONY: all clean run
