#include <iostream>
#include "Common.h"
#include "SudokuGenerator.h"
#include "SudokuSolver.h"

int main()
{
	LOG("Nasz super programik\n");
       
    SudokuGenerator generator;
    int* sudokuArray = new int[81]();
    generator.readFromFile(sudokuArray);
    SudokuSolver Sudoku(sudokuArray);
    int* sudokuResultArray = Sudoku.solve();
    generator.saveToFile(sudokuResultArray);
    delete[] sudokuArray;
    system("Pause");
	return 0;
}