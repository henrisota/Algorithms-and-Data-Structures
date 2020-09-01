/*
	CH-231-A
	hw8_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>

template <typename T>
class Stack {
    private:
        struct StackNode {      // linked list
            T data;
            StackNode *next;
        };
        StackNode *top;         // top of stack
        int size;               // -1 if not set, value otherwise
        int current_size;       // unused if size = -1
    public:
        void push(T x);         // if size set, check for overflow
        T pop();                // return element if not in underflow        
        bool isEmpty();         // true if empty, false otherwise
        Stack(int new_size);    // Parametrized constructor
        Stack();                // Constructor
        ~Stack();               // Destructor
};

template <typename T>
void Stack<T>::push(T x) {
    // Check if stack is full
    if (this->current_size == this->size)
        std::cout << "Stack Overflow!" << std::endl;
    else {
        this->current_size += 1;
        if (this->current_size == 0) {
            // Else in case there are no elements in the stack
            StackNode *newElement = new StackNode();
            newElement->data = x;
            // Set next field of newElement to NULL as it is the only element
            newElement->next = NULL;
            // Set top to point to newElement as it is the only element
            this->top = newElement;
            std::cout << "Push element with value " << this->top->data
                      << " onto the stack." << std::endl;
        } else {
            StackNode *newElement = new StackNode();
            // Set next pointer of newElement to current top
            newElement->next = top;
            newElement->data = x;
            // Set top to point to newElement as it is the last element in
            this->top = newElement;
            std::cout << "Push element with value " << this->top->data
                      << " onto the stack." << std::endl;
        }
    }
}

template <typename T>
T Stack<T>::pop() {
    // Check if there are no elements in the stack
    if (this->current_size == 0) {
        std::cout << "Stack Underflow!" << std::endl;
        return {};
    } else {
        // Set the element to be popped to point at top
        StackNode *poppedElement = this->top;
        T data = this->top->data;
        // Update top to point to next of the current top
        this->top = this->top->next;
        this->current_size--;
        std::cout << "Popped element with value " << data
                  << " from the stack." << std::endl;
        delete poppedElement;
        return data;
    }
}

template <typename T>
bool Stack<T>::isEmpty() {
    // Check if stack is empty
    if (current_size == 0)
        return true;
    else return false;
}

template <typename T>
Stack<T>::Stack(int new_size) {
    this->size = new_size;
    this->current_size = 0;
    this->top = NULL;
}

template <typename T>
Stack<T>::Stack() {
    this->size = -1;
    this->current_size = 0;
    this->top = 0;
}

template <typename T>
Stack<T>::~Stack() {
    while (!this->isEmpty()) {
        StackNode *temp = this->top;
        this->top = this->top->next;
        delete temp;
    }
}