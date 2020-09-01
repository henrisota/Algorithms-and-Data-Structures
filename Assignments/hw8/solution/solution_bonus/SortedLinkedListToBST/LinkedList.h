/*
	CH-231-A
	hw8_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "BinarySearchTree.h"

class ListNode {
    public:
        int data;
        ListNode *next;
        ListNode(int data);
        ListNode();   
};

ListNode::ListNode(int data) {
    this->data = data;
    this->next = NULL;
}

ListNode::ListNode() {
    this->data = 2147483647; // Set it to INT_MAX value
    this->next = NULL;
}

class LinkedList {
    public:
        ListNode *head;
        LinkedList();

        void pushList(int data);
        void printList();
        int countListNodes();
        TreeNode* toBST();
        TreeNode* toBSTUnderRoot(ListNode **head, int n);
};

LinkedList::LinkedList() {
    this->head = NULL;
}

void LinkedList::pushList(int data) {
    ListNode *newElement = new ListNode(data);
    // Check if list is empty
    if (this->head != NULL)
        // Prepend the element before the start of the list 
        newElement->next = this->head;
    else {} // Do nothing
    // Make newElement the new head of the list
    this->head = newElement;
    std::cout << "Pushed element " << data << " into the Linked List!"
              << std::endl;
}

void LinkedList::printList() {
    ListNode *cursor = this->head;
    std::cout << "Sorted Linked List: ";
    // Print the elements of the linked list by traversing the list
    while (cursor != NULL) {
        if (cursor == this->head)
            std::cout << cursor->data;
        else std::cout << " " << cursor->data;
        cursor = cursor->next;
    }
    std::cout << std::endl;
}

int LinkedList::countListNodes() {
    int count = 0;
    ListNode *cursor = this->head;
    // Traverse through the list and count the number of elements
    while (cursor != NULL) {
        count++;
        cursor = cursor->next;
    }
    return count;
}

TreeNode* LinkedList::toBST() {
    // Calculate the number of ListNodes in the Linked List
    int n = this->countListNodes();

    // Construct the Binary Search Tree and return its root TreeNode
    return toBSTUnderRoot(&this->head, n);
}

TreeNode* LinkedList::toBSTUnderRoot(ListNode **head, int n) {
    if (n <= 0)
        return NULL;

    // Construct the left subtree by calling itself
    TreeNode *left = toBSTUnderRoot(head, n/2);
    // Set the root of the tree
    TreeNode *root = new TreeNode((*head)->data);
    // Connect the current root to its left subtree
    root->left = left;
    // Move on onto the next element
    *head = (*head)->next;
    // Construct the right subtree by calling itself and connect it to the root
    root->right = toBSTUnderRoot(head, n - n / 2 - 1);

    return root;
}