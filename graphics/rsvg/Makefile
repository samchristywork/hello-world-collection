all: build/hello.png

build/hello.png: hello.svg
	mkdir -p build/
	rsvg-convert hello.svg -o $@

clean:
	rm -rf build/

.PHONY: all clean
