CC = g++
CFLAGS = -Wall -o
TARGETS = RedBlackTree

all: $(TARGETS)

RedBlackTree: testRedBlackTree.cpp RedBlackTree.cpp RedBlackTree.h
	$(CC) $(CFLAGS) rbt testRedBlackTree.cpp RedBlackTree.cpp

run: rbt
	./rbt

clean:
	rm rbt