/*
	CH-231-A
	hw2_p5.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include <set>

int main() {
	// Set is the suitable container
	int temp;
	std::set<int> randoms;
	std::set<int>::iterator it;

	// Initializing random number generator
	srand(time(NULL));

	// Produce random numbers until 6 unique ones show up and insert them into
	// the set
	while (randoms.size() != 6) {
		temp = rand() % 49 + 1;
		randoms.insert(temp);
	}

	// Iterate through the set and output each integer into stdout
	for (it = randoms.begin(); it != randoms.end(); it++) {
		if (it == randoms.begin())
			std::cout << *it;
		else std::cout << " " << *it;
	}
	std::cout << std::endl;

	return 0;
}