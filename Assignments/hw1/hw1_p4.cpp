/*
	CH-231-A
	hw1_p4.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <vector>

int main() {
	std::string temp;
	std::vector<std::string> wordVector;
	std::cin >> temp;

	// Push back each word into vector each word until END is inputted
	while (temp.compare("END") != 0) {
		wordVector.push_back(temp);
		std::cin >> temp;
	}

	// Loop through the vector and output the words using index operator
	if (!wordVector.empty())
		for (unsigned int i = 0; i < wordVector.size(); i++) {
			// Group the separator before the element when index is not 0
			// Although not needed in case of " "
			if (i == 0)
				std::cout << wordVector[i];
			else std::cout << " " << wordVector[i];
		}
	std::cout << std::endl;

	// Set a mark variable at the beginning of the vector
	std::vector<std::string>::iterator begin = wordVector.begin();

	// Iterate through the vector using iterator and output using dereferencing
	if (!wordVector.empty())
		for (std::vector<std::string>::iterator it = wordVector.begin();
				it != wordVector.end(); it++) {
			// Group the separator before the element when index is not 0
			if (it == begin)
				std::cout << *it;
			else std::cout << "," << *it;
		}
	std::cout << std::endl;
	
	return 0;
}