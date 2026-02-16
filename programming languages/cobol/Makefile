CC := gcobol

all: build/hello

build/hello: hello.cob
	mkdir -p build/
	${CC} hello.cob -o $@

clean:
	rm -rf build/

.PHONY: all clean
