CC=g++
SOURCES=main.cpp src/board.cpp src/game.cpp
LIBS=-lncurses
BIN=bin/snakegame

all: run

build: $(SOURCES)
	$(CC) $(SOURCES) $(LIBS) -o $(BIN)

run: build
	./$(BIN)

clear:
	rm $(BIN)