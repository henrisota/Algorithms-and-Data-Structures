/*
	CH-231-A
	hw10_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include "Activity.h"

Activity::Activity(int start, int end) {
	// Construct activity object with start and end parameter provided
	this->start = start;
	this->end = end;
}

int findLatest(const std::vector<Activity> &list) {
	int position = 0;
	Activity latestStartingActivity = list[0];
	// Search through the array for the interval with the latest starting time
	for (int i = 0; i < (int) list.size(); ++i)
		// Check if the starting time of activity is later than the current
		// we know of
		if (list[i].start > latestStartingActivity.start) {
			latestStartingActivity = list[i];
			position = i;
		}
	// Return the position of the latest starting activity of the list
	return position;
}

std::ostream& operator<<(std::ostream &out, const Activity &a) {
	// Output the properties of a Activity object in format
	// (start,end)
	out << "(" << a.start << "," << a.end << ")";
	return out;
}

std::vector<Activity> greedyActivitySelector(std::vector<Activity> list) {
	std::vector<Activity> optimalSelection;
	std::vector<Activity> activitiesLeft = list;

	// Find the first latest activity of the given list
	int latestActivityPosition = findLatest(list);
	// Remove the latest activity of the list from the activitiesLeft vector
	activitiesLeft.erase(activitiesLeft.begin() + latestActivityPosition);
	// Push the latest activity of the list into the optimal solution vector
	optimalSelection.push_back(list[latestActivityPosition]);
	
	// Search the activitiesLeft vector until it has no elements left
	while ((int) activitiesLeft.size() != 0) {
		// Find the latest activity of the activitiesLeft vector
		latestActivityPosition = findLatest(activitiesLeft);
		// Save the activity by copying it from the activitiesLeft vector
		Activity latest = activitiesLeft[latestActivityPosition];
		// Remove the last activity from the activitiesLeft vector
		activitiesLeft.erase(activitiesLeft.begin() + latestActivityPosition);

		// Check if the activity that has just been chosen as the latest is
		// compatible with the last activity added on the optimal solution
		if (latest.end <= optimalSelection[optimalSelection.size() - 1].start)
			// Add the activity to the optimal solution if it is non-conflicting
			// with the previously added one
			optimalSelection.push_back(latest);
	}

	return optimalSelection;
}