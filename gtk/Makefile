CC := gcc

CFLAGS := $(shell pkg-config --cflags gtk+-3.0)
LIBS := $(shell pkg-config --libs gtk+-3.0)

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} ${CFLAGS} hello.c -o $@ ${LIBS}

clean:
	rm -rf build/
