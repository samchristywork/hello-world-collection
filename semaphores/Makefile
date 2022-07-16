CC := gcc

all: build/server build/client

build/server: server.c
	mkdir -p build/
	${CC} server.c -o $@ -lrt -lpthread

build/client: client.c
	mkdir -p build/
	${CC} client.c -o $@ -lrt -lpthread

clean:
	rm -rf build/
