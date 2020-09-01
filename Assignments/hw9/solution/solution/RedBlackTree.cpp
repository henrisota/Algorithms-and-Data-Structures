/*
	CH-231-A
	hw9_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "RedBlackTree.h"

void RedBlackTree::createNILNode(Node *node, Node *parent) {
    // Place NIL node properties to the given node and connect it to parent
    node->data = 0;
    node->color = BLACK;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = parent;
}

void RedBlackTree::preOrderTraversalRecursive(Node *x) {
    // Traverse the Red Black Tree recursively and read it preoder manner while 
    // x is not a NIL element
    if (x != this->NIL) {
        std::cout << x->data;
        // Output the color of the node
        if (x->color == RED)
            std::cout << "R ";
        else std::cout << "B ";
        this->preOrderTraversalRecursive(x->left);
        this->preOrderTraversalRecursive(x->right);
    }
}

void RedBlackTree::inOrderTraversalRecursive(Node *x) {
    // Traverse the Red Black Tree recursively and read it inorder manner while
    // x is not a NIL element
    if (x != this->NIL) {
        this->inOrderTraversalRecursive(x->left);
        std::cout << x->data;
        // Output the color of the node
        if (x->color == RED)
            std::cout << "R ";
        else std::cout << "B ";
        this->inOrderTraversalRecursive(x->right);
    }
}

void RedBlackTree::postOrderTraversalRecursive(Node *x) {
    // Traverse the Red Black Tree recursively and read it postorder manner 
    // while x is not a NIL element
    if (x != this->NIL) {
        this->postOrderTraversalRecursive(x->left);
        this->postOrderTraversalRecursive(x->right);
        std::cout << x->data;
        // Output the color of the node
        if (x->color == RED)
            std::cout << "R ";
        else std::cout << "B ";
    }
}

void RedBlackTree::transplant(Node *u, Node *v) {
    // Check if the parent element is NULL (transplant to the root)
    if (u->parent == nullptr)
        this->root = v;
    // Else check if the node we are transplanting to is left node of its parent
    else if (u == u->parent->left)
        // Make v the left node of u's parent
        u->parent->left = v;
    // Else make v the right node of u's parent
    else u->parent->right = v;
    // Set the connection between u's parent and v from v's node side
    v->parent = u->parent;
}

void RedBlackTree::insertFixUp(Node *z) {
    Node *y;
    // Iterate while the color of z's parent is RED
    while (z->parent->color == RED) {
        // Symmetrical case when z's parent is the left child of z's granparent
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;
            // Case 1
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                // Case 2
                if (z == z->parent->right) {
                    z = z->parent;
                    this->rotateLeft(z);
                }
                // Case 3
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                this->rotateRight(z->parent->parent);
            }
        } else {
            // Symmetrical case when z's parent is the right child of z's
            // grandparent
            y = z->parent->parent->left;
            // Case 1
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                // Case 2
                if (z == z->parent->left) {
                    z = z->parent;
                    this->rotateRight(z);
                }
                // Case 3
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                this->rotateLeft(z->parent->parent);
            }
        }
        // Break when z is the root of the Red Black Tree
        if (z == this->root)
            break;
    }
    // Set the root's color to be black to preserve property 2
    this->root->color = BLACK;
}

void RedBlackTree::deleteNode(Node *node, int key) {
    Node *z = this->NIL;
    Node *x, *y;

    // Search for the node with the key
    while (node != this->NIL) {
        if (node->data == key)
            z = node;
        if (node->data <= key)
            node = node->right;
        else node = node->left;
    }
    // Check if the node with the key wasn't found
    if (z == this->NIL) {
        // Print message in case node isn't found and break out of the function
        std::cout << "Node with key " << key << " is not found in the tree!"
                  << std::endl;
        return;
    }
    y = z;
    Color y_original_color = y->color;
    // Check if z's left child is empty
    if (z->left == this->NIL) {
        // Place x at z's right child
        x = z->right;
        // Tranplant z's right child (x) into z's position
        this->transplant(z, z->right);
    } else if (z->right == this->NIL) {
        // In case z's right child is empty
        // Place x at z's left child
        x = z->left;
        // Transplant z's left child (x) into z's position
        this->transplant(z, z->left);
    } else {
        // In case both children of z exist
        // Find the minimum of z's right subtree
        y = this->minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        // Check if y is z's child (successor of z is its child)
        if (y->parent == z)
            x->parent = y;
        else {
            // Tranplant y's right child into y's positon
            this->transplant(y, y->right);
            // Put z's right child as y's right child
            y->right = z->right;
            // Make y the y's right child parent
            y->right->parent = y;
        }
        // Move y into z's position
        this->transplant(z, y);
        // Make z's left child the left child of y
        y->left = z->left;
        // Make y the parent of y' left child
        y->left->parent = y;
        // Set y's color to be the same color as z's color
        y->color = z->color;
    }
    // Delete the node to free up memory
    delete z;
    // Check in case the color of node y in its last position was BLACK
    if (y_original_color == BLACK)
        // Call deleteFixUp on x to preserve red-black properties
        this->deleteFixUp(x);
}

void RedBlackTree::deleteFixUp(Node *x) {
    Node *w;
    // Iterate while x is not the root and while x's color is BLACK
    while ((x != root) && (x->color == BLACK)) {
        // Symmetric case when x is the left child of its parent
        if (x == x->parent->left) {
            // Set w to be the right child of x's parent
            w = x->parent->right;
            // Check if w's color is RED
            if (w->color == RED) {
                // Case 1
                w->color = BLACK;
                x->parent->color = RED;
                this->rotateLeft(x->parent);
                w = x->parent->right;
            }
            // Check if both children of w are BLACK
            if ((w->left->color) == BLACK && (w->right->color == BLACK)) {
                // Case 2
                w->color = RED;
                x = x->parent;
            } else {
                // Check if w's right child color is BLACK
                if (w->right->color == BLACK) {
                    // Case 3
                    w->left->color = BLACK;
                    w->color = RED;
                    this->rotateRight(w);
                    w = x->parent->right;
                }
                // Case 4
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                this->rotateLeft(x->parent);
                x = root;
            }
        } else {
            // Symmetric case when x is the right child of its parent
            // Set w to be the left child of x's parent
            w = x->parent->left;
            // Check if w's color is RED
            if (w->color == RED) {
                // Case 1
                w->color = BLACK;
                x->parent->color = RED;
                this->rotateRight(x->parent);
                w = x->parent->left;
            }
            // Check if both children of w are BLACK
            if ((w->right->color == BLACK) && (w->left->color == BLACK)) {
                // Case 2
                w->color = RED;
                x = x->parent;
            } else {
                // Check if w's right child color is BLACK
                if (w->left->color == BLACK) {
                    // Case 3
                    w->right->color = BLACK;
                    w->color = RED;
                    this->rotateLeft(w);
                    w = x->parent->left;
                }
                // Case 4
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                this->rotateRight(x->parent);
                x = root;
            }
        }
    }
    // Set x's color to be BLACK after fix up procedure
    x->color = BLACK;
}

Node* RedBlackTree::searchTreeRecursive(Node *x, int key) {
    // Check if x is the NIL element or node with the key has been found
    if ((x == this->NIL) || (key == x->data))
        return x;

    // Search recursively under the left subtree or right subtree depending
    // if the key is less than or bigger than x which is the root of the
    // current "tree"
    if (key < x->data)
        return searchTreeRecursive(x->left, key);
    else return searchTreeRecursive(x->right, key);
}

void RedBlackTree::rotateLeft(Node *x) {
    // Set x's right child be y
    Node *y = x->right;
    // Make y's left child the right child of x
    x->right = y->left;
    // Check if y's left child is not empty
    if (y->left != this->NIL)
        // Make x to be the parent of y's left child
        y->left->parent = x;
    // Make x's parent be y's parent
    y->parent = x->parent;
    // Check if x's parent is NULL (root case)
    if (x->parent == nullptr)
        this->root = y;
    else if (x == x->parent->left)
        // In case x is the left child of its parent
        // Make y be the left child of x's parent
        x->parent->left = y;
    // Else make y be the right child of x's parent
    else x->parent->right = y;
    // Set x to be y's left child
    y->left = x;
    // Set y to be x's parent
    x->parent = y;
}

void RedBlackTree::rotateRight(Node *y) {
    // Set y's left child to be x
    Node *x = y->left;
    // Make x's right child the left child of y
    y->left = x->right;
    // Check if x's right child is not empty
    if (x->right != this->NIL)
        // Make y to be the parent of x's right child
        x->right->parent = y;
    // Make y's parent be x's parent
    x->parent = y->parent;
    // Check if y's parent is NULL (root case)
    if (y->parent == nullptr)
        this->root = x;
    else if (y == y->parent->right)
        // In case y is the right child of its parent
        // Make x be the right child of y's parent
        y->parent->right = x;
    // Else make x be the left child of y's parent
    else y->parent->left = x;
    // Set y to be x's left right
    x->right = y;
    // Set x to be y's parent
    y->parent = x;
}

RedBlackTree::RedBlackTree() {
    // Empty constructor of Red Black Tree
    // Initialize the NIL node of the Red Black Tree with color BLACK and set
    // it to be the "root"
    this->NIL = new Node;
    this->root = this->NIL;
    this->NIL->color = BLACK;
    this->NIL->left = nullptr;
    this->NIL->right = nullptr;
}

void RedBlackTree::insert(int key) {
    // Set up the new node to be inserted
    Node *z = new Node;
    z->parent = nullptr;
    z->data = key;
    z->left = this->NIL;
    z->right = this->NIL;
    z->color = RED;

    Node *y = nullptr;
    Node *x = this->root;

    // Search for the position to place the new node iteratively
    while (x != this->NIL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else x = x->right;
    }
    // Set the parent of z to be y
    z->parent = y;
    
    // Check if y is NULL (root case)
    if (y == nullptr)
        // Set z to be the new root
        this->root = z;
    else if (z->data < y->data)
        // Else if z is less than the value of y
        // Set z to be y's left child
        y->left = z;
    // Set z to be y's right child (z's data is bigger or equal to y's data)
    else y->right = z;
    // Check if z's parent is NULL
    if (z->parent == nullptr) {
        // Set z to be BLACk
        z->color = BLACK;
        return;
    }
    // Check if z's grandparent is nULL
    if (z->parent->parent == nullptr)
        // Break out of the function
        return;
    // Fix the insertion procedure by calling insert fix up on z
    this->insertFixUp(z);
}

void RedBlackTree::deleteFromTree(int key) {
    // Call the helper method deleteNode that removes the node with data
    // property set to key if this node is found
    this->deleteNode(this->root, key);
}

Node* RedBlackTree::predecessor(Node *x) {
    // Check if x's left child is not NIL
    if (x->left != this->NIL)
        // Predecessor is the maximum of x's left subtree
        return this->maximum(x->left);
    // In case there is no left child
    // Set x's parent to be y
    Node *y = x->parent;
    // Move up the tree until y becomes NIL (arrived at root) or x is the left
    // child of the current y
    while ((y != this->NIL) && (x == y->left)) {
        // Move up the tree by setting x to be y and make y to be its parent
        x = y;
        y = y->parent;
    }
    return y;
}

Node* RedBlackTree::successor(Node *x) {
    // Check if x's right child is not NIL
    if (x->right != this->NIL)
        // Successor is the minimum of x's right subtree
        return this->minimum(x->right);
    // In case there is no right child
    // Set x's parent to be y
    Node *y = x->parent;
    // Move up the tree until y becomes NIL (arrived at NIL) or x is the right
    // child of the current y
    while ((y != this->NIL) && (x == y->right)) {
        // Move up the tree by setting x to be y and make y to be its parent
        x = y;
        y = y->parent;
    }
    return y;
}

Node* RedBlackTree::getMinimum() {
    // Check if root exists
    if (this->root)
        // Return the value of the helper function minimum, which recursively
        // searches the tree under root node
        return this->minimum(this->root);
    // Cover case when root doesn't exist
    // Note:    Impossible to happen in this setup, but this was written to 
    //          remove the warnings of the compiler
    else return {};
}

Node* RedBlackTree::getMaximum() {
    // Check if root exists
    if (this->root)
        // Return the value of the helper function maximum, which recursively
        // searches the tree under the root node
        return this->maximum(this->root);
    // Cover case when root doesn't exist
    // Note:    Impossible to happen in this setup, but this was written to 
    //          remove the warnings of the compiler
    else return {};
}

Node* RedBlackTree::search(int key) {
    // Return the value of the recursive search functions that searches
    // the tree under the root node for this key
    return this->searchTreeRecursive(this->root, key);
}

Node* RedBlackTree::minimum(Node *x) {
    // Iterate while x's left child is not NIL
    while (x->left != this->NIL)
        // Set x to be its left child
        x = x->left;
    return x;
}

Node* RedBlackTree::maximum(Node *x) {
    // Iterate while x's right child is not NIL
    while (x->right != this->NIL)
        // Set x to be its right child
        x = x->right;
    return x;
}

void RedBlackTree::preOrder() {
    // Cal recursive helper function to read the under root node
    this->preOrderTraversalRecursive(this->root);
}

void RedBlackTree::inOrder() {
    // Cal recursive helper function to read the under root node
    this->inOrderTraversalRecursive(this->root);
}

void RedBlackTree::postOrder() {
    // Cal recursive helper function to read the under root node
    this->postOrderTraversalRecursive(this->root);
}