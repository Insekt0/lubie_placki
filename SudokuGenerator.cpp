#include "SudokuGenerator.h"
#include <fstream>

void SudokuGenerator::generate(int* sudokuArray, COMPLEXITY_LEVELS complexity_level) {
    // TODO
}

void SudokuGenerator::readFromFile(int* sudokuArray) {
    ifstream myfile;
    myfile.open("sudoku.txt");
    int value;
    int counter = 0;
    while(myfile >> value)
        sudokuArray[counter++] = value;
}
    
void SudokuGenerator::saveToFile(int* sudokuArray) {
    ofstream myfile;
    myfile.open("result.txt");
    for (int i = 0; i < 81; ++i)
    {
        myfile << sudokuArray[i] << " ";
        if(i%9 == 8)
            myfile << "\n";
    }
    myfile.close();
}