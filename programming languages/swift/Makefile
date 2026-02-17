CC := swiftc

all: build/hello

build/hello: hello.swift
	mkdir -p build/
	${CC} hello.swift -o $@

clean:
	rm -rf build/

.PHONY: all clean
