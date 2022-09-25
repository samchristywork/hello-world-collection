CC := gcc

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} -g -o $@ $^

valgrind: build/hello
	valgrind ./build/hello

clean:
	rm -rf build/

.PHONY: clean
