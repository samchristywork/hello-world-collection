all: build/hello.png

build/hello.png: hello.gnuplot
	mkdir -p build/
	gnuplot hello.gnuplot

clean:
	rm -rf build/

.PHONY: all clean
