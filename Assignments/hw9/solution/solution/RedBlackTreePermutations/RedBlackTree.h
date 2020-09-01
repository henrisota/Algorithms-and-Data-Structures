/*
	CH-231-A
	hw9_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <string>

enum Color {RED, BLACK};

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
};

class RedBlackTree {
    private:
        Node *root;

        Node *NIL;
        void createNILNode(Node *node, Node *parent);

        // Methods to read the Red Black Tree recursively from a given node
        void preOrderTraversalRecursive(Node *x);
        std::string inOrderTraversalRecursive(Node *x);
        void postOrderTraversalRecursive(Node *x);

        // Methods to modify the Red Black Tree
        void transplant(Node *u, Node *v);
        void insertFixUp(Node *z);
        void deleteNode(Node *node, int key);
        void deleteFixUp(Node *x);
        // Method to search the Red Black Tree recursively from a given node
        Node* searchTreeRecursive(Node *x, int key);

    protected:
        // Methods to rotate a node of the Red Black Tree
        void rotateLeft(Node *x);
        void rotateRight(Node *y);

    public:
        // Constructor
        RedBlackTree();

        // Method to insert element with data property key into Red Black Tree
        void insert(int key);
        // Method to remove element with data property key from Red Black Tree
        void deleteFromTree(int key);
        // Methods to find predecessor and successor of node x in Red Black Tree
        Node* predecessor(Node *x);
        Node* successor(Node *x);
        // Methods to find minimum and maximum node in Red Black Tree
        Node* getMinimum();
        Node* getMaximum();
        // Method to search for a given key inside the Red Black Tree
        Node* search(int key);

        // Methods to read the Red Black Tree from the root
        void preOrder();
        std::string inOrder();
        void postOrder();

        // Method to find the minimum of the subtree at given node x
        Node* minimum(Node *x);
        // Method to find the maximum of the subtree at given node x
        Node* maximum(Node *x);
};