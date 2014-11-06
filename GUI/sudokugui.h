#ifndef SUDOKUGUI_H
#define SUDOKUGUI_H

#include <QtWidgets/QMainWindow>
#include "ui_sudokugui.h"
#include "D:\studia\wmh\projekt\solver\SudokuGenerator.h"
#include "D:\studia\wmh\projekt\solver\SudokuSolver.h"
#include <ctime>
#include <cstdlib>

class SudokuGUI : public QMainWindow
{
	Q_OBJECT

		public slots:
			//Klikniecie przycisku OK
			void okButtonClicked(){
				srand(unsigned(time(0)));
				int* sudokuArray = new int[81]();
				SudokuGenerator generator;
				generator.generate(sudokuArray, level);
				changeCellsValue(sudokuArray);
				delete[] sudokuArray;
				//generacja, szukanie rozwiazania,itd
			}
			//zaznaczenie sasiadow
			void mostNeighboursSelected(){
				method = 0;
			}
			//zaznaczenie losowosci
			void randomSelected(){
				method = 1;
			}
			//wybor z listy poziomow trudnosci
			void setDifficultyLevel(int lvl){
				//wydaje mi sie ze indeksowanie od 0
				level = static_cast<COMPLEXITY_LEVELS>(lvl+1);
			}
			void setRepetitionCount(const QString & repCount){
				repetitions=repCount.toInt();
			}
public:
	SudokuGUI(QWidget *parent = 0);
	~SudokuGUI();
	int method;
	COMPLEXITY_LEVELS level;
	int repetitions;
private:
	Ui::SudokuGUIClass ui;
	void changeCellsValue(int* table){
		//pewnie bedzie sie przekazywac tablice z wynikiem i tablice wygenerowana i od tego uzalezniac kolor

	}

	void displayTime(string time){
		ui.TimeField->setText(QString::fromStdString(time));
	}

	void displayOperations(string operations){
		ui.OperationsField->setText(QString::fromStdString(operations));
	}
};

#endif // SUDOKUGUI_H
