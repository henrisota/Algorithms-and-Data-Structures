/*
	CH-231-A
	hw8_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "LinkedList.h"

int main() {
	int elements[10] = {42, 33, 27, 24, 17, 14, 9, 6, 4, 2};
	LinkedList list;
	BinarySearchTree bst;

	// Push elements sorted increasingly into the list
	for (auto element : elements)
		list.pushList(element);

	// Print the linked list
	list.printList();

	TreeNode *root = list.toBST();
	bst.root = root;

	// Printing the elements of the Binary Search Tree
	bst.print();

	return 0;
}