
all:
	mkdir -p build/
	g++ main.cpp `pkg-config --libs --cflags gtk+-3.0` -lepoxy -o build/main

clean:
	rm -rf build/
