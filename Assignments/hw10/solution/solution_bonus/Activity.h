/*
	CH-231-A
	hw10_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#ifndef ACTIVITY_H_
#define ACTIVITY_H_
#include <vector>

class Activity {
    private:
        int start;
        int end;
    public:
        // Parametrized constructor
        Activity(int start, int end);

        // Friend functions
        // Function to find the latest starting time activity in the list
        friend int findLatest(const std::vector<Activity> &list);
        // Function to output a Activity object properties on the output stream
        friend std::ostream& operator<<(std::ostream &out, const Activity &a);
        friend std::vector<Activity> greedyActivitySelector(
            std::vector<Activity> list
        );
};

#endif /* ACTIVITY_H_ */