all: build/hello.pdf

build/hello.pdf: hello.tex
	mkdir -p build/
	xelatex -output-directory build/ -halt-on-error hello.tex

clean:
	rm -rf build/

.PHONY: clean
