TARGET := build/hello

all: $(TARGET)

$(TARGET): hello.l
	mkdir -p build/
	flex -o build/lex.yy.c hello.l
	gcc -Wall -Wextra -o $(TARGET) build/lex.yy.c -lfl

clean:
	rm -rf build/

.PHONY: all clean
