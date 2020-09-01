/*
	CH-231-A
	hw12_p3.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <iostream>
#include <algorithm>
#include <ctime>
#include "PuzzleBoard.h"

const int INF = 1061109567;   // 0x3f3f3f3f

int main () {
    bool generateRandom;
    int boardSize, solution;
    int **fields;

    std::cout << "Enter the puzzle board size: ";
    std::cin >> boardSize;

    std::cout << "Generate random puzzle board or input one (1/0): ";
    std::cin >> generateRandom;

    if (generateRandom) {
        PuzzleBoard board(boardSize);
        std::cout << board;
        solution = board.solve();
    } else {
        fields = new int*[boardSize];
        if (fields == nullptr) {
            std::cout << "Incorrect Memory Allocation!" << std::endl;
            return 0;
        }

        for (int i = 0; i < boardSize; ++i) {
            fields[i] = new int[boardSize];
            if (fields[i] == nullptr) {
                std::cout << "Incorrect Memory Allocation!" << std::endl;
                return 0;
            }
            for (int j = 0; j < boardSize; ++j)
                std::cin >> fields[i][j];
        }
        PuzzleBoard board(boardSize, fields);
        std::cout << board;
        solution = board.solve();
    }

    if (solution == -1)
        std::cout << "There is no solution for this Puzzle Board!" << std::endl;
    else std::cout << "Minimum number of steps for the solution is: "
                   << solution
                   << std::endl;
    
    return 0;
}