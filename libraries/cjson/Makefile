CC := gcc

CFLAGS := $(shell pkg-config --cflags libcjson)
LIBS := $(shell pkg-config --libs libcjson)

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} hello.c ${CFLAGS} -o $@ ${LIBS}

clean:
	rm -rf build/

.PHONY: clean
