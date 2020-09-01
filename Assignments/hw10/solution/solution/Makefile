CC = g++
CFLAGS = -Wall -o
TARGETS = HashTable

all: $(TARGETS)

HashTable: testHashTable.cpp HashTable.cpp HashTable.h
	$(CC) $(CFLAGS) hashtable testHashTable.cpp HashTable.cpp

run: hashtable
	./hashtable

clean:
	rm hashtable