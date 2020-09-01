/*
	CH-231-A
	hw1_p3.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "LinkedList.h"

int main() {
	List<int> list;
    list.push_front(14);
    list.push_front(11);
    list.push_back(12);
	list.push_back(15);

    std::cout << "List has "
			  << list.elementNumber()
			  << " elements."
			  << std::endl
			  << "Element in the front is: "
			  << list.front()
			  << std::endl
			  << "Element in the back is: "
			  << list.back()
			  << std::endl;

    list.push_front(1);
    list.push_back(13);

    std::cout << "After pushing one element into the front and one into "
			  << "the back, List has "
			  << list.elementNumber()
			  << " elements now."
			  << std::endl
			  << "Element in the front is: "
			  << list.front()
			  << std::endl
			  << "Element in the back is: "
			  << list.back()
			  << std::endl;

    std::cout << "Popping element from the front: " 
			  << list.pop_front()
			  << std::endl
			  << "Popping element from the back: "
			  << list.pop_back()
			  << std::endl;

	std::cout << "Element in the front is: "
			  << list.front()
			  << std::endl
			  << "Element in the back is: "
			  << list.back()
			  << std::endl
			  << "List has "
			  << list.elementNumber()
			  << " elements left."
			  << std::endl;

	// Empty List by popping every element and test pop when List is empty
	for (int i = 0; i < 5; i++)
		list.pop_back();

	return 0;
}