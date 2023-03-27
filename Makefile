CC=g++ -std=c++17
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/main.cpp src/game.cpp src/board.cpp src/snake.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=build/game

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
