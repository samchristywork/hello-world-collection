CC := gcc
CFLAGS := -Wall -Wextra -g

SRC := hello.c
OBJ := $(SRC:.c=.o)
TARGET := build/hello

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build/
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

symbols: $(TARGET)
	nm $(TARGET)

clean:
	rm -rf build/ $(OBJ)

.PHONY: all symbols clean
