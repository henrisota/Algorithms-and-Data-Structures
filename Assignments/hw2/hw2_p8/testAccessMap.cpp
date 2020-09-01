/*
	CH-231-A
	hw2_p8.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "Access.h"

int main() {
    unsigned int code;
    Access codes;

    // Activate codes
    codes.activate(1234, 1);
    codes.activate(9999, 5);
    codes.activate(9876, 9);    

    // Input code and test if it is correct (active) with access level 5
    while (true) {
        std::cout << "Enter the code: ";
        std::cin >> code;
        if (codes.isactive(code, 5)) {
            std::cout << "Door opened successfully!" << std::endl;
            break;
        } else std::cout << "Incorrect code entered or access denied!"
                         << std::endl;
    }

    // Deactivate code found, update code 9999 with access level 8 and place new
    // code 1111 with access level 7
    codes.deactivate(code);
    codes.activate(9999, 8);
    codes.activate(1111, 7);

    // Input code and test if it is correct (active) with new codes
    while (true) {
        std::cout << "Enter the code: ";
        std::cin >> code;
        if (codes.isactive(code, 7)) {
            std::cout << "Door opened successfully!" << std::endl;
            break;
        } else std::cout << "Incorrect code entered!" << std::endl;
    }
    
	return 0;
}