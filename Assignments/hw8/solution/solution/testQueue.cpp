/*
	CH-231-A
	hw8_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> queue;

    for (int i = 1; i < 6; i++) {
        std::cout << "Enqueued element " << i << " onto the queue."
                  << std::endl;
        queue.Enqueue(i);
        std::cout << std::endl;
    }    
    std::cout << "Enqueued 5 elements onto the queue!" 
              << std::endl << std::endl;

    for (int i = 1; i < 6; i++) {
        queue.Dequeue();
        std::cout << std::endl;
    }

    std::cout << "Dequeued 5 elements from the queue!" << std::endl;

    // Test dequeueing when queue is empty
    std::cout << std::endl << "Trying to dequeue when queue is empty:" 
              << std::endl;
    queue.Dequeue();
    
    return 0;
}