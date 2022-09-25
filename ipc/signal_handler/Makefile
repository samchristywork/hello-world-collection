CC := gcc

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} hello.c -o $@ -lrt

clean:
	rm -rf build/

.PHONY: clean
