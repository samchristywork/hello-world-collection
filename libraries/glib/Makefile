CC := gcc

CFLAGS := $(shell pkg-config --cflags glib-2.0)
LIBS := $(shell pkg-config --libs glib-2.0)

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} hello.c ${CFLAGS} -o $@ ${LIBS}

clean:
	rm -rf build/

.PHONY: clean
