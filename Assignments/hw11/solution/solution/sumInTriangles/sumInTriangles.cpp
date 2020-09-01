/*
	CH-231-A
	hw11_p2.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <vector>

enum Choice {Left, Right};

std::vector<int> reconstructPath(std::vector<std::vector<int>> &input,
								 std::vector<std::vector<Choice>> &paths) {
	int pathLocation = 0;
	std::vector<int> path;

	// Traverse each level from the top to reconstruct path from the Choices
	for (int i = 0; i < (int) input.size(); ++i) {
		path.push_back(input[i][pathLocation]);
		// Move on the column to the right if Choice is Right for the next read
		if (paths[i][pathLocation] == Right)
			pathLocation++;
	}

	return path;
}

int SIT(std::vector<std::vector<int>> dp,
		std::vector<std::vector<Choice>> &paths) {
	// Solve subproblems starting from the second to last row and build upon
	// these subproblems while going towards the top
	for (int i = (int) dp.size() - 2; i > -1; --i) {
		// Calculate the maximum path of element j in row i based on the maximum
		// value of the paths of the elements on row i+1, and columns j and j+1
		for (int j = 0; j <= i; ++j) {
			// Check if left path has strictly bigger sum than the one on the 
			// right and set the Choice for element in paths depending on it
			if (dp[i + 1][j] > dp[i + 1][j + 1])
				dp[i][j] = dp[i][j] + dp[i + 1][j];
			else dp[i][j] = dp[i][j] + dp[i + 1][j + 1];
			paths[i][j] = dp[i + 1][j] > dp[i + 1][j + 1] ? Left : Right;
		}
	}

	return dp[0][0];
}

int main() {
    int in, row = 0, column = 0, sum = 0;
	std::vector<std::vector<int>> input;
	std::vector<std::vector<Choice>> paths;
	std::vector<int> path, empty;
	std::vector<Choice> emptyChoices;

	// Initialize input and path matrix with empty vectors
	input.push_back(empty);
	paths.push_back(emptyChoices);

	// Insert into input matrix and create paths matrix accordingly
	std::cin >> in;
	while (in > -1 && in < 10001) {
		if (column > row) {
			column = 0;
			input.push_back(empty);
			paths.push_back(emptyChoices);
			row++;
		}
		input[row].push_back(in);
		paths[row].push_back({});
		std::cin >> in;
		column++;
	}

	// Calculate biggest sum and its corresponding path by reconstructing
	sum = SIT(input, paths);
	path = reconstructPath(input, paths);

	// Output the sum and the elements of the path
	std::cout << sum << std::endl;
	for (int element : path)
		std::cout << element << " ";
	std::cout << std::endl;

    return 0;
}