CC := gcc

CFLAGS := -I/usr/include/lua5.3
LIBS := -llua5.3

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} ${CFLAGS} hello.c -o $@ ${LIBS}

clean:
	rm -rf build/

.PHONY: clean
