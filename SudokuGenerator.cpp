#include "SudokuGenerator.h"

#include "SudokuSolver.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>

void SudokuGenerator::generate(int* sudokuArray, COMPLEXITY_LEVELS LEVEL) {
    int result[81];
    int* tempResult = 0;
    int y;
    int x;
    unsigned attempt = 0;
    int chosenPosition;
    vector<int> positions;
    
    for (int i = 0; i < 81; ++i)
        positions.push_back(i);
    while(1)
    {
        ++attempt;
        for (int i = 0; i < 9; ++i)
            sudokuArray[positions[i]] = 0;

        random_shuffle(positions.begin(), positions.end());

        for (int i = 0; i < 9; ++i)
        {
            chosenPosition = positions[i];
            SudokuSolver::convert1Dto2D(chosenPosition, y, x);
            vector<int> possibleValues = SudokuSolver::checkPossibleValues(y, x, sudokuArray);
            random_shuffle(possibleValues.begin(), possibleValues.end());
            sudokuArray[chosenPosition] = possibleValues[0];
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
#endif
            LOG("Sudoku solved in MOST_NEIGHBOURS mode in: %ds %dms %dus\n", sudoku.getSolveTime()/1000000, (sudoku.getSolveTime() % 1000000)/1000, (sudoku.getSolveTime() % 1000));
            LOG("Operations performed: %d\n", sudoku.getSolveComplexity());
            LOG("Attempt: %d\n", attempt);
            break;
        }
    }
    
    for (int i = 0; i < 81; ++i)
        sudokuArray[i] = result[i];

    // in this moment we have sudoku board fully filled
    // now we are removing cells

    string level;
    int numberOfCellsLeftOnBoard;
    switch(LEVEL)
    {
    case EXTREMELY_EASY:
        level = "Extremely easy";
        numberOfCellsLeftOnBoard = rand() % 31 + 50;
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

    printSudoku(sudokuArray, level);
}

void SudokuGenerator::readFromFile(int* sudokuArray, string filename) {
    ifstream myfile;
    myfile.open(filename);
    int value;
    int counter = 0;
    while(myfile >> value)
        sudokuArray[counter++] = value;
}
    
void SudokuGenerator::saveToFile(int* sudokuArray) {
    ofstream myfile;
    myfile.open("result.txt");
    for (int i = 0; i < 81; ++i)
    {
        myfile << sudokuArray[i] << " ";
        if(i%9 == 8)
            myfile << "\n";
    }
    myfile.close();
}

void SudokuGenerator::printSudoku(int* sudokuArray, string name) {
    
    cout << "\nSudoku: " << name;
    for (int i = 0; i < 81; ++i)
    {
        if(i%9 == 0)
            cout << endl;
        if(i%27 == 0)
            cout << " -----------------------" << endl;
        
        if(i%3 == 0)
            cout << "| ";
        cout << sudokuArray[i] << " ";

        if(i%9 == 8)
            cout << "|";
        if(i == 80)
            cout << "\n -----------------------" << endl;
    }

}