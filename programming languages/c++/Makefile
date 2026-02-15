CC := g++

CFLAGS := -Wall -Wextra -g

all: build/hello

build/hello: hello.cpp
	mkdir -p build/
	${CC} ${CFLAGS} hello.cpp -o $@

clean:
	rm -rf build/

.PHONY: all clean
