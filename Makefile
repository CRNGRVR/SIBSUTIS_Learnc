CC=gcc
CFLAGS=-Wall --pedantic -Wextra -std=c99
BIN=./bin
SRC=./src
TESTDIR=./tests
EXTRA=./extra

TARGET = test_runner

$(TARGET): $(SRC)/advanced_array_function.c $(TESTDIR)/test_advanced_array_function.c $(EXTRA)/Unity/unity.c
	$(CC) $(CFLAGS) $(SRC)/advanced_array_function.c \
	$(TESTDIR)/test_advanced_array_function.c \
	$(EXTRA)/Unity/unity.c -o $(BIN)/$(TARGET)

test: $(TARGET)
	./$(BIN)/$(TARGET)

clean:
	rm -rf $(BIN)

.PHONY: test clean