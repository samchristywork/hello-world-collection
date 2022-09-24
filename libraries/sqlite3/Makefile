CC := gcc
CFLAGS := $(shell pkg-config --cflags sqlite3)
LIBS := $(shell pkg-config --libs sqlite3)

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
	rm -rf build/
