/*
	CH-231-A
	hw10_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <iomanip>
#include "HashTable.h"

Node::Node(int key, int value) {
	this->key = key;
	this->value = value;
}

HashTable::HashTable() {
	// Initiliaze a Hash Table with 25 open positions
	this->maxSize = 25;
	this->currentSize = 0;
	this->arr = new Node*[this->maxSize];
	// Set each Node pointer to NULL
	for (int i = 0; i < this->maxSize; ++i) 
		arr[i] = NULL;
}

HashTable::~HashTable() {
	for (int i = 0; i < this->maxSize; ++i)
		if (this->arr[i] != NULL)
			delete arr[i];
}

int HashTable::hashCode(int key) {
	// Return the value of the hashed by using the division method: k mod m
	return (key % this->maxSize);
}

void HashTable::insertNode(int key, int value) {
	// Check if Hash Table is full before inserting
	if (this->currentSize >= this->maxSize)
		// Output message in case Hash Table is full
		std::cout << "Insertion is not possible as Hash Table is full!"
				  << std::endl;
	else {
		// Insert new node into Hash Table
		Node *newEntry = new Node(key, value);
		// Calculate hash of the key
		int hashedKey = this->hashCode(key);
		// Check if node at hashed key position is empty
		if (this->arr[hashedKey] == NULL) {
			std::cout << "Successfully inserted into position "
					  << this->hashCode(key) << std::endl;
			this->arr[hashedKey] = newEntry;
		} else {
			// Perform linear probing to find next possible position to insert
			int i = 0;
			// Increase i until i has reached Hash Table size or empty position
			// has been found
			while ((i <= this->maxSize) && 
				   (arr[(hashedKey + i) % this->maxSize] != NULL)) {
				i++;
			}
			std::cout << "Successfully inserted into position "
					  << (hashedKey + i) % this->maxSize << std::endl;
			this->arr[(hashedKey + i) % this->maxSize] = newEntry;
		}
		// Inrease current size by 1 after insertion
		this->currentSize++;
	}
}

int HashTable::get(int key) {
	// Calculate hash of the key
	int hashedKey = this->hashCode(key);
	// Check if node at hashed key is empty
	if (this->arr[hashedKey] == NULL) {
		std::cout << "Couldn't retrieve any element with key " << key << "!"
				  << std::endl;
		return {};
	} else {
		// Perform linear probing to search the next possible positions
		int i = 0;
		// Increase i until i has reached Hash Table size or key has been
		// found
		while ((i <= this->maxSize) &&
			   (this->arr[(hashedKey + i) % this->maxSize]->key != key)) {
			i++;
		}
		// Check if key matches in case the while loop went through the whole
		// table and returned to the same position
		if (this->arr[(hashedKey + i) % this->maxSize]->key == key) {
			std::cout << "Retrieved element with key " << key << " in position "
					<< (hashedKey + i)  % this->maxSize << " and value "
					<< this->arr[(hashedKey + i) % this->maxSize]->value 
					<< std::endl;
			return this->arr[(hashedKey + i) % this->maxSize]->value;
		} else {
			// Search wasn't successful even after while loop traversed the
			// whole Hash Table
			std::cout << "Couldn't retrieve any element with key " << key << "!"
					  << std::endl;
			return {};
		}
	}
}

bool HashTable::isEmpty() {
	// Return boolean value in case Hash Table is empty
	return !this->currentSize;
}

void HashTable::printHashTable() {
	std::cout << "Hash Table (m = " << this->maxSize << "):" << std::endl;
	// Print information regarding each entry in the Hash Table if not NULL
	for (int i = 0; i < this->maxSize; ++i) {
		if (this->arr[i] != NULL)
			std::cout << "Position " << std::setw(2) << i << ":\t("
					  << std::setw(3) << this->arr[i]->key
					  << ", "
					  << std::setw(3) << this->arr[i]->value
					  << ")"
					  << std::endl;
	}
}