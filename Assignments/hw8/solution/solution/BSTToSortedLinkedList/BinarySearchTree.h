/*
	CH-231-A
	hw8_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "LinkedList.h"

class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int data);
};

TreeNode::TreeNode(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

class BinarySearchTree {
    public:
        TreeNode *root;
        BinarySearchTree();
        
        void insert(int data);
        void insertUnderRoot(TreeNode *root, int data);
        void toSortedLinkedList(LinkedList &list);
        void toSortedLinkedListUnderRoot(LinkedList &list, TreeNode *root);
        void print();
        void printUnderRoot(TreeNode *root);
};

BinarySearchTree::BinarySearchTree() {
    this->root = NULL;
}

void BinarySearchTree::insert(int data) {
    TreeNode *newElement = new TreeNode(data);
    // Check if root of the tree is NULL
    if (this->root == NULL)
        // Set root to the newElement
        this->root = newElement;
    else
        // Call the recursive insert function to place the element into the tree
        this->insertUnderRoot(this->root, data);
    std::cout << "Inserted element " << data
              << " into Binary Search Tree!" << std::endl;
}

void BinarySearchTree::insertUnderRoot(TreeNode *root, int data) {
    // Check if the element we are trying to place is bigger than the root
    if (data > root-> data) {
        // In case it is bigger, check if the right branch of root is empty
        if (root->right == NULL) {
            // Insert the element into the right branch of the root
            root->right = new TreeNode(data);
        } else {
            // Try to insert the element into the right subtree
            this->insertUnderRoot(root->right, data);
        }
    } else {
        // In case it is smaller or equal, check if the left branch of root is
        // empty
        if (root->left == NULL) {
            // Insert the element into the left branch of the root
            root->left = new TreeNode(data);
        } else {
            // Try to insert the element into the left subtree
            this->insertUnderRoot(root->left, data);
        }
    }
}

void BinarySearchTree::toSortedLinkedList(LinkedList &list) {
    // Check if root is empty
    if (this->root == NULL)
        std::cout << "Binary Search Tree has no elements inside!" << std::endl;
    else
        // Call the recursive transfer function to move the elements from the
        // BST to a Sorted Linked List
        this->toSortedLinkedListUnderRoot(list, this->root);
}

void BinarySearchTree::toSortedLinkedListUnderRoot(LinkedList &list,
                                                   TreeNode *root) {
    // Call itself recursively with the right subtree if it exists
    if (root->right != NULL)
        toSortedLinkedListUnderRoot(list, root->right);
    // Push the element at the root into the list
    list.pushList(root->data);
    // Call itself recursively with the left subtree if it exists
    if (root->left != NULL)
        toSortedLinkedListUnderRoot(list, root->left);
}

void BinarySearchTree::print() {
    // Check if Binary Search Tree is empty
    if (this->root != NULL) {
        std::cout << "Binary Search Tree:";
        // Call the recursive function for the root of the Binary Search Tree
        printUnderRoot(this->root);
        std::cout << std::endl;
    } else
        std::cout << "Binary Search Tree has no elements inside!" << std::endl;
}

void BinarySearchTree::printUnderRoot(TreeNode *root) {
    // Print the elements of the left subtree if it exists
    if (root->left != NULL)
        printUnderRoot(root->left);
    // Print the data field of the root element
    std::cout << " " << root->data;
    // Print the elements of the right subtree if it exists
    if (root->right != NULL)
        printUnderRoot(root->right);
}