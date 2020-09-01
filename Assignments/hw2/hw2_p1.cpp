/*
	CH-231-A
	hw2_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <list>
#include <fstream>

int main() {
	std::fstream file("listB.txt", std::ios::out);
	std::list<int> A, B;
	int temp;
	std::cin >> temp;

    // Push ints into the back of A and the front of B if they are positive
	while (temp > 0) {
		A.push_back(temp);
		B.push_front(temp);
		std::cin >> temp;
	}

    // Output list A into stdout
	for (std::list<int>::iterator it = A.begin(); it != A.end(); it++) {
		if (it == A.begin())
			std::cout << *it;
		else std::cout << " " << *it;
	}

    // Output list B into listB.txt file
	if (file.good() && file.is_open()) {
		for (std::list<int>::iterator it = B.begin(); it != B.end(); it++) {
			if (it == B.begin())
                file << *it;
			else file << " " << *it;
		}
	} else std::cout << "Error while opening file!" << std::endl;

	file.close();

    // Output newline in stdout
    std::cout << std::endl;

    // Pop element from the front of A and push it in the back of A
    temp = *A.begin();
    A.push_back(temp);
    A.pop_front();

    // Pop element from the front of B and push it in the back of B
    temp = *B.begin();
    B.push_back(temp);
    B.pop_front();

    // Output list A into stdout
    for (std::list<int>::iterator it = A.begin(); it != A.end(); it++) {
		if (it == A.begin())
			std::cout << *it;
		else std::cout << "," << *it;
	}
    std::cout << std::endl;

    // Output list B into stdout
    for (std::list<int>::iterator it = B.begin(); it != B.end(); it++) {
		if (it == B.begin())
			std::cout << *it;
		else std::cout << "," << *it;
	}

    // Output newline in stdout
    std::cout << std::endl;

    // Merge list B into list A and sort A
    A.merge(B);
    A.sort();

    // Output the list A (now merged with B) into stdout
    for (std::list<int>::iterator it = A.begin(); it != A.end(); it++) {
		if (it == A.begin())
			std::cout << *it;
		else std::cout << " " << *it;
	}

	std::cout << std::endl;

	return 0;
}