#include "SudokuSolver.h"

#include <algorithm>
#include <chrono>
#include <utility>

bool sort_function (pair<int,int> first_pair, pair<int,int> second_pair) {
    return first_pair.second < second_pair.second; 
}

SudokuSolver::SudokuSolver(int* sudokuArray) {
    m_sudokuArray = new int[81]();
    m_sudokuTemporaryArray = new int[81]();
    m_cells.reserve(81);
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

SudokuSolver::~SudokuSolver() {
    delete[] m_sudokuArray;
    delete[] m_sudokuTemporaryArray;
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
            m_cells.push_back(make_pair(position, value));
        }
    assert(!m_cells.empty());
    switch(SCENARIO)
    {
        case MOST_NEIGHBOURS:
            sort(m_cells.begin(), m_cells.end(), sort_function);
            break;
        case RANDOM:
            random_shuffle(m_cells.begin(), m_cells.end());
            break;
        default:
            assert(false);
            break;
    }

    int y;
    int x;
    for (unsigned i = 0; i < m_cells.size(); ++i)
    {
        convert1Dto2D(m_cells[i].first, y, x); 
        LOG("y: %d, x: %d, possible values: %d\n", y, x, m_cells[i].second); 
    }
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

int SudokuSolver::recursiveSearchInTree(int position, bool isGenerating) {

    ++m_solveComplexity;
#if ENSURE_FAST_GENERATION    
    if(isGenerating && m_solveComplexity > MAX_OPERATIONS)
        return -2;
#endif
    int itsY;
    int itsX;

    convert1Dto2D(position, itsY, itsX);
    bool resultArray[9];
    checkPossibleValues(itsY, itsX, m_sudokuTemporaryArray, resultArray);

    bool shouldReturn = true;
    int firstPossibleValue;
    for (int i = 0; i < 9; ++i)
        if(resultArray[i] == true)
        {
            firstPossibleValue = i+1;
            shouldReturn = false;
            break;
        }

    if(shouldReturn)
        return -1; // dead end, solution is somewhere else

    unsigned nextCellPosition = -1;
    unsigned vectorIndex = -1;

    for (unsigned i = 0; i < m_cellsNumber; ++i)
        if(m_cellsArray[i] != -1)
        {
            nextCellPosition = m_cellsArray[i];
            vectorIndex = i;
            break;
        }
    // LOG("nextCellPosition: %d\n", nextCellPosition);
    // LOG("vectorIndex: %d\n", vectorIndex);
    if (nextCellPosition == -1)
    {
        accessTemporaryArray(itsY, itsX) = firstPossibleValue;
        return 0; // Solution found
    }

    m_cellsArray[vectorIndex] = -1;
    int result;

    for (unsigned i = 0; i < 9; ++i)
    {
        if(!resultArray[i])
            continue;
        accessTemporaryArray(itsY, itsX) = i+1;
        result = recursiveSearchInTree(nextCellPosition, isGenerating);
        if(!result)
            return 0;
    }

    accessTemporaryArray(itsY, itsX) = 0;
    m_cellsArray[vectorIndex] = nextCellPosition;

    return -1; // dead end, solution is somewhere else
}

int* SudokuSolver::solve(NEXT_POINT_SEARCHING_SCENARIO SCENARIO, bool isGenerating) {
    if(isSudokuAlreadySolved)
        return m_sudokuArray;
    auto startTime = std::chrono::steady_clock::now();
    m_solveComplexity = 0;
    findAndSortEmptyCells(SCENARIO);
    
    m_cellsNumber = m_cells.size();
    m_cellsArray = new int[m_cellsNumber]();

    for (unsigned i = 0; i < m_cellsNumber; ++i)
        m_cellsArray[i] = m_cells[i].first;

    int position = m_cellsArray[0];
    m_cellsArray[0] = -1;
    
    int result = recursiveSearchInTree(position, isGenerating);

    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    m_solveTime = elapsedTime.count();

    delete[] m_cellsArray;
    if(result)
        return 0;
    
    return m_sudokuTemporaryArray;
}