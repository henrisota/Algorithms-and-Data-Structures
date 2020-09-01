/*
	CH-231-A
	hw1_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "Stack.h"

int main() {
    // Create integer stack with initialSize
    Stack<int> iStack;
    // Create double stack with size 50
	Stack<double, 50> dStack;

    // Created variables to keep popped value
    int iPop;
    double dPop;

    // Fill integer stack with squares of the first 10 natural numbers
	for (int i = 0; i < 10; i++)
		iStack.push(i * i);
    
    // Fill double stack with the numbers 1-50 with a small increment value of
    // 0.01
    for (int i = 0; i < 50; i++)
        dStack.push(i + 1.01);

    // Testing pushing over stack size
    std::cout << "Pushing one more element onto integer stack when it is full "
              << "results into being: "
              << iStack.push(100)
              << std::endl;

    // Using copy constructor on integer stack
    Stack<int> iStackCopy(iStack);

    // Pop each element of the copy constructed stack
    for (int i = 0; i < 10; i++)
        iStackCopy.pop(iPop);
    
    // Testing popping when stack is empty
    std::cout << "Popping one more element onto integer stack when it is empty"
              << " results into being: "
              << iStackCopy.pop(iPop)
              << std::endl;
    
    // Get the element on the top of the double stack
    std::cout << "Element on the back of the double stack is: "
              << dStack.back()
              << std::endl;

    // Pop one element from integer and double stack
    iStack.pop(iPop);
    dStack.pop(dPop);
    std::cout << "Element popped from integer stack is: "
              << iPop
              << std::endl
              << "Element popped from double stack is: "
              << dPop
              << std::endl;

    // Get the number of elements in both stacks
    std::cout << "Number of elements in integer stacks is: "
              << iStack.getNumEntries()
              << std::endl
              << "Number of elements in double stack is: "
              << dStack.getNumEntries()
              << std::endl;

    return 0;
}