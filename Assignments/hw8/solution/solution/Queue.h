/*
	CH-231-A
	hw8_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "Stack.h"

template <typename T>
class Queue {
    private:
        Stack<T> firstStack, secondStack;
    public:
        void Enqueue(T x);
        T Dequeue();
        // Implementation of the constructor, parametric constructor
        //  and destructor is not necessary in this case
        // Queue(int new_size);
        // Queue();
        // ~Queue();
};

template <typename T>
void Queue<T>::Enqueue(T x) {
    // Push enqueued elements onto the first stack
    std::cout << "First Stack: ";
    this->firstStack.push(x);
}

template <typename T>
T Queue<T>::Dequeue() {
    // Check if queue is empty
    if ((this->firstStack.isEmpty()) && (this->secondStack.isEmpty())) {
        std::cout << "Queue is empty!" << std::endl;
        return {};
    }
    // Check if the second stack is empty
    if (this->secondStack.isEmpty()) {
        std::cout << "Transferring elements from stacks!" << std::endl;
        // Pop all elements of the first stack and push them onto the second
        // stack, thus reversing the order of the elements that entered in the
        // first stack
        while (!this->firstStack.isEmpty()) {
            T transfer = this->firstStack.pop();
            this->secondStack.push(transfer);
        }
        std::cout << std::endl;
    }
    // Pop one element from the second stack
    T dequeued = this->secondStack.pop();
    std::cout << "Dequeued element " << dequeued << " from the queue."
              << std::endl;
    return dequeued;
}