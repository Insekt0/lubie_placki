#ifndef SudokuSolver_h
#define SudokuSolver_h

#include "Common.h"
#include <chrono>
#include <utility>
#include <vector>


class SudokuSolver {
public:
    SudokuSolver(int* sudokuArray);
    ~SudokuSolver();
    int* solve(NEXT_POINT_SEARCHING_SCENARIO SCENARIO);
    vector<int> checkPossibleValues(int itsY, int itsX);
    void countElements();
    void findAndSortEmptyCells(NEXT_POINT_SEARCHING_SCENARIO SCENARIO);
    int recursiveSearchInTree(int position);

    int& accessSudokuArray(int y, int x) { return m_sudokuArray[(x-1) + (y-1)*9]; }
    int& accessTemporaryArray(int y, int x) { return m_sudokuTemporaryArray[x-1 + (y-1)*9]; }
    int& accessSmallSquareArray(int y, int x) { return m_smallSquareArray[x-1 + (y-1)*3]; }
    void convert1Dto2D(int position, int& newY, int& newX) { newY = (position / 9) + 1, newX = (position % 9) + 1; }
    long long getSolveTime() { return m_solveTime; }
    long long getSolveComplexity() { return m_solveComplexity; }

private:
    int* m_sudokuArray;
    int* m_sudokuTemporaryArray;
    long long m_solveTime;
    long long m_solveComplexity;
    int* m_columnsElementsArray;
    int* m_rowsElementsArray;
    int* m_smallSquareArray;
    vector< pair<int,int> > m_cells;
};


#endif // SudokuSolver_h