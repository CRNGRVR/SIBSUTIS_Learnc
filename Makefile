CC=gcc
CFLAGS=-Wall --pedantic -g -lm
BIN=./bin
SRC=./src
TESTDIR=./tests

build:
	$(CC) ./$(SRC)/1.c -o 1 $(CFLAGS)

test:
	./1 10 1 10
	./1 100 1 10
	./1 1000 1 10
