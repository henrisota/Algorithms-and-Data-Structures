/*
	CH-231-A
	hw2_p6.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "Access.h"

int main() {
    unsigned int code;
    Access codes;

    // Activate codes
    codes.activate(1234);
    codes.activate(9999);
    codes.activate(9876);    

    // Input code and test if it is correct (active)
    while (true) {
        std::cout << "Enter the code: ";
        std::cin >> code;
        if (codes.isactive(code)) {
            std::cout << "Door opened successfully!" << std::endl;
            break;
        } else std::cout << "Incorrect code entered!" << std::endl;
    }

    // Deactivate code found and 9999, and activate code 1111
    codes.deactivate(code);
    codes.deactivate(9999);
    codes.activate(1111);

    // Input code and test if it is correct (active) with new codes
    while (true) {
        std::cout << "Enter the code: ";
        std::cin >> code;
        if (codes.isactive(code)) {
            std::cout << "Door opened successfully!" << std::endl;
            break;
        } else std::cout << "Incorrect code entered!" << std::endl;
    }
    
	return 0;
}