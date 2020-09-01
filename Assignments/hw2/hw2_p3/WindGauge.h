/*
	CH-231-A
	hw2_p3.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <deque>

class WindGauge {
    public:
        // Constructor
        WindGauge(int period = 12);
        // Method to place new value of speed into history of values
        void currentWindSpeed(int speed);
        // Method to return the highest value in the history of wind speeds
        int highest() const;
        // Method to return the lowest value in the history of wind speeds
        int lowest() const;
        // Method to return the average value of the wind speeds in history
        int average() const;

        // dump() method implemented under public access due to not being able
        // to access other methods and properties
        void dump() const; 

    private:
        // Container for wind speed values
        std::deque<int> history;
        // Integer to store the number of periods in an hour
        int period;
};