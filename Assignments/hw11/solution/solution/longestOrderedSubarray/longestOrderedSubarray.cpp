/*
	CH-231-A
	hw11_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <algorithm>

bool Longest(const std::vector<int> &first, const std::vector<int> &second) {
   return first.size() < second.size();
}

std::vector<int> LOS(std::vector<int> sequence) {
    int size = (int) sequence.size();

    // Dynamic Programming Table to store solutions to previous subproblems
    std::vector<std::vector<int>> dp(size);

    // Store the first subarray which is only the first element
    dp[0].push_back(sequence[0]);

    // Build upon the first subarray to find solutions to other subproblems
    for (int i = 1; i < size; ++i) {
        // Build subarray out of solved subproblems for the current i
        for (int j = 0; j < i; ++j) {
            // Check if number at position j can be added and the size of
            // the subproblem solved for subarray up to position j is bigger
            // than the one we have already built upon now
            if ((sequence[i] > sequence[j]) && (dp[i].size() < dp[j].size()))
                // Set the solution to the subproblem of the subarray up to
                // i to the subproblem of the subarray up to j when the size
                // of subproblem j is bigger than subproblem i we already know
                dp[i] = dp[j];
        }
        // Subproblem solved for subarray up to position i will involve the 
        // element at position i
        dp[i].push_back(sequence[i]);
    }

    // Find the biggest subarray in dp using comparator based on vector size
    std::vector<std::vector<int>>::iterator los = std::max_element(
        dp.begin(), dp.end(), Longest
    );

    return *los;
}

int main() {
    int input;
    std::vector<int> sequence;

    // Retrieve input until input given is negative integer
    std::cin >> input;
    while (input > -1) {
        sequence.push_back(input);
        std::cin >> input;
    }

    // Find the Longest Ordered Subarray from the sequence inputted
    std::vector<int> los = LOS(sequence);

    // Output each element of LOS
    for (int element : los)
        std::cout << element << " ";
    std::cout << std::endl;

    return 0;
}