CC := gcc
CFLAGS := -Wall -Wextra -pg -g

SRC := hello.c
OBJ := $(SRC:.c=.o)
TARGET := build/hello

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build/
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

profile: $(TARGET)
	./$(TARGET)
	gprof $(TARGET) gmon.out

clean:
	rm -rf build/ $(OBJ) gmon.out

.PHONY: all profile clean
