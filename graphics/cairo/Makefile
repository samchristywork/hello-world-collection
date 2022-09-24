CC := gcc

CFLAGS := $(shell pkg-config --cflags cairo)
LIBS := $(shell pkg-config --libs cairo)

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} ${CFLAGS} hello.c -o $@ ${LIBS}

clean:
	rm -rf build/

.PHONY: clean
