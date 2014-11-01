#include "SudokuGenerator.h"
#include <fstream>

void SudokuGenerator::generate(int* sudokuArray, COMPLEXITY_LEVELS complexity_level) {
    // TODO
}

void SudokuGenerator::readFromFile(int* sudokuArray, string filename) {
    ifstream myfile;
    myfile.open(filename);
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

void SudokuGenerator::printSudoku(int* sudokuArray, string name) {
    
    cout << "\n    Sudoku: " << name;
    for (int i = 0; i < 81; ++i)
    {
        if(i%9 == 0)
            cout << endl;
        if(i%27 == 0)
            cout << " -----------------------" << endl;
        
        if(i%3 == 0)
            cout << "| ";
        cout << sudokuArray[i] << " ";

        if(i%9 == 8)
            cout << "|";
        if(i == 80)
            cout << "\n -----------------------" << endl;
    }

}