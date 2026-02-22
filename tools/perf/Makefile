CC := gcc
CFLAGS := -Wall -Wextra -O2

SRC := hello.c
OBJ := $(SRC:.c=.o)
TARGET := build/hello

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build/
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

stat: $(TARGET)
	perf stat ./$(TARGET)

clean:
	rm -rf build/ $(OBJ)

.PHONY: all stat clean
