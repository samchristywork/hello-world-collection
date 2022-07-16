CC := gcc

all: build/server build/client

build/server: server.c
	mkdir -p build/
	${CC} server.c -o $@ -lrt

build/client: client.c
	mkdir -p build/
	${CC} client.c -o $@ -lrt

clean:
	rm -rf build/
