#ifndef SudokuSolver_h
#define SudokuSolver_h

#include "Common.h"
#include <utility>
#include <vector>


class SudokuSolver {
public:
    SudokuSolver(int* sudokuArray);
    ~SudokuSolver();
    int* solve();
    bool checkIfFree(int y, int x);
    void findNextCell(int& y, int& x);

    int& accessSudokuArray(int y, int x) { return m_sudokuArray[(x-1) + (y-1)*9]; }
    int& accessTemporaryArray(int y, int x) { return m_sudokuTemporaryArray[x-1 + (y-1)*9]; }
    double getSolveTime() { return m_solveTime; }
    int getSolveComplexity() { return m_solveComplexity; }

private:
    int* m_sudokuArray;
    int* m_sudokuTemporaryArray;
    double m_solveTime;
    int m_solveComplexity;
    vector< pair<int,int> > m_cells;
};


#endif // SudokuSolver_h