/*
	CH-231-A
	hw8_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>

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