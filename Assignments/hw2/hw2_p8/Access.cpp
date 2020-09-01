/*
	CH-231-A
	hw2_p8.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "Access.h"

void Access::activate(unsigned int code, unsigned int level) {
	std::map<unsigned int, unsigned int>::iterator it;
	// Activate code only if it hasn't already been activated
	for (it = this->codes.begin(); it != this->codes.end(); it++)
		if ((*it).first == code && (*it).second == level) {
			std::cout << "Code is already active!" << std::endl;
			return;
		} else if ((*it).first == code && (*it).second != level) {
			this->codes.erase(code);
			this->codes.insert(
				std::pair<unsigned int, unsigned int>(code, level)
			);
			std::cout << "Updated code with new access level!" << std::endl;
			return;
		}
	this->codes.insert(std::pair<unsigned int, unsigned int>(code, level));
}

void Access::deactivate(unsigned int code) {
	std::map<unsigned int, unsigned int>::iterator it;
	it = this->codes.find(code);
	// Deactivate code if code is found in codes map
	if (it != this->codes.end())
		this->codes.erase(code);
	else std::cout << "Code can't be deactivated as it isn't active!" 
				   << std::endl;
}

bool Access::isactive(unsigned int code, unsigned int level) const {
	std::map<unsigned int, unsigned int>::const_iterator it;
	// Check through codes to see if code is there and its access level is
	// higher than the door level
	for (it = this->codes.begin(); it != this->codes.end(); it++)
		if ((*it).first == code && this->codes.at((*it).first) >= level)
			return true;
	return false;
}