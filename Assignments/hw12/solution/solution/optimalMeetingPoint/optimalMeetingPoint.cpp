/*
	CH-231-A
	hw12_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int INF = 1061109567;   // 0x3f3f3f3f

class City {
	public:
		int cityID;
		int yourCityDistance;
		int friendCityDistance;
		int profitableDistance;
		bool visited;

		// City constructor
		City() {
			// Set its cityID to 0 initially, each distance to INFINITY and
			// visited to false as it hasn't yet been discovered
			this->cityID = 0;
			this->yourCityDistance = INF;
			this->friendCityDistance = INF;
			this->profitableDistance = INF;
			this->visited = false;
		}

		// Set the distance the algorithm is trying to minimize
		void setDistance(int distance) {
			// Check if city has been visited before
			// Second Dijkstra run
			if (visited == true) {
				// Calculate the maximum between the both shortest paths coming
				// from both cities: max(x, y)
				this->friendCityDistance = distance;
				if (this->friendCityDistance > this->yourCityDistance)
					this->profitableDistance = this->friendCityDistance;
				else this->profitableDistance = this->yourCityDistance;
			} else 
				// Set the distance from your_city as first Dijkstra is running
				// Graph has yet to be fully discovered
				this->yourCityDistance = distance;
		}

		// Overload (Definition) of less than operator for comparison between
		// two cities
        friend bool operator<(City firstCity, City secondCity) {
			// Check if city has been visited before
			// Second Dijkstra run
            if (firstCity.visited == true)
				// Order based on distance from friend_city
                return firstCity.friendCityDistance < secondCity.friendCityDistance;
            else
				// Order based on distance from your_city
				return firstCity.yourCityDistance < secondCity.yourCityDistance;
        }
};

int find_meetup_city(std::vector<std::vector<int>> adj_matrix, int your_city, 
					 int friend_city) {
	int distance;
	std::priority_queue<City> Q;
	std::vector<City> cities((int) adj_matrix.size());

	// Appoint identification numbers to each city
	for (int i = 0; i < (int) adj_matrix.size(); ++i)
		cities[i].cityID = i;

	// First Dijkstra Run
	// Set distance from your_city to itself to 0 (initial starting node)
	cities[your_city].setDistance(0);
	// Place your_city into the queue
	Q.push(cities[your_city]);
	City currentCity;

	// Iterate until the queue is empty
	while (!Q.empty()) {
		// Pop from the queue and save the city
		currentCity = Q.top();
		Q.pop();

		// Iterate through all the cities
		for (int i = 0; i < (int) adj_matrix.size(); ++i) {
			// Check for self loops and existence of edge
			if ((i != currentCity.cityID) && 
				(adj_matrix[currentCity.cityID][i])) {
				// Calculate distance from your_city to the previous city
				// summed up with the distance to the current city
				distance = currentCity.yourCityDistance + adj_matrix[currentCity.cityID][i];
				// Check if the calculated distance is smaller than the 
				// currently shortest path to this city
				if (distance < cities[i].yourCityDistance) {
					// Set the new shortest distance accordingly
					cities[i].setDistance(distance);
					// Push this city with new distance onto the queue
					Q.push(cities[i]);
				}
			}
		}
	}

	// Set visited to true for each city after first run of Dijkstra
	for (int i = 0; i < (int) adj_matrix.size(); ++i)
		cities[i].visited = true;

	// Second Dijkstra Run
	// Set distance from friend_city to itself to 0 (initial starting node)
	cities[friend_city].setDistance(0);
	// Place friend_city into the queue
	Q.push(cities[friend_city]);

	// Iterate until the queue is empty
	while (!Q.empty()) {
		// Pop from the queue and save the city
		currentCity = Q.top();
		Q.pop();

		// Iterate through all the cities
		for (int i = 0; i < (int) adj_matrix.size(); ++i) {
			// Check for self loops and existence of edge
			if ((i != currentCity.cityID) && 
				(adj_matrix[currentCity.cityID][i])) {
				// Calculate distance from friend_city to the previous city
				// summed up with the distance to the current city
				distance = currentCity.friendCityDistance + adj_matrix[currentCity.cityID][i];
				// Check if the calculated distance is smaller than the 
				// currently shortest path to this city
				if (distance < cities[i].friendCityDistance) {
					// Set the new shortest distance accordingly
					cities[i].setDistance(distance);
					// Push this city with new distance onto the queue
					Q.push(cities[i]);
				}
			}
		}
	}

	// Minimization step to find the optimal meetup min(max(x, y))
	// Start from the friend_city
	int meetupCity = friend_city;
	// Set the initial minimum to the distance of friend_city from your_city
	int profitableDistance = cities[meetupCity].profitableDistance;
	// Iterate through each city
	for (int i = 0; i < (int) adj_matrix.size(); ++i)
		// Check if city offers a more optimal meeting city for both
		if (cities[i].profitableDistance < profitableDistance) {
			// Save the new optimal distance
			profitableDistance = cities[i].profitableDistance;
			// Save the ID of the optimal meeting city
			meetupCity = i;
		}
	
	return meetupCity;
}

int main() {
	int numberOfCities, numberOfRoads, your_city, friend_city, from, to, dist;

	// Input the number of nodes and edges, in this case, cities and roads
	std::cin >> numberOfCities >> numberOfRoads;

	// Create an adjacency matrix for the graph with 
	// numberOfCities x numberOfCities dimension
	std::vector<std::vector<int>> adj_matrix(
		numberOfCities, std::vector<int>(numberOfCities, INF)
	);

	// Input each edge between the nodes and treat it as an undirected edge
	for (int i = 0; i < numberOfRoads; ++i) {
		std::cin >> from >> to >> dist;
		adj_matrix[from][to] = adj_matrix[to][from] = dist;
	}

	// Input the cities between which the optimal meeting point should be found
	std::cin >> your_city >> friend_city;		

	// Output the ID of the city where they should meet up
	std::cout << "Optimal Meeting Point: "
			  << find_meetup_city(adj_matrix, your_city, friend_city) 
			  << std::endl;

    return 0;
}