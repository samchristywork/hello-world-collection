all: build/hello.svg

build/hello.svg: hello.dot
	mkdir -p build/
	dot -Tsvg < hello.dot > $@

clean:
	rm -rf build/
