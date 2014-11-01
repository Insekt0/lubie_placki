#include <iostream>
#include <sstream>
#include "Common.h"
#include "SudokuGenerator.h"
#include "SudokuSolver.h"


int main()
{
	cout << "Nasz super sudoku solver" << endl;
    cout << "Podaj poczatkowa liczbe pol sudoku" << endl;
    
    int filledCellsNumber;
    cin >> filledCellsNumber;
    ostringstream ss;
    ss << filledCellsNumber;
    string filename = ss.str();

    SudokuGenerator generator;
    int* sudokuArray = new int[81]();

    generator.generate(sudokuArray, filledCellsNumber);
    generator.printSudoku(sudokuArray, filename);

    //generator.readFromFile(sudokuArray, filename);
    
    SudokuSolver Sudoku1(sudokuArray);
    int* sudokuResultArray1 = Sudoku1.solve(MOST_NEIGHBOURS);
    generator.saveToFile(sudokuResultArray1);

    string result;
    result.append(filename); 
    result.append(" result");

    generator.printSudoku(sudokuResultArray1, result);
    
    cout << "Sudoku solved in MOST_NEIGHBOURS mode in: " << Sudoku1.getSolveTime()/1000000 << "s " << (Sudoku1.getSolveTime() % 1000000)/1000 << "ms " << (Sudoku1.getSolveTime() % 1000) << "us" << endl;
    cout << "Operations performed: " << Sudoku1.getSolveComplexity() << endl;
    
    /*SudokuSolver Sudoku2(sudokuArray);
    int* sudokuResultArray2 = Sudoku2.solve(RANDOM);
    generator.printSudoku(sudokuResultArray2, filename);
    
    cout << "Sudoku solved in RANDOM mode in: " << Sudoku2.getSolveTime()/1000000 << "s " << (Sudoku2.getSolveTime() % 1000000)/1000 << "ms " << (Sudoku2.getSolveTime() % 1000) << "us" << endl;
    cout << "Operations performed: " << Sudoku2.getSolveComplexity() << endl << endl;
    
    if(Sudoku1.getSolveTime() < Sudoku2.getSolveTime())
        cout << "MOST_NEIGHBOURS mode was " << Sudoku2.getSolveTime() / Sudoku1.getSolveTime() << " times faster than RANDOM mode" << endl;
    else
        cout << "RANDOM mode was " << Sudoku1.getSolveTime() / Sudoku2.getSolveTime() << " times faster than MOST_NEIGHBOURS mode" << endl;
    delete[] sudokuArray;*/
	
    cout << endl;
    system("Pause");
    return 0;
}