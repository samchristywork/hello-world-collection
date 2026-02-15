all: build/hello.wasm

build/hello.wasm: hello.wat
	mkdir -p build/
	wat2wasm hello.wat -o $@

run: all
	wasmtime build/hello.wasm

clean:
	rm -rf build/

.PHONY: all clean run
