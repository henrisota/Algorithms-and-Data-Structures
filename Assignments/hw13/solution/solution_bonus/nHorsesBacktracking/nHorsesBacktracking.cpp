/*
	CH-231-A
	hw13_p1.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <vector>

// Global variable to hold the number of solutions
int solutions;

// Function to check if position (xPos, yPos) is empty or not under attack
bool checkPosition(std::vector<std::vector<char>> &board, int xPos, int yPos);


// Function to mark positions that horse at position (xPos, yPos) can attack
void setAttackPositions(std::vector<std::vector<char>> &board, char mark,
						int xPos, int yPos);

// Function to check if position (xPos, yPos) is valid (inside the board)
bool isValidPos(int xPos, int yPos, int boardSize);

// Function to find the possible solutions of placing n horses on a n x n board
// starting from the given position (xInit, yInit) on a board (marked or not)
void solve(std::vector<std::vector<char>> board, int n, int xInit, int yInit);

// Function to output the board onto stdout
void printBoard(std::vector<std::vector<char>> board);

int main() {
	int n;

	std::cout << "Enter the size of the chessboard: ";
	std::cin >> n;

	solutions = 0;

	// Create a n x n chessboard with empty positions marked by '_'
	std::vector<std::vector<char>> board(n, std::vector<char>(n, '_'));

	// Output the setup of the board
	for (int i = 0; i < (int) board.size(); ++i) {
		for (int j = 0; j < (int) board.size(); ++j)
			std::cout << board[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// Calculate the possible solutions for placing n horses on a n x n board
	solve(board, n, 0, 0);

	std::cout << "There are " << solutions << " different combinations"
			  << " for placing " << n << " horses on a "
			  << n << "x" << n << " board."
			  << std::endl;

    return 0;
}

bool checkPosition(std::vector<std::vector<char>> &board, int xPos, int yPos) {
	// Check if position is available (empty or not yet under attack) and return
	// accordingly
	return (board[xPos][yPos] == '_');
}

void setAttackPositions(std::vector<std::vector<char>> &board, char mark,
						int xPos, int yPos) {
	/*
		Possible attack positions for a horse respective to its position
		-----------
		| |#| |#| |
		|#| | | |#|
		| | |H| | |
		|#| | | |#|
		| |#| |#| |
		-----------
	*/
	// Creating vector of attack position for the horse
	std::vector<std::pair<int, int>> attackPositions = {
		{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, 1}
	};
	// Iterate through all different attack positions
	for (std::pair<int, int> attackPosition : attackPositions) {
		// Calculate absolute position of attack from referencing position of 
		// horse on the board
		int newxPos = xPos + attackPosition.first;
		int newyPos = yPos + attackPosition.second;
		// Check if attack position is inside the board
		if (isValidPos(newxPos, newyPos, (int) board.size()))
			// Mark the position of attack
			board[newxPos][newyPos] = mark;
	}
}

bool isValidPos(int xPos, int yPos, int boardSize) {
	// Check if given position is inside the board
	if ((xPos < 0) || (yPos < 0) || (xPos >= boardSize) || (yPos >= boardSize))
		return false;
	else return true;
}

void solve(std::vector<std::vector<char>> board, int n, int xInit, int yInit) {
	// Check if n is 0 (All possible horses have been placed correctly)
	if (n == 0) {
		// Solution has been found, therefore print the board
		// Comment line in case only number of solutions is wanted
		printBoard(board);

		solutions++;
		return;
	}
	// Iterate through the board starting from position (xInit, yInit) until
	// position (boardSize - 1, boardSize - 1)
	for (int i = xInit; i < (int) board.size(); ++i) {
		for (int j = yInit; j < (int) board.size(); ++j) {
			// Check if position (i, j) is empty or not under attack on board
			if (checkPosition(board, i, j)) {
				// Copy board to try to find solutions for placing a horse
				// on position (i, j)
				std::vector<std::vector<char>> testBoard = board;
				// Place horse on the empty position
				testBoard[i][j] = 'H';
				// Place positions under attack after placing the new horse
				setAttackPositions(testBoard, '*', i, j);
				// Find solutions (if any) to place the leftover n - 1
				// horses in the positions after (i, j)
				solve(testBoard, n - 1, i, j);
			}
		}
		// Set the yInit to 0 after checking the first row (and other rows),
		// in order to all leftover positions
		yInit = 0;
	}
}

void printBoard(std::vector<std::vector<char>> board) {
	// Output solution
	std::cout << "Solution " << solutions + 1 << ":" << std::endl;
	// Output board onto stdout
	for (int i = 0; i < (int) board.size(); ++i) {
		for (int j = 0; j < (int) board.size(); ++j)
			std::cout << board[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}