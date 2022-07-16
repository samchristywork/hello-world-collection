CC := gcc
CFLAGS := -I build/argon2/include/
LIBS := build/argon2/libargon2.a -lpthread

all: build/main

build/main: main.c
	mkdir -p build/
	[ -d build/argon2 ] || git clone https://github.com/P-H-C/phc-winner-argon2 build/argon2
	(cd build/argon2 && make -j`nproc`)
	${CC} ${CFLAGS} main.c -o $@ ${LIBS}

clean:
	rm -rf build/
