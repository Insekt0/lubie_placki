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
    
    for (int i = 0; i < 81; ++i)
        positions.push_back(i);
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
            
            for(int i = 0; i < 9; ++i)
                if(possibleValues[i])
                {
                    sudokuArray[chosenPosition] = i+1;
                    break;
                }
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

struct color {
    color(WORD attribute):m_color(attribute){};
    WORD m_color;
};

template <class _Elem, class _Traits>
std::basic_ostream<_Elem,_Traits>& 
      operator<<(std::basic_ostream<_Elem,_Traits>& i, color& c)
{
    HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout,c.m_color);
    return i;
}

inline std::ostream& red(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
                FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& white(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
       FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    return s;
}

inline std::ostream& blue(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
              |FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    return s;
}

void SudokuGenerator::printSudoku(int* sudokuArray, string name, int* baseArray) {
    
    cout << "\nSudoku: " << name;
    for (int i = 0; i < 81; ++i)
    {
        if(i%9 == 0)
            cout << endl;
        if(i%27 == 0)
            cout << white << " -----------------------" << endl;
        
        if(i%3 == 0)
            cout << white << "| ";
        
        if(!baseArray && sudokuArray[i])
            cout << white << sudokuArray[i] << " ";
        else if(!baseArray)
            cout << "  ";
        else if(sudokuArray[i] && sudokuArray[i] == baseArray[i])
            cout << white << sudokuArray[i] << " ";
        else if(sudokuArray[i])
            cout << red << sudokuArray[i] << " ";
        else
            cout << "  ";
        if(i%9 == 8)
            cout << white << "|";
        if(i == 80)
            cout << white << "\n -----------------------" << endl;
    }

}