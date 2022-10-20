CC := g++

CFLAGS := $(shell wx-config --cxxflags)
LIBS := $(shell wx-config --libs)

all: build/hello

build/hello: hello.cpp
	mkdir -p build/
	${CC} ${CFLAGS} hello.cpp -o $@ ${LIBS}

clean:
	rm -rf build/

.PHONY: clean
