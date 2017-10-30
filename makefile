CC=gcc -fopenmp -g
CFLAGS=-I.
BUILD_DIR = build

.PHONY: all
all: main

.PHONY: main
main: main.c
	test -d "$(BUILD_DIR)" || mkdir $(BUILD_DIR)
	$(CC) main.c -o $(BUILD_DIR)/main

setup:
	make -C ./exemplos/
	make all

clean:
	rm -r build