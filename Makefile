CC=gcc
CFLAGS=-Wall --pedantic -g -lm
BIN=./bin
SRC=./src

build:
	$(CC) ./$(SRC)/1.c -o 1 $(CFLAGS)
	$(CC) ./$(SRC)/2.c -o 2 $(CFLAGS)
	$(CC) ./$(SRC)/3.c -o 3 $(CFLAGS)
	$(CC) ./$(SRC)/4.c -o 4 $(CFLAGS)

test:
	./1
	./2
	./3
	./4
