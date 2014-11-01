#include "SudokuSolver.h"
#include <algorithm>

bool sort_function (pair<int,int> first_pair, pair<int,int> second_pair) {
    return first_pair.second > second_pair.second; 
}

SudokuSolver::SudokuSolver(int* sudokuArray) {
    m_sudokuArray = new int[81]();
    m_sudokuTemporaryArray = new int[81]();
    m_columnsElementsArray = new int[9]();
    m_rowsElementsArray = new int[9]();
    m_smallSquareArray = new int[9]();
    for(int i = 0; i < 81; ++i)
    {
        m_sudokuArray[i] = sudokuArray[i];
        m_sudokuTemporaryArray[i] = sudokuArray[i];
    }
}

SudokuSolver::~SudokuSolver() {
    delete[] m_sudokuArray;
    delete[] m_sudokuTemporaryArray;
    delete[] m_columnsElementsArray;
    delete[] m_rowsElementsArray;
    delete[] m_smallSquareArray;
}

void SudokuSolver::countElements() {

    for (int y = 1; y <= 9; ++y)
        for (int x = 1; x <= 9; ++x)
        {
            if (!accessSudokuArray(y, x))
                continue;
            ++m_rowsElementsArray[y-1];
            ++m_columnsElementsArray[x-1];
            ++accessSmallSquareArray((y + 2) / 3, (x + 2) / 3);
        }
    
    LOG("Row elements array\n");
    for(int i = 0; i < 9; ++i)
    {
        LOG("%d\n", m_rowsElementsArray[i]);
    }
    LOG("Column elements array\n");
    for(int i = 0; i < 9; ++i)
    {
        LOG("%d ", m_columnsElementsArray[i]);
    }
    LOG("\nSmall squares elements array");
    for(int i = 0; i < 9; ++i)
    {
        if(i%3 == 0)
            LOG("\n");
        LOG("%d ", m_smallSquareArray[i]);
    }
    LOG("\n");
   
}

void SudokuSolver::findAndSortEmptyCells(NEXT_POINT_SEARCHING_SCENARIO SCENARIO) {
    int value;
    int position;

    for (int y = 1; y <= 9; ++y)
        for (int x = 1; x <= 9; ++x)
        {
            if (accessSudokuArray(y, x))
                continue;

            switch(SCENARIO)
            {
                case MOST_NEIGHBOURS:
                    value = m_rowsElementsArray[y-1] < m_columnsElementsArray[x-1] ? m_columnsElementsArray[x-1] : m_rowsElementsArray[y-1];
                    value = value < accessSmallSquareArray((y + 2) / 3, (x + 2) / 3) ? accessSmallSquareArray((y + 2) / 3, (x + 2) / 3) : value;
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

    for(unsigned i = 0; i < m_cells.size(); ++i)
        LOG("%d: position:%d, value:%d\n", i, m_cells[i].first, m_cells[i].second); 
}

// static
vector<int> SudokuSolver::checkPossibleValues(int itsY, int itsX, int* sudokuArray) {
    vector<int> result;
    
    bool values[9];
    for(int i =0; i < 9; ++i)
        values[i] = true;

    // checks which values exist in column
    for (int y = 1; y <= 9; ++y)
    {
        if(!sudokuArray[itsX-1 + (y-1)*9])
            continue;
        values[sudokuArray[itsX-1 + (y-1)*9]-1] = false;
    }

    // checks which values exist in row
    for (int x = 1; x <= 9; ++x)
    {
        if(!sudokuArray[x-1 + (itsY-1)*9])
            continue;
        values[sudokuArray[x-1 + (itsY-1)*9]-1] = false;
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
            values[sudokuArray[x-1 + (y-1)*9]-1] = false;
        }

    for (int i = 0; i < 9; ++i)
        if(values[i]) 
            result.push_back(i+1);

    return result;
}

int SudokuSolver::recursiveSearchInTree(int position) {

    ++m_solveComplexity;

    int itsY;
    int itsX;

    convert1Dto2D(position, itsY, itsX);
    LOG("itsY: %d, itsX: %d\n", itsY, itsX);
    vector<int> possibleValues = checkPossibleValues(itsY, itsX, m_sudokuTemporaryArray);
    LOG("possible values: ");
    for (unsigned i = 0; i < possibleValues.size(); ++i)
        LOG("%d ", possibleValues[i]);
    LOG("\n");

    if(possibleValues.empty())
        return -1; // dead end, solution is somewhere else

    unsigned nextCellPosition = -1;
    unsigned vectorIndex = -1;

    for (unsigned i = 0; i < m_cells.size(); ++i)
        if(m_cells[i].first != -1)
        {
            nextCellPosition = m_cells[i].first;
            vectorIndex = i;
            break;
        }
    // LOG("nextCellPosition: %d\n", nextCellPosition);
    // LOG("vectorIndex: %d\n", vectorIndex);
    if (nextCellPosition == -1)
    {
        accessTemporaryArray(itsY, itsX) = possibleValues[0];
        return 0; // Solution found
    }

    m_cells[vectorIndex].first = -1;
    int result;

    for (unsigned i = 0; i < possibleValues.size(); ++i)
    {
        LOG("possibleValue: %d\n", possibleValues[i]);
        accessTemporaryArray(itsY, itsX) = possibleValues[i];
        result = recursiveSearchInTree(nextCellPosition);
        if(!result)
            return 0;
    }

    accessTemporaryArray(itsY, itsX) = 0;
    m_cells[vectorIndex].first = nextCellPosition;

    return -1; // dead end, solution is somewhere else
}

int* SudokuSolver::solve(NEXT_POINT_SEARCHING_SCENARIO SCENARIO) {
    auto startTime = std::chrono::steady_clock::now();
    m_solveComplexity = 0;
    countElements();
    findAndSortEmptyCells(SCENARIO);
    
    int position = m_cells[0].first;
    m_cells[0].first = -1;
    
    int result = recursiveSearchInTree(position);

    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    m_solveTime = elapsedTime.count();

    if(result)
        return 0;
    
    return m_sudokuTemporaryArray;
}