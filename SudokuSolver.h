#ifndef SudokuSolver_h
#define SudokuSolver_h

#include "Common.h"

#include <vector>

struct Cell {
    int* m_row;
    int* m_column;
    int* m_square;
};

class SudokuSolver {
public:
    SudokuSolver(int* sudokuArray);
    int* solve(NEXT_POINT_SEARCHING_SCENARIO SCENARIO, bool isGenerating = false);
    static void checkPossibleValues(int itsY, int itsX, int* sudokuArray, bool* resultArray);
    void findAndSortEmptyCells(NEXT_POINT_SEARCHING_SCENARIO SCENARIO);
    int recursiveSearchInTree(int position, bool isGenerating, unsigned newIndex);
    void initializeValues();
    inline bool checkCollision(int position, int value);
    inline void setCellValue(int position, int value);
    inline void removeCellValue(int position, int value);

    inline int& accessSudokuArray(int y, int x) { return m_sudokuArray[(x-1) + (y-1)*9]; }
    inline int& accessTemporaryArray(int y, int x) { return m_sudokuTemporaryArray[x-1 + (y-1)*9]; }
    static void convert1Dto2D(int position, int& newY, int& newX) { newY = (position / 9) + 1, newX = (position % 9) + 1; }
    long long getSolveTime() { return m_solveTime; }
    long long getSolveComplexity() { return m_solveComplexity; }

private:
    Cell m_cells[81];
    int m_rows[9];
    int m_columns[9];
    int m_squares[9];
    int m_sudokuArray[81];
    int m_sudokuTemporaryArray[81];
    long long m_solveTime;
    long long m_solveComplexity;
    vector< pair<int,int> > m_cellsVector;
    int m_cellsArray[81];
    unsigned m_cellsNumber;
    bool isSudokuAlreadySolved;
};


#endif // SudokuSolver_h