CC := gcc
CFLAGS := -Wall -Wextra -g -fsanitize=address

SRC := hello.c
OBJ := $(SRC:.c=.o)
TARGET := build/hello

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build/
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/ $(OBJ)

.PHONY: all clean
