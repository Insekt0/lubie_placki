#ifndef SudokuGenerator_h
#define SudokuGenerator_h

#include "Common.h"

class SudokuGenerator {
public:
    void generate(int* sudokuArray, COMPLEXITY_LEVELS complexity_level);
    void readFromFile(int* sudokuArray);
    void saveToFile(int* sudokuArray);
};


#endif // SudokuGenerator_h