#include "SudokuGenerator.h"

#include "SudokuSolver.h"
#include <algorithm>
#include <fstream>



void SudokuGenerator::generate(int* sudokuArray, int numberOfCellsToFill) {
    int* result = 0;
    int chosenPosition;
    bool earlyReturnFromLoop;
    int y;
    int x;
    unsigned attempt = 0;
    while(!result)
    {
        for (int i = 0; i < 81; ++i)
            sudokuArray[i] = 0;

        vector<int> positions;

        for (int i = 0; i < 81; ++i)
            positions.push_back(i);

        random_shuffle(positions.begin(), positions.end());
        
        earlyReturnFromLoop = false;

        for (int i = 0; i < numberOfCellsToFill; ++i)
        {
            vector<int> possibleValues;
            chosenPosition = positions[i];
            SudokuSolver::convert1Dto2D(chosenPosition, y, x);
            possibleValues = SudokuSolver::checkPossibleValues(y,x,sudokuArray);
            
            if(possibleValues.empty())
            {
                earlyReturnFromLoop = true;
                break;
            }
            
            random_shuffle(possibleValues.begin(), possibleValues.end());
            sudokuArray[chosenPosition] = possibleValues[0];
        }

        if(earlyReturnFromLoop)
            continue;
        
        SudokuSolver solver(sudokuArray);
        result = solver.solve(MOST_NEIGHBOURS);
        cout << "Attempt: " << attempt++ << endl;
    }
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
    
    cout << "\n    Sudoku: " << name;
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