CC := gcc

LIBS := -lncurses
CFLAGS := -g -Wall -Wpedantic

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} ${CFLAGS} hello.c -o $@ ${LIBS}

clean:
	rm -rf build/

.PHONY: clean
