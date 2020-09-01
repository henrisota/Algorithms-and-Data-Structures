/*
	CH-231-A
	hw2_p3.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <climits>
#include "WindGauge.h"

WindGauge::WindGauge(int period) {
	this->period = period;
}

void WindGauge::currentWindSpeed(int speed) {
	// Check if the number of values has reached number of periods allowed
	if ((int) this->history.size() == this->period)
		// Remove the value added first in the current state of the deque
		this->history.pop_back();
	// Place new value of wind speed into container
	this->history.push_front(speed);
}

int WindGauge::highest() const {
	int max = INT_MIN;
	// Find maximum wind speed value by iterating through the whole history
	for (std::deque<int>::const_iterator it = this->history.begin();
		 it != this->history.end(); it++)
		if (*it > max)
			max = *it;
	return max;
}

int WindGauge::lowest() const {
	int min = INT_MAX;
	// Find minimum wind speed value by iterating through the whole history
	for (std::deque<int>::const_iterator it = this->history.begin();
		 it != this->history.end(); it++)
		if (*it < min)
			min = *it;
	return min;
}

int WindGauge::average() const {
	int average = 0;
	// Find average wind speed value by iterating through the whole history,
	// summing up all the values and ultimately dividing by the number of 
	// values in the history currently
	for (std::deque<int>::const_iterator it = this->history.begin();
		 it != this->history.end(); it++)
		average += *it;
	return (average / this->history.size());
}

void WindGauge::dump() const {
	// Dump lowest, highest, and average wind speed into stdout
	std::cout << "Lowest wind speed: "
			  << this->lowest()
			  << std::endl
			  << "Highest wind speed: "
			  << this->highest()
			  << std::endl
			  << "Average wind speed: "
			  << this->average()
			  << std::endl;
}