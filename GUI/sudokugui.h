#ifndef SUDOKUGUI_H
#define SUDOKUGUI_H

#include "ui_sudokugui.h"
#include "../solver/Common.h"
#include "../solver/SudokuGenerator.h"
#include "../solver/SudokuSolver.h"

#include <fstream>
#include <QFileDialog>
#include <ctime>
#include <cstdlib>
#include <QtWidgets/QMainWindow>

class SudokuGUI : public QMainWindow
{
    Q_OBJECT
    public slots:
        void generateButtonClicked();
        void solveButtonClicked();
        void loadSudokuButtonClicked();
        void mostNeighboursSelected() { m_solveMethod = MOST_NEIGHBOURS; }
        void randomSelected() { m_solveMethod = RANDOM; }
        void setDifficultyLevel(int lvl) { m_level = static_cast<COMPLEXITY_LEVELS>(lvl+1); }
        void setRepetitionCount(const QString & repCount) { m_repetitionsCount = repCount.toInt(); }
        void setSaveFlag(bool flag) { saveFlag = flag;}

    public:
        SudokuGUI(QWidget *parent = 0);

    private:
        void changeCellsValue(int* table, bool justAfterSolve = false);
        void displayTime(long long time);
        void displayOperations(long long operations);
        void changeGridToArray(int* table);
        void moveCellsIntoTable();
        void generate();
        void solve();
        void saveToFile(string stream);

        ofstream myfile;
        unsigned m_repetitionsCount;        
        int m_sudokuGeneratedArray[81];
        int m_sudokuSolvedArray[81];
        bool saveFlag;
        NEXT_POINT_SEARCHING_SCENARIO m_solveMethod;
        COMPLEXITY_LEVELS m_level;
        Ui::SudokuGUIClass ui;
        QLineEdit* m_cellsArray[81];
};

#endif // SUDOKUGUI_H
