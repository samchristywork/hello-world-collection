CC := gcc
LIBS := -lcrypto

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} ${CFLAGS} $^ -o $@ ${LIBS}

clean:
	rm -rf build/
