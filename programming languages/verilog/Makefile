CC := iverilog

all: build/hello

build/hello: hello.v
	mkdir -p build/
	${CC} hello.v -o $@

clean:
	rm -rf build/
