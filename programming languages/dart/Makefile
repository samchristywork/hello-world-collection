all: build/hello

build/hello: hello.dart
	mkdir -p build/
	dart compile exe hello.dart -o $@

run: all
	build/hello

clean:
	rm -rf build/

.PHONY: all clean run
