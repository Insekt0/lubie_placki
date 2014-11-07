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

enum STATUS_BAR_INFO {
    EMPTY = 0,
    WRONG_SUDOKU_BOARD,
    SUDOKU_UNSOLVABLE
};

class SudokuGUI : public QMainWindow
{
    Q_OBJECT
    public slots:
        void generateButtonClicked();
        void solveButtonClicked();
        void loadSudokuButtonClicked();
        void aboutAuthorsClicked();
        void mostNeighboursSelected() { m_solveMethod = MOST_NEIGHBOURS; }
        void randomSelected() { m_solveMethod = RANDOM; }
        void setDifficultyLevel(int lvl) { m_level = static_cast<COMPLEXITY_LEVELS>(lvl+1); }
        void setRepetitionCount(const QString & repCount) { m_repetitionsCount = repCount.toInt(); }
        void setSaveFlag(bool flag) { m_saveFlag = flag; }

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
        void updateStatusBar(STATUS_BAR_INFO status);

        ofstream m_file;
        unsigned m_repetitionsCount;        
        int m_sudokuGeneratedArray[81];
        int m_sudokuSolvedArray[81];
        bool m_saveFlag;
        NEXT_POINT_SEARCHING_SCENARIO m_solveMethod;
        COMPLEXITY_LEVELS m_level;
        Ui::SudokuGUIClass m_ui;
        QLineEdit* m_cellsArray[81];
};

#endif // SUDOKUGUI_H
