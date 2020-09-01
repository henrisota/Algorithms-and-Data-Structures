/*
	CH-231-A
	hw2_p7.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <map>

int main() {
	std::string firstName, lastName, birthDate, input;
	std::map<std::string, std::string> collection;
	std::fstream file("data.txt", std::ios::in);

	if (!file.good()) {
		std::cerr << "File was not opened correctly!" << std::endl;
		exit(1);
	}

	// Read each first name, last name and birthdate from data.txt and save it
	// to collection map
	if (file.is_open())
		while (!file.eof()) {
			file >> firstName >> lastName >> birthDate;
			collection[firstName + " " + lastName] = birthDate;		
		}
	
	while (true) {
		std::cout << "Enter a name or Exit to close the program: ";
		std::getline(std::cin, input);

		// Check if user wants to exit the program
		if (input == "Exit")
			break;
		else {
			// Check if input is in collection
			if (collection.find(input) != collection.end())
				// Output the value based on the key which is input
				std::cout << collection[input] << std::endl;
			else std::cout << "Name not found!" << std::endl;
		}
	}
	
	file.close();

    return 0;
}