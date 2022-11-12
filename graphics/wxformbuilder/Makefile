CC := g++

CFLAGS := $(shell wx-config --cxxflags)
LIBS := $(shell wx-config --libs)

all: build/hello

build/noname.o: generated_code/noname.cpp
	mkdir -p build/
	${CC} ${CFLAGS} -c generated_code/noname.cpp -o $@ ${LIBS}

build/hello: hello.cpp build/noname.o
	mkdir -p build/
	${CC} ${CFLAGS} hello.cpp build/noname.o -o $@ ${LIBS}

clean:
	rm -rf build/

.PHONY: clean
