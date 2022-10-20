CC := g++

CPPFLAGS := -Wall -Wpedantic -lboost_regex
LIBS := /usr/lib/x86_64-linux-gnu/libboost_regex.a

all: build/hello

build/hello: hello.cpp
	mkdir -p build/
	${CC} ${CPPFLAGS} $^ -o $@ ${LIBS}

clean:
	rm -rf build/

.PHONY: clean
