CC=i686-w64-mingw32-g++
cflags=-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
BIN=1.exe

build:
				$(CC) -C main.cpp -L"./lib/" $(cflags) -o $(BIN) --static
				wine ./$(BIN)