/*
	CH-231-A
	hw12_p3.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#ifndef PUZZLEBOARD_H_
#define PUZZLEBOARD_H_
#include <iostream>
#include <fstream>
#include <vector>

class Field {
    public:
        int xPos;
        int yPos;
        int step;
        int steps;

        friend bool operator<(Field firstField, Field secondField) {
            return (firstField.steps < secondField.steps);
        }
};

class PuzzleBoard {
    private:
        int boardSize;
        int xPos;
        int yPos;
        std::vector<std::vector<Field>> fields;

    public:
        // Subpoint (b)

        // Constructor of PuzzleBoard based on values from fields parameter
        // If fields is null, then it initializes the fields of the board with
        // random values between 1 and boardSize-1
        PuzzleBoard(int boardSize, int **fields = NULL);

        // Make the move (if valid), where direction is 0 for up, 1 for right,
        // 2 for down, 3 for left. Returns true if the move was valid, false
        // otherwise.
        bool makeMove(int direction);

        // Returns false if game is not over yet, true if puzzle was solved
        bool getResult();

        // Outputs the PuzzleBoard onto out stream
        friend std::ostream &operator<<(std::ostream &os, PuzzleBoard const &m);

        // Subpoint (c)

        // Returns the minimum number of moves needed to solve the puzzle, and 
        // -1 if it is not solvable
        int solve();

        // Helper Methods
        // Return true if the position given is inside the bounds of the board
        // otherwise false
        bool isValidPos(int xPos, int yPos);
};
#endif /* PUZZLEBOARD_H_ */