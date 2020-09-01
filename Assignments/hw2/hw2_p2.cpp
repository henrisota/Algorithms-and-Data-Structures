/*
	CH-231-A
	hw2_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <deque>

int main() {
	// Create deque made of floats
	std::deque<float> A;
	float temp;

	// Read floats until inputted value is 0
	std::cin >> temp;
	while (temp != 0) {
		// Store them in the back or the front according to their sign
		if (temp > 0)
			A.push_back(temp);
		else A.push_front(temp);
		std::cin >> temp;
	}

	// Output deque to stdout
	for (std::deque<float>::iterator it = A.begin(); it != A.end(); it++) {
		if (it == A.begin())
			std::cout << *it;
		else std::cout << " " << *it;
	}

	// output newline to stdout
	std::cout << std::endl;

	// Iterate through the deque until finding a positive float and insert a 0
	// in that position in the deque
	for (std::deque<float>::iterator it = A.begin(); it != A.end(); it++) {
		if (*it > 0) {
			A.insert(it, 0);
			break;
		}
	}

	// Output deque to stdout after insertion
	for (std::deque<float>::iterator it = A.begin(); it != A.end(); it++) {
		if (it == A.begin())
			std::cout << *it;
		else std::cout << ";" << *it;
	}

	std::cout << std::endl;

	return 0;
}