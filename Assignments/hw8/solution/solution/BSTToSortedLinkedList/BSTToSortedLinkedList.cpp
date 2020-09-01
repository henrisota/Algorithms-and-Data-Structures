/*
	CH-231-A
	hw8_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "BinarySearchTree.h"

int main() {
    int elements[10] = {4, 12, 9, 2, 13, 19, 21, 8, 8, 15};
    BinarySearchTree bst;
    LinkedList list;

    // The elements inside the Binary Search Tree
    for (auto element : elements)
        bst.insert(element);

    // Print the elements of the Binary Search Tree
    bst.print();

    bst.toSortedLinkedList(list);

    // Printing the elements of the list
    list.printList();

    return 0;
}