CC := gcc

CFLAGS := -I raylib/build/raylib/include
LIBS := -L raylib/build/raylib/ -lraylib -lGL -lm -lpthread -ldl

all: build/hello

build/hello: hello.c
	mkdir -p build/
	${CC} ${CFLAGS} hello.c -o $@ ${LIBS}

clone:
	git clone https://github.com/raysan5/raylib.git
	mkdir raylib/build
	cd raylib/build && cmake ..
	cd raylib/build && make -j8

clean:
	rm -rf build/

.PHONY: clean clone
