CC = g++
CFLAGS = -Wall -o
TARGETS = PuzzleBoard

all: $(TARGETS)

PuzzleBoard: testPuzzleBoard.cpp PuzzleBoard.cpp PuzzleBoard.h
	$(CC) $(CFLAGS) PuzzleBoard testPuzzleBoard.cpp PuzzleBoard.cpp

run: PuzzleBoard
	./PuzzleBoard

clean:
	rm PuzzleBoard