CC := valac

LIBS := --pkg gtk+-3.0

all: build/hello

build/hello: hello.vala
	mkdir -p build/
	${CC} ${LIBS} hello.vala -o $@

clean:
	rm -rf build/

.PHONY: clean
