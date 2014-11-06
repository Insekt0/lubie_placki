#include "sudokugui.h"



		SudokuGUI::SudokuGUI(QWidget *parent)
			: QMainWindow(parent)
		{
			QStringList levelsList=(QStringList()<<"Ekstremalnie latwy"<<"Latwy"<<"Sredni"<<"Trudny"<<"Piekielnie trudny");
			/*method = 0;
			level = static_cast<COMPLEXITY_LEVELS>(1);
			repetitions=0;*/
			ui.setupUi(this);
			ui.DifficultyLevelSelector->addItems(levelsList);
			QObject::connect(ui.okButton, SIGNAL(clicked()),ui.centralWidget,SLOT(okButtonClicked()));
			QObject::connect(ui.DifficultyLevelSelector, SIGNAL(currentIndexChanged(int)),ui.centralWidget,SLOT(setDifficultyLevel(int)));
			QObject::connect(ui.RepetitionField, SIGNAL(textChanged(const QString &)),ui.centralWidget, SLOT(setRepetitionCount(const QString &)));
			QObject::connect(ui.MostNeighboursButton, SIGNAL(clicked()), ui.MethodGroup,SLOT(mostNeighboursSelected()));
			QObject::connect(ui.RandomButtom, SIGNAL(clicked()),ui.MethodGroup,SLOT(randomSelected()));
		}

		SudokuGUI::~SudokuGUI()
		{

		}
