#include "SudokuSolver.h"

bool sort_function (pair<int,int> first_pair, pair<int,int> second_pair) {
    return first_pair.second > second_pair.second; 
}

SudokuSolver::SudokuSolver(int* sudokuArray) {
    m_sudokuArray = new int[81];
    m_sudokuTemporaryArray = new int[81];
    for(int i = 0; i < 81; ++i)
    {
        m_sudokuArray[i] = sudokuArray[i];
        m_sudokuTemporaryArray[i] = sudokuArray[i];
    }
}

SudokuSolver::~SudokuSolver() {
    delete[] m_sudokuArray;
    delete[] m_sudokuTemporaryArray;
}

int* SudokuSolver::solve() {
    // IMPLEMENT ME
    return m_sudokuTemporaryArray;
}

bool SudokuSolver::checkIfFree(int y, int x) {
    // IMPLEMENT ME
    return true;
}

void findNextCell(int& y, int& x)
{
    // IMPLEMENT ME
}