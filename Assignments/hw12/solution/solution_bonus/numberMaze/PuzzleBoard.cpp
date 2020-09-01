/*
	CH-231-A
	hw12_p3.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include "PuzzleBoard.h"

const int INF = 1061109567;   // 0x3f3f3f3f

PuzzleBoard::PuzzleBoard(int boardSize, int **fields) {
	// Set dummy field to create initial board
	Field blankField;
	blankField.step = 0;
	blankField.steps = INF;
	blankField.xPos = 0;
	blankField.yPos = 0;

	// Set boardSize and initial position
	this->boardSize = boardSize;
	this->xPos = 0;
	this->yPos = 0;

	// Check if input matrix was NULL
	if (fields == NULL) {
		// Generate fields of the puzzle board by choosing random steps
		std::srand(time(0));
		for (int i = 0; i < this->boardSize; ++i) {
			// Fill a vector with Field objects with random step sizes
			std::vector<Field> row(this->boardSize, blankField);
			for (int j = 0; j < this->boardSize; ++j) {
				row[j].step = (std::rand() % (this->boardSize - 1)) + 1;
				row[j].xPos = i;
				row[j].yPos = j;
			}
			this->fields.push_back(row);
		}
	} else {
		// Fill fields of the puzzle board using the input matrix
		for (int i = 0; i < this->boardSize; ++i) {
			// Fill a vector with Field objects with steps sizes defined
			// in input matrix
			std::vector<Field> row(this->boardSize, blankField);
			for (int j = 0; j < this->boardSize; ++j) {
				row[j].step = fields[i][j];
				row[j].xPos = i;
				row[j].yPos = j;
			}
			this->fields.push_back(row);
		}
	}
}

bool PuzzleBoard::makeMove(int direction) {
	int newxPos, newyPos;

	// Calculate new position to jump to based on direction given and step
	switch(direction) {
		case 0:
			// Direction UP (Lower x pos)
			newxPos = this->xPos - this->fields[xPos][yPos].step;
			newyPos = this->yPos;
			break;
		case 1:
			// Direction RIGHT (Higher y pos)
			newxPos = this->xPos;
			newyPos = this->yPos + this->fields[xPos][yPos].step;
			break;
		case 2:
			// Direction DOWN (Higher x pos)
			newxPos = this->xPos + this->fields[xPos][yPos].step;
			newyPos = this->yPos;
			break;
		case 3:
			// Direction LEFT (Lower y pos)
			newxPos = this->xPos;
			newyPos = this->yPos - this->fields[xPos][yPos].step;
			break;
		default:
			return false;
	}

	// Check if the new calculated position after the jump is valid
	if (isValidPos(newxPos, newyPos)) {
		// Check if the number of steps to the new calculated jump position
		// is bigger than the number of steps taken from the current position
		if (this->fields[newxPos][newyPos].steps > 
			this->fields[this->xPos][this->yPos].steps + 1) {
			// Update steps taken to arrive at this position on the board
			this->fields[newxPos][newyPos].steps = this->fields[this->xPos][this->yPos].steps + 1;
			this->xPos = newxPos;
			this->yPos = newyPos;
			return true;
		}
	} else return false;

	return false;
}

bool PuzzleBoard::getResult() {
	// Check if position on the board is the bottom right corner
	if ((this->xPos == this->boardSize - 1) && (this->yPos == this->boardSize - 1))
		// Return true as game is over when position is the bottom right corner
		return true;
	// Return false as the game isn't over when position is not on the bottom
	// right corner
	else return false;
}

std::ostream& operator<<(std::ostream &os, PuzzleBoard const &m) {
	// Output the puzzle board into outstream
	for (int i = 0; i < m.boardSize; ++i) {
		for (int j = 0; j < m.boardSize; ++j)
			os << m.fields[i][j].step << " ";
		os << std::endl;
	}
	return os;
}

int PuzzleBoard::solve() {
	int n = this->boardSize;

	// Run Dijkstra's algorithm on the puzzle board
	// Set the initial position at the upper left corner of the board
	this->fields[0][0].steps = 0;
	std::priority_queue<Field> Q;
	// Push first Field onto the queue
	Q.push(this->fields[0][0]);
	Field currentField;

	while (!Q.empty()) {
		// Pop from the queue one Field and save its properties
		currentField = Q.top();
		Q.pop();
		// Change the current xPos and yPos to the popped Field
		this->xPos = currentField.xPos;
		this->yPos = currentField.yPos;

		// Calculate new positions from jumping in all 4 directions starting
		// from current Field
		for (int i  = 0; i < 4; ++i) {
			// Check and make a move if possible to be performed in direction i
			if (makeMove(i)) {
				// Push Field at newly calculated xPos and yPos
				Q.push(fields[this->xPos][this->yPos]);
				this->xPos = currentField.xPos;
				this->yPos = currentField.yPos;
			}
		}
	}
	// Return -1 if no solution was found, otherwise return number of steps 
	// taken to arrive at bottom right corner of the puzzle board
	return (this->fields[n - 1][n - 1].steps == INF) ? -1 : this->fields[n - 1][n - 1].steps;
}

bool PuzzleBoard::isValidPos(int xPos, int yPos) {
	// Check if xPos or yPos are smaller than 0 or bigger or equal to boardSize
	if ((xPos < 0) || (yPos < 0) || (xPos >= this->boardSize) ||
		(yPos >= this->boardSize))
		// Return false as position is not valid
		return false;
	else return true;
}