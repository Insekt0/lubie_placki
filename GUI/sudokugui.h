#ifndef SUDOKUGUI_H
#define SUDOKUGUI_H

#include <QtWidgets/QMainWindow>
#include "ui_sudokugui.h"
#include "..\solver\SudokuGenerator.h"
#include "..\solver\SudokuSolver.h"
#include <ctime>
#include <cstdlib>

class SudokuGUI : public QMainWindow
{
    Q_OBJECT
    private:
        Ui::SudokuGUIClass ui;
        void changeCellsValue(int* table);
        void displayTime(string time);
        void displayOperations(string operations);
    public slots:
        void okButtonClicked();
        void mostNeighboursSelected();
        void randomSelected();
        void setDifficultyLevel(int lvl);
        void setRepetitionCount(const QString & repCount);
    public:
        SudokuGUI(QWidget *parent = 0);
        ~SudokuGUI();
        int method;
        COMPLEXITY_LEVELS level;
        int repetitions;

};

#endif // SUDOKUGUI_H
