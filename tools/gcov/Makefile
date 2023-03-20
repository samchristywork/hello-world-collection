CC := gcc
LIBS :=
CFLAGS :=

all: build/main

build/foo.o: src/foo.*
	mkdir -p build/
	${CC} ${CFLAGS} -c src/foo.c -o $@

build/main: src/main.c build/foo.o
	mkdir -p build/
	${CC} ${CFLAGS} build/foo.o ./src/main.c ${LIBS} -o $@

.PHONY: coverage
coverage: CFLAGS+=-fprofile-arcs -ftest-coverage -g
coverage: LIBS+=-lgcov --coverage
coverage: all

clean:
	rm -rf build/

.PHONY: all clean
