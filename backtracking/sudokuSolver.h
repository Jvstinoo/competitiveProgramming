#include <iostream>
#include <bits/stdc++.h>


struct Square {
    int row;
    int col;
    int val;
    int usedOptions[9];
    bool possibleOption;
};

class SudokuSolver {
    public:
        SudokuSolver() {
            grid = parseInput();
        }
        void solver(int start_row, int start_column);
        void printGrid();
    private:
        std::unordered_map<int, Square[9]> parseInput();
        bool getOption(Square &sq);
        bool inRow(Square &sq, int possibleOption);
        bool inColumn(Square &sq, int possibleOption);
        bool inGrid(Square &sq, int possibleOption);
        std::unordered_map<int, Square[9]> grid;
        std::stack<Square*> changed_squares;
};
