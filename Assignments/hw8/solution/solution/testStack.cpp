/*
	CH-231-A
	hw8_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "Stack.h"

int main() {
	// Create new Stack with size 3
    Stack<int> stack(3);

	// Push 3 elements onto the Stack and try to push another one
    stack.push(4);
	stack.push(-6);
	stack.push(1);
	stack.push(10);

	// Empty the stack iteratively until there is no element left
	while (!stack.isEmpty())
		stack.pop();

	// Push a new element onto the empty stack
	stack.push(7);
	// Pop the newly added element
	stack.pop();
	// Try to pop another element from the stack when it is empty
	stack.pop();

    return 0;
}