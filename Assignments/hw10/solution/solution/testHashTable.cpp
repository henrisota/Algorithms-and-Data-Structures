/*
	CH-231-A
	hw10_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "HashTable.h"

int main() {
	HashTable hashTable;

	// Insert a few nodes onto the Hash Table
	hashTable.insertNode(0, 47);
	hashTable.insertNode(14, 91);
	hashTable.insertNode(15, 92);
	hashTable.insertNode(4, 25);

	// Insert a node with key 28 (hashedKey = 28 % 25 = 3)
	hashTable.insertNode(28, 19);

	// Insert a node with key 29 (hashedKey = 29 % 25 = 4)
	// Linear probing is applied to this to place element in position 5
	hashTable.insertNode(29, 24);

	// Test wrap around functionality and linear probing

	// Insert a node with key 24
	hashTable.insertNode(24, 11);
	// Insert a node with key 49 (hashedKey = 49 % 25 = 4)
	// Linear probing is applied to this to place element in position 1
	// by wrapping around back to position 0 and probing from there
	hashTable.insertNode(49, 25);

	// Extra inserts to test Hash Table at full capacity
	// hashTable.insertNode(26, 85);
	// hashTable.insertNode(6, 90);
	// hashTable.insertNode(7, 97);
	// hashTable.insertNode(8, 96);
	// hashTable.insertNode(9, 93);
	// hashTable.insertNode(10, 67);
	// hashTable.insertNode(11, 63);
	// hashTable.insertNode(12, 47);
	// hashTable.insertNode(13, 50);
	// hashTable.insertNode(16, 39);
	// hashTable.insertNode(41, 29);
	// hashTable.insertNode(40, 47);
	// hashTable.insertNode(36, 39);
	// hashTable.insertNode(38, 9);
	// hashTable.insertNode(21, 3);
	// hashTable.insertNode(22, 8);
	// hashTable.insertNode(23, 5);
	// hashTable.insertNode(24, 44);

	std::cout << std::endl;
	hashTable.printHashTable();
	std::cout << std::endl;

	// Test get functionality
	hashTable.get(4);
	hashTable.get(29);
	hashTable.get(49);
	hashTable.get(24);
	hashTable.get(33);

    return 0;
}