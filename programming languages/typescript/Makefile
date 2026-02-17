all: build/hello.js

build/hello.js: hello.ts
	mkdir -p build/
	tsc --outDir build/ hello.ts

run: all
	node build/hello.js

clean:
	rm -rf build/

.PHONY: all clean run
