/*
	CH-231-A
	hw10_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include "Activity.h"

int main() {
	std::vector<Activity> list = {
		Activity(1, 4),
		Activity(3, 5),
		Activity(0, 6),
		Activity(5, 7),
		Activity(3, 9),
		Activity(5, 9),
		Activity(6, 10),
		Activity(8, 11),
		Activity(8, 12),
		Activity(2, 14),
		Activity(12, 16)
	};
	
	std::vector<Activity> solution = greedyActivitySelector(list);

	std::cout << "Optimal solution set of activities:" << std::endl;
	for (Activity activity: solution)
		std::cout << activity << std::endl;

    return 0;
}