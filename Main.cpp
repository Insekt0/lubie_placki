#include "SudokuGenerator.h"
#include "SudokuSolver.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

int main()
{
	cout << "Nasz super sudoku solver" << endl << endl;
    cout << "Podaj poziom od 1 do 5 - 1: extremely easy, 5: evil" << endl;
    srand(unsigned(time(0)));
    //unsigned levelNumber;
    //cin >> levelNumber;
    //assert(levelNumber > 0 && levelNumber <= 5);
    //COMPLEXITY_LEVELS level = static_cast<COMPLEXITY_LEVELS>(levelNumber);
    int* sudokuArray = new int[81]();
    
    SudokuGenerator generator;
    //generator.generate(sudokuArray, level);

    generator.readFromFile(sudokuArray, "sudoku_whs.txt");
    generator.printSudoku(sudokuArray, "sudoku_whs.txt");


    SudokuSolver Sudoku1(sudokuArray);
    int* sudokuResultArray1 = Sudoku1.solve(MOST_NEIGHBOURS);

    generator.printSudoku(sudokuResultArray1, "MOST_NEIGHBOURS", sudokuArray);
    
    cout << "Sudoku solved in MOST_NEIGHBOURS mode in: " << Sudoku1.getSolveTime()/1000000000 << "s " << (Sudoku1.getSolveTime() % 1000000000)/1000000 << "ms " << (Sudoku1.getSolveTime() % 1000000) / 1000 << "us " << (Sudoku1.getSolveTime() % 1000) << "ns" << endl;
    cout << "Operations performed: " << Sudoku1.getSolveComplexity() << endl;
    
    SudokuSolver Sudoku2(sudokuArray);
    int* sudokuResultArray2 = Sudoku2.solve(RANDOM);
    generator.printSudoku(sudokuResultArray2, "RANDOM", sudokuArray);
    
    cout << "Sudoku solved in RANDOM mode in: " << Sudoku2.getSolveTime()/1000000000 << "s " << (Sudoku2.getSolveTime() % 1000000000)/1000000 << "ms " << (Sudoku2.getSolveTime() % 1000000) / 1000 << "us " << (Sudoku2.getSolveTime() % 1000) << "ns" << endl;
    cout << "Operations performed: " << Sudoku2.getSolveComplexity() << endl << endl;
    
    delete[] sudokuArray;
	
    cout << endl;
    system("Pause");
    return 0;
}