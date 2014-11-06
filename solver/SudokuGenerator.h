#ifndef SudokuGenerator_h
#define SudokuGenerator_h

#include "Common.h"

class SudokuGenerator {
public:
    void generate(int* sudokuArray, COMPLEXITY_LEVELS LEVEL);
    void readFromFile(int* sudokuArray, string filename);
    void saveToFile(int* sudokuArray);
    void printSudoku(int* sudokuArray, string name, int* baseArray = 0);
};


#endif // SudokuGenerator_h