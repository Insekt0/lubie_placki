#ifndef SudokuSolver_h
#define SudokuSolver_h

#include "Common.h"

#include <vector>


class SudokuSolver {
public:
    SudokuSolver(int* sudokuArray);
    ~SudokuSolver();
    int* solve(NEXT_POINT_SEARCHING_SCENARIO SCENARIO, bool isGenerating = false);
    static void checkPossibleValues(int itsY, int itsX, int* sudokuArray, bool* resultArray);
    void findAndSortEmptyCells(NEXT_POINT_SEARCHING_SCENARIO SCENARIO);
    int recursiveSearchInTree(int position, bool isGenerating);

    inline int& accessSudokuArray(int y, int x) { return m_sudokuArray[(x-1) + (y-1)*9]; }
    inline int& accessTemporaryArray(int y, int x) { return m_sudokuTemporaryArray[x-1 + (y-1)*9]; }
    static void convert1Dto2D(int position, int& newY, int& newX) { newY = (position / 9) + 1, newX = (position % 9) + 1; }
    long long getSolveTime() { return m_solveTime; }
    long long getSolveComplexity() { return m_solveComplexity; }

private:
    int* m_sudokuArray;
    int* m_sudokuTemporaryArray;
    long long m_solveTime;
    long long m_solveComplexity;
    vector< pair<int,int> > m_cells;
    int* m_cellsArray;
    unsigned m_cellsNumber;
    bool isSudokuAlreadySolved;
};


#endif // SudokuSolver_h