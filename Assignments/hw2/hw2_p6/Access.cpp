/*
	CH-231-A
	hw2_p6.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "Access.h"

void Access::activate(unsigned int code) {
	std::set<unsigned int>::iterator it;
	// Activate code only if it hasn't already been activated
	for (it = this->codes.begin(); it != this->codes.end(); it++)
		if (*it == code) {
			std::cout << "Code is already active!" << std::endl;
			return;
		}
	this->codes.insert(code);
}

void Access::deactivate(unsigned int code) {
	std::set<unsigned int>::iterator it;
	it = this->codes.find(code);
	// Deactivate code if code is found in codes set
	if (it != this->codes.end())
		this->codes.erase(code);
	else std::cout << "Code can't be deactivated as it isn't active!" 
				   << std::endl;
}

bool Access::isactive(unsigned int code) const {
	std::set<unsigned int>::iterator it;
	// Check through codes to see if code is in there and return accordingly
	for (it = this->codes.begin(); it != this->codes.end(); it++)
		if (*it == code)
			return true;
	return false;
}