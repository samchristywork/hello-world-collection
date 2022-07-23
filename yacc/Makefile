CC := gcc

all: build/hello

build/hello: build/hello.o
	${CC} -o $@ $^

build/hello.o: build/hello.c
	${CC} -c -o $@ $^

build/hello.c: hello.y
	mkdir -p build/
	bison -d -o $@ hello.y

clean:
	rm -rf build/
