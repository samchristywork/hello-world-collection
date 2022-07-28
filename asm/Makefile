all: build/hello

build/hello: hello.s
	mkdir -p build/
	nasm -f elf64 hello.s -o $@.o
	ld -o $@ $@.o

clean:
	rm -rf build/

.PHONY: clean
