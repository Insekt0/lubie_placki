#ifndef SUDOKUGUI_H
#define SUDOKUGUI_H

#include <QtWidgets/QMainWindow>
#include "ui_sudokugui.h"

class SudokuGUI : public QMainWindow
{
	Q_OBJECT

public:
	SudokuGUI(QWidget *parent = 0);
	~SudokuGUI();

private:
	Ui::SudokuGUIClass ui;
};

#endif // SUDOKUGUI_H
