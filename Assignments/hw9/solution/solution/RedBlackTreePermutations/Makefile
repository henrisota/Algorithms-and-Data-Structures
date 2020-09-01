CC = g++
CFLAGS = -Wall -o
TARGETS = RedBlackTreePermutations

all: $(TARGETS)

RedBlackTreePermutations: redBlackTreePermutations.cpp RedBlackTree.cpp RedBlackTree.h
	$(CC) $(CFLAGS) rbt_permutations redBlackTreePermutations.cpp RedBlackTree.cpp

run: rbt_permutations
	./rbt_permutations

clean:
	rm rbt_permutations