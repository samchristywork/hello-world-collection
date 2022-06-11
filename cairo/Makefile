CC := gcc

LIBS := $(shell pkg-config --libs cairo)
CFLAGS := $(shell pkg-config --cflags cairo)

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} ${CFLAGS} hello.c -o $@ ${LIBS}

clean:
	rm -rf build/

