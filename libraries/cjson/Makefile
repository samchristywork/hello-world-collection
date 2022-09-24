CC := gcc

LIBS := -lcjson

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} hello.c -o $@ ${LIBS}

clean:
	rm -rf build/

.PHONY: clean
