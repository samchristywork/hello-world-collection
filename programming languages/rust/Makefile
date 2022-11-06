CC := rustc

all: build/hello

build/hello: hello.rs
	mkdir -p build/
	${CC} hello.rs -o $@

clean:
	rm -rf build/

.PHONY: clean
