CC := gcc

all: build/hello

build/hello: build/hello.o
	${CC} -o $@ $^

build/hello.o: build/hello.c
	${CC} -c -o $@ $^

build/hello.c: hello.y
	mkdir -p build/
	bison -d -o $@ hello.y

test: build/hello
	echo "Hello, World!" | ./build/hello

clean:
	rm -rf build/
