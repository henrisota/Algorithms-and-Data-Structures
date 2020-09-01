/*
	CH-231-A
	hw9_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "RedBlackTree.h"

int main() {
    RedBlackTree rbt;
    int inElements[6] = {13, 44, 37, 7, 22, 16};

    // Test inserting values into the Red Black Tree
    for (int element : inElements) {
        std::cout << "Inserting element with value " << element
                  << " into the Red Black Tree!" << std::endl;
        rbt.insert(element);
        std::cout << "State of the Red Black Tree (inorder):" << std::endl;
        rbt.inOrder();
        std::cout << std::endl;
    }

    // Test removal of values from the Red Black Tree
    // Trying to remove number 23 will result in a error message saying that
    // there is not a node with that key value inside the tree
    int outElements[3] = {13, 23, 37};
    for (int element : outElements) {
        std::cout << "Deleting element with value " << element
                  << " from the Red Black Tree!" << std::endl;
        rbt.deleteFromTree(element);
        std::cout << "State of the Red Black Tree (inorder):" << std::endl;
        rbt.inOrder();
        std::cout << std::endl;
    }

    return 0;
}