#include "SudokuGenerator.h"

#include "SudokuSolver.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <Windows.h>

void SudokuGenerator::generate(int* sudokuArray, COMPLEXITY_LEVELS LEVEL) {
    int result[81];
    int* tempResult = 0;
    int y;
    int x;
    unsigned attempt = 0;
    int chosenPosition;
    vector<int> positions;
    vector<int> checkedPossibleValues;

    
    for (int i = 0; i < 81; ++i)
    {
        positions.push_back(i);
        sudokuArray[i] = 0;
    }

    while(1)
    {
        ++attempt;
        for (int i = 0; i < 9; ++i)
            sudokuArray[positions[i]] = 0;

        random_shuffle(positions.begin(), positions.end());
        bool possibleValues[9];
        

        for (int i = 0; i < 9; ++i)
        {
            chosenPosition = positions[i];
            SudokuSolver::convert1Dto2D(chosenPosition, y, x);
            
            SudokuSolver::checkPossibleValues(y, x, sudokuArray, possibleValues);
            checkedPossibleValues.clear();
            checkedPossibleValues.reserve(9);

            for(int j = 0; j < 9; ++j)
                if(possibleValues[j])
                    checkedPossibleValues.push_back(j+1);

            if(!checkedPossibleValues.size())
                continue;

            random_shuffle(checkedPossibleValues.begin(), checkedPossibleValues.end());
            sudokuArray[chosenPosition] = checkedPossibleValues[0];

        }
        SudokuSolver sudoku(sudokuArray);
        int* tempResult = sudoku.solve(MOST_NEIGHBOURS, true);
        if(tempResult)
        { 
#if DEBUG_MODE 
            printSudoku(sudokuArray, "generated");
#endif
            for(int i = 0; i < 81; ++i)
                result[i] = tempResult[i];
#if DEBUG_MODE            
            printSudoku(result, "solved");
            unsigned timeInSec = unsigned(sudoku.getSolveTime()/1000000000);
            unsigned timeInMiliSec = (sudoku.getSolveTime() % 1000000000)/1000000;
            unsigned timeInMicroSec = (sudoku.getSolveTime() % 1000000) / 1000;
            unsigned timeInNanoSec = sudoku.getSolveTime() % 1000;
#endif
            LOG("Sudoku solved in MOST_NEIGHBOURS mode in: %us %ums %uus %uns\n", timeInSec, timeInMiliSec, timeInMicroSec, timeInNanoSec);
            LOG("Operations performed: %u\n", static_cast<unsigned>(sudoku.getSolveComplexity()));
            LOG("Attempt: %d\n", attempt);
            break;
        }
    }
    
    for (int i = 0; i < 81; ++i)
        sudokuArray[i] = result[i];

    // in this moment we have sudoku board fully filled
    // now we are removing cells

    string level;
    int numberOfCellsLeftOnBoard = 0;
    switch(LEVEL)
    {
    case EXTREMELY_EASY:
        level = "Extremely easy";
        numberOfCellsLeftOnBoard = rand() % 22 + 50;
        break;
    case EASY:
        level = "Easy";
        numberOfCellsLeftOnBoard = rand() % 14 + 36;
        break;
    case MEDIUM:
        level = "Medium";
        numberOfCellsLeftOnBoard = rand() % 4 + 32;
        break;
    case DIFFICULT:
        level = "Difficult";
        numberOfCellsLeftOnBoard = rand() % 4 + 28;
        break;
    case EVIL:
        level = "Evil";
        numberOfCellsLeftOnBoard = rand() % 6 + 22;
        break;
    default:
        assert(false);
    }

    LOG("numberOfCellsLeftOnBoard = %d\n", numberOfCellsLeftOnBoard);
    LOG("Level: %s\n", level.c_str());

    for (int i = 0; i < (81 - numberOfCellsLeftOnBoard); ++i)
        sudokuArray[positions[i]] = 0;
}