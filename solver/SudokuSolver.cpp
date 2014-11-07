#include "SudokuSolver.h"

#include <algorithm>
#include <chrono>
#include <utility>

bool sort_function (pair<int,int> first_pair, pair<int,int> second_pair) {
    return first_pair.second < second_pair.second; 
}

SudokuSolver::SudokuSolver(int* sudokuArray) {
    m_cellsVector.reserve(81);
    isSudokuAlreadySolved = true;
    int value;
    for(int i = 0; i < 81; ++i)
    {
        value = sudokuArray[i];
        if(!value && isSudokuAlreadySolved)
            isSudokuAlreadySolved = false;
        m_sudokuArray[i] = value;
        m_sudokuTemporaryArray[i] = value;
    }
}

void SudokuSolver::findAndSortEmptyCells(NEXT_POINT_SEARCHING_SCENARIO SCENARIO) {
    int value;
    int position;
    bool resultArray[9];

    for (int y = 1; y <= 9; ++y)
        for (int x = 1; x <= 9; ++x)
        {
            if (accessSudokuArray(y, x))
                continue;

            switch(SCENARIO)
            {
                case MOST_NEIGHBOURS:
                    value = 0;
                    checkPossibleValues(y, x, m_sudokuArray, resultArray);
                    for (int i = 0; i < 9; ++i)
                        value = resultArray[i] ? value + 1 : value;
                    break;
                case RANDOM:
                    value = 0;
                    break;
                default:
                    assert(false);
                    break;
            }
                position = x-1 + (y-1)*9;
            m_cellsVector.push_back(make_pair(position, value));
        }
    assert(!m_cellsVector.empty());
    switch(SCENARIO)
    {
        case MOST_NEIGHBOURS:
            sort(m_cellsVector.begin(), m_cellsVector.end(), sort_function);
            break;
        case RANDOM:
            random_shuffle(m_cellsVector.begin(), m_cellsVector.end());
            break;
        default:
            assert(false);
            break;
    }
#if DEBUG_MODE
    int y;
    int x;
    for (unsigned i = 0; i < m_cellsVector.size(); ++i)
    {
        convert1Dto2D(m_cellsVector[i].first, y, x); 
        LOG("y: %d, x: %d, possible values: %d\n", y, x, m_cellsVector[i].second); 
    }
#endif
}

// static
void SudokuSolver::checkPossibleValues(int itsY, int itsX, int* sudokuArray, bool* resultArray) {
    for(int i =0; i < 9; ++i)
        resultArray[i] = true;

    // checks which values exist in column
    for (int y = 1; y <= 9; ++y)
    {
        if(!sudokuArray[itsX-1 + (y-1)*9])
            continue;
        resultArray[sudokuArray[itsX-1 + (y-1)*9]-1] = false;
    }

    // checks which values exist in row
    for (int x = 1; x <= 9; ++x)
    {
        if(!sudokuArray[x-1 + (itsY-1)*9])
            continue;
        resultArray[sudokuArray[x-1 + (itsY-1)*9]-1] = false;
    }

    int lowerXBorder;
    int lowerYBorder;
    int upperXBorder;
    int upperYBorder;

    if(itsX < 4) {
        lowerXBorder = 1;
        upperXBorder = 3;
    } else if (itsX < 7) {
        lowerXBorder = 4;
        upperXBorder = 6;        
    } else {
        lowerXBorder = 7;
        upperXBorder = 9; 
    }

    if(itsY < 4) {
        lowerYBorder = 1;
        upperYBorder = 3;
    } else if (itsY < 7) {
        lowerYBorder = 4;
        upperYBorder = 6;        
    } else {
        lowerYBorder = 7;
        upperYBorder = 9; 
    }

    // checks which values exist in small square
    for (int y = lowerYBorder; y <= upperYBorder; ++y)
        for (int x = lowerXBorder; x <= upperXBorder; ++x)
        {
            if(!sudokuArray[x-1 + (y-1)*9])
                continue;
            resultArray[sudokuArray[x-1 + (y-1)*9]-1] = false;
        }
}

void SudokuSolver::initializeValues()
{
    for (int i = 0; i < 9; ++i)
    {
        m_rows[i] = 0;
        m_columns[i] = 0;
        m_squares[i] = 0;
    }
    int positionInBigArray;
    int positionOfSquare;
    for (int x = 0; x < 9; ++x)
        for(int y = 0; y < 9; ++y)
        {
            positionInBigArray = x + 9*y;
            positionOfSquare = x/3 + (y/3)*3;
            if(m_sudokuArray[positionInBigArray])
            {
                m_rows[y] = m_rows[y] | 1 << m_sudokuArray[positionInBigArray]; 
                m_columns[x] = m_columns[x] | 1 << m_sudokuArray[positionInBigArray];
                m_squares[positionOfSquare] = m_squares[positionOfSquare] | 1 << m_sudokuArray[positionInBigArray];
            }
            m_cells[positionInBigArray].m_column = m_columns + x;
            m_cells[positionInBigArray].m_row = m_rows + y;
            m_cells[positionInBigArray].m_square = m_squares + positionOfSquare;
        }
}

inline bool SudokuSolver::checkCollision(int position, int value)
{
    return !!((*m_cells[position].m_column | *m_cells[position].m_row | *m_cells[position].m_square) & (1 << value));
}

void SudokuSolver::setCellValue(int position, int value)
{
    *m_cells[position].m_column = *m_cells[position].m_column | (1 << value);
    *m_cells[position].m_row = *m_cells[position].m_row | (1 << value);
    *m_cells[position].m_square = *m_cells[position].m_square | (1 << value);
}

void SudokuSolver::removeCellValue(int position, int value)
{
    *m_cells[position].m_column = *m_cells[position].m_column ^ (1 << value);
    *m_cells[position].m_row = *m_cells[position].m_row ^ (1 << value);
    *m_cells[position].m_square = *m_cells[position].m_square ^ (1 << value);
}


int SudokuSolver::recursiveSearchInTree(int position, bool isGenerating, unsigned newIndex) {

    ++m_solveComplexity;
#if ENSURE_FAST_GENERATION    
    if(isGenerating && m_solveComplexity > MAX_OPERATIONS)
        return -2;
#endif
    
    bool collisionArray[9];
    
    for (int i = 0; i < 9; ++i)
        collisionArray[i] = checkCollision(position, i+1);

    bool shouldReturn = true;
    int firstPossibleValue;
    for (int i = 0; i < 9; ++i)
        if(!collisionArray[i]) // == false
        {
            firstPossibleValue = i+1;
            shouldReturn = false;
            break;
        }

    if(shouldReturn)
        return -1; // dead end, solution is somewhere else

    if (m_cellsNumber == newIndex)
    {
        m_sudokuTemporaryArray[position] = firstPossibleValue;
        return 0; // Solution found
    }

    unsigned nextCellPosition = m_cellsArray[newIndex];
    m_cellsArray[newIndex] = -1;

    int result;

    for (unsigned i = firstPossibleValue; i <= 9; ++i)
    {
        if(collisionArray[i-1])
            continue;
        m_sudokuTemporaryArray[position] = i;
        setCellValue(position,i);
        result = recursiveSearchInTree(nextCellPosition, isGenerating, newIndex+1);
        if(!result)
            return 0;
        removeCellValue(position,i);
    }

    m_sudokuTemporaryArray[position] = 0;
    m_cellsArray[newIndex] = nextCellPosition;
    return -1; // dead end, solution is somewhere else
}

int* SudokuSolver::solve(NEXT_POINT_SEARCHING_SCENARIO SCENARIO, bool isGenerating) {
    if(isSudokuAlreadySolved)
        return m_sudokuArray;
    auto startTime = std::chrono::steady_clock::now();
    m_solveComplexity = 0;
    findAndSortEmptyCells(SCENARIO);
    initializeValues();
    
    m_cellsNumber = m_cellsVector.size();
    for (unsigned i = 0; i < m_cellsNumber; ++i)
        m_cellsArray[i] = m_cellsVector[i].first;

    int position = m_cellsArray[0];
    m_cellsArray[0] = -1;
    
    int result = recursiveSearchInTree(position, isGenerating, 1);

    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    m_solveTime = elapsedTime.count();

    if(result)
        return 0;
    
    return m_sudokuTemporaryArray;
}