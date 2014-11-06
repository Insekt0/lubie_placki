/********************************************************************************
** Form generated from reading UI file 'sudokugui.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKUGUI_H
#define UI_SUDOKUGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <stdio.h>
#include <iostream>

QT_BEGIN_NAMESPACE
	using namespace std;
class Ui_SudokuGUIClass
{
public:
    QWidget *centralWidget;
    QPushButton *okButton;
    QComboBox *DifficultyLevelSelector;
    QLineEdit *TimeField;
    QLabel *DifficultyLevelLabel;
    QLineEdit *RepetitionField;
    QLineEdit *OperationsField;
    QGroupBox *MethodGroup;
    QWidget *layoutWidget_3;
    QVBoxLayout *MethodLayout;
    QRadioButton *MostNeighboursButton;
    QRadioButton *RandomButtom;
    QWidget *layoutWidget_4;
    QVBoxLayout *SudokuGridMainVerticalLayout;
    QHBoxLayout *SudokuGridHorizontalLayer1;
    QLineEdit *cell1;
    QLineEdit *cell2;
    QLineEdit *cell3;
    QSpacerItem *HorizontalSpacer1VLayer1;
    QLineEdit *cell4;
    QLineEdit *cell5;
    QLineEdit *cell6;
    QSpacerItem *HorizontalSpacer2VLayer1;
    QLineEdit *cell7;
    QLineEdit *cell8;
    QLineEdit *cell9;
    QHBoxLayout *SudokuGridHorizontalLayer2;
    QLineEdit *cell10;
    QLineEdit *cell11;
    QLineEdit *cell12;
    QSpacerItem *HorizontalSpacer1VLayer2;
    QLineEdit *cell13;
    QLineEdit *cell14;
    QLineEdit *cell15;
    QSpacerItem *HorizontalSpacer2VLayer2;
    QLineEdit *cell16;
    QLineEdit *cell17;
    QLineEdit *cell18;
    QHBoxLayout *SudokuGridHorizontalLayer3;
    QLineEdit *cell19;
    QLineEdit *cell20;
    QLineEdit *cell21;
    QSpacerItem *HorizontalSpacer1VLayer3;
    QLineEdit *cell22;
    QLineEdit *cell23;
    QLineEdit *cell24;
    QSpacerItem *HorizontalSpacer2VLayer3;
    QLineEdit *cell25;
    QLineEdit *cell26;
    QLineEdit *cell27;
    QHBoxLayout *SudokuGridHorizontalLayer4;
    QLineEdit *cell28;
    QLineEdit *cell29;
    QLineEdit *cell30;
    QSpacerItem *HorizontalSpacer1VLayer4;
    QLineEdit *cell31;
    QLineEdit *cell32;
    QLineEdit *cell33;
    QSpacerItem *HorizontalSpacer2VLayer4;
    QLineEdit *cell34;
    QLineEdit *cell35;
    QLineEdit *cell36;
    QHBoxLayout *SudokuGridHorizontalLayer5;
    QLineEdit *cell37;
    QLineEdit *cell38;
    QLineEdit *cell39;
    QSpacerItem *HorizontalSpacer1VLayer5;
    QLineEdit *cell40;
    QLineEdit *cell41;
    QLineEdit *cell42;
    QSpacerItem *HorizontalSpacer2VLayer5;
    QLineEdit *cell43;
    QLineEdit *cell44;
    QLineEdit *cell45;
    QHBoxLayout *SudokuGridHorizontalLayer6;
    QLineEdit *cell46;
    QLineEdit *cell47;
    QLineEdit *cell48;
    QSpacerItem *HorizontalSpacer1VLayer6;
    QLineEdit *cell49;
    QLineEdit *cell50;
    QLineEdit *cell51;
    QSpacerItem *HorizontalSpacer2VLayer6;
    QLineEdit *cell52;
    QLineEdit *cell53;
    QLineEdit *cell54;
    QHBoxLayout *SudokuGridHorizontalLayer7;
    QLineEdit *cell55;
    QLineEdit *cell56;
    QLineEdit *cell57;
    QSpacerItem *HorizontalSpacer1VLayer7;
    QLineEdit *cell58;
    QLineEdit *cell59;
    QLineEdit *cell60;
    QSpacerItem *HorizontalSpacer2VLayer7;
    QLineEdit *cell61;
    QLineEdit *cell62;
    QLineEdit *cell63;
    QHBoxLayout *SudokuGridHorizontalLayer8;
    QLineEdit *cell64;
    QLineEdit *cell65;
    QLineEdit *cell66;
    QSpacerItem *HorizontalSpacer1VLayer8;
    QLineEdit *cell67;
    QLineEdit *cell68;
    QLineEdit *cell69;
    QSpacerItem *HorizontalSpacer2VLayer8;
    QLineEdit *cell70;
    QLineEdit *cell71;
    QLineEdit *cell72;
    QHBoxLayout *SudokuGridHorizontalLayer9;
    QLineEdit *cell73;
    QLineEdit *cell74;
    QLineEdit *cell75;
    QSpacerItem *HorizontalSpacer1VLayer9;
    QLineEdit *cell76;
    QLineEdit *cell77;
    QLineEdit *cell78;
    QSpacerItem *HorizontalSpacer2VLayer9;
    QLineEdit *cell79;
    QLineEdit *cell80;
    QLineEdit *cell81;
    QLabel *TimeLabel;
    QLabel *RepetitionLabel;
    QLabel *OperationLabel;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
	int method;
	int diffLevel;
	int repetitions;

	private:
		void changeCellsValue(int table[]){
			//pewnie bedzie sie przekazywac tablice z wynikiem i tablice wygenerowana i od tego uzalezniac kolor
		}

		void displayTime(string time){
			TimeField->setText(QString::fromStdString(time));
		}

		void displayOperations(string operations){
			OperationsField->setText(QString::fromStdString(operations));
		}

	public slots:
		//Klikniecie przycisku OK
		void okButtonClicked(){
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
		void setDifficultyLevel(int level){
			diffLevel=level+1;//wydaje mi sie ze indeksowanie od 0
		}
		void setRepetitionCount(const QString &){

		}

    void setupUi(QMainWindow *SudokuGUIClass)
    {
		method = 0;
		diffLevel=0;
		repetitions=0;
        if (SudokuGUIClass->objectName().isEmpty())
            SudokuGUIClass->setObjectName(QStringLiteral("SudokuGUIClass"));
        SudokuGUIClass->resize(670, 451);
        centralWidget = new QWidget(SudokuGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(670, 386));
        centralWidget->setMaximumSize(QSize(670, 386));

        okButton = new QPushButton(centralWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(530, 250, 93, 20));
        okButton->setMaximumSize(QSize(100, 20));
        okButton->setCursor(QCursor(Qt::OpenHandCursor));
		QObject::connect(okButton, SIGNAL(clicked()),centralWidget,SLOT(okButtonClicked()));

		QStringList levelsList=(QStringList()<<"Ekstremalnie latwy"<<"Latwy"<<"Sredni"<<"Trudny"<<"Piekielnie trudny");

        DifficultyLevelSelector = new QComboBox(centralWidget);
        DifficultyLevelSelector->setObjectName(QStringLiteral("DifficultyLevelSelector"));
        DifficultyLevelSelector->setGeometry(QRect(500, 170, 150, 20));
        DifficultyLevelSelector->setMinimumSize(QSize(150, 0));
        DifficultyLevelSelector->setMaximumSize(QSize(200, 20));
		DifficultyLevelSelector->addItems(levelsList);
		QObject::connect(DifficultyLevelSelector, SIGNAL(currentIndexChanged(int)),centralWidget,SLOT(setDifficultyLevel(int)));

        TimeField = new QLineEdit(centralWidget);
        TimeField->setObjectName(QStringLiteral("TimeField"));
        TimeField->setGeometry(QRect(500, 301, 137, 22));
        TimeField->setInputMethodHints(Qt::ImhDigitsOnly);
		TimeField->setReadOnly(true);

        DifficultyLevelLabel = new QLabel(centralWidget);
        DifficultyLevelLabel->setObjectName(QStringLiteral("DifficultyLevelLabel"));
        DifficultyLevelLabel->setGeometry(QRect(490, 150, 111, 16));

        RepetitionField = new QLineEdit(centralWidget);
        RepetitionField->setObjectName(QStringLiteral("RepetitionField"));
        RepetitionField->setGeometry(QRect(500, 223, 137, 22));
        RepetitionField->setInputMethodHints(Qt::ImhDigitsOnly);
		QObject::connect(RepetitionField, SIGNAL(textChanged(const QString &)),centralWidget, SLOT(setRepetitionCount(const QString &)));

        OperationsField = new QLineEdit(centralWidget);
        OperationsField->setObjectName(QStringLiteral("OperationsField"));
        OperationsField->setGeometry(QRect(500, 353, 137, 22));
        OperationsField->setInputMethodHints(Qt::ImhDigitsOnly);
		OperationsField->setReadOnly(true);

        MethodGroup = new QGroupBox(centralWidget);
        MethodGroup->setObjectName(QStringLiteral("MethodGroup"));
        MethodGroup->setGeometry(QRect(499, 32, 141, 100));
        MethodGroup->setMaximumSize(QSize(160, 100));

        layoutWidget_3 = new QWidget(MethodGroup);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 20, 125, 76));

        MethodLayout = new QVBoxLayout(layoutWidget_3);
        MethodLayout->setSpacing(6);
        MethodLayout->setContentsMargins(11, 11, 11, 11);
        MethodLayout->setObjectName(QStringLiteral("MethodLayout"));
        MethodLayout->setContentsMargins(0, 0, 0, 0);

        MostNeighboursButton = new QRadioButton(layoutWidget_3);
        MostNeighboursButton->setObjectName(QStringLiteral("MostNeighboursButton"));
        MostNeighboursButton->setChecked(true);
		QObject::connect(MostNeighboursButton, SIGNAL(clicked()), MethodGroup,SLOT(mostNeighboursSelected()));
        MethodLayout->addWidget(MostNeighboursButton);

        RandomButtom = new QRadioButton(layoutWidget_3);
        RandomButtom->setObjectName(QStringLiteral("RandomButtom"));
		QObject::connect(RandomButtom, SIGNAL(clicked()),MethodGroup,SLOT(randomSelected()));
        MethodLayout->addWidget(RandomButtom);

        layoutWidget_4 = new QWidget(centralWidget);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(0, 10, 481, 371));

        SudokuGridMainVerticalLayout = new QVBoxLayout(layoutWidget_4);
        SudokuGridMainVerticalLayout->setSpacing(6);
        SudokuGridMainVerticalLayout->setContentsMargins(11, 11, 11, 11);
        SudokuGridMainVerticalLayout->setObjectName(QStringLiteral("SudokuGridMainVerticalLayout"));
        SudokuGridMainVerticalLayout->setContentsMargins(0, 0, 0, 0);

        SudokuGridHorizontalLayer1 = new QHBoxLayout();
        SudokuGridHorizontalLayer1->setSpacing(6);
        SudokuGridHorizontalLayer1->setObjectName(QStringLiteral("SudokuGridHorizontalLayer1"));

        cell1 = new QLineEdit(layoutWidget_4);
        cell1->setObjectName(QStringLiteral("cell1"));
        cell1->setEnabled(true);
        sizePolicy.setHeightForWidth(cell1->sizePolicy().hasHeightForWidth());
        cell1->setSizePolicy(sizePolicy);
        cell1->setMinimumSize(QSize(25, 30));
        cell1->setMaximumSize(QSize(35, 40));
        QFont font;
        font.setFamily(QStringLiteral("Modern No. 20"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        cell1->setFont(font);
        cell1->setInputMethodHints(Qt::ImhDigitsOnly);
        cell1->setMaxLength(1);
        cell1->setAlignment(Qt::AlignCenter);
        cell1->setReadOnly(true);

        SudokuGridHorizontalLayer1->addWidget(cell1);

        cell2 = new QLineEdit(layoutWidget_4);
        cell2->setObjectName(QStringLiteral("cell2"));
        cell2->setEnabled(true);
        sizePolicy.setHeightForWidth(cell2->sizePolicy().hasHeightForWidth());
        cell2->setSizePolicy(sizePolicy);
        cell2->setMinimumSize(QSize(25, 30));
        cell2->setMaximumSize(QSize(35, 40));
        cell2->setFont(font);
        cell2->setInputMethodHints(Qt::ImhDigitsOnly);
        cell2->setMaxLength(1);
        cell2->setAlignment(Qt::AlignCenter);
        cell2->setReadOnly(true);

        SudokuGridHorizontalLayer1->addWidget(cell2);

        cell3 = new QLineEdit(layoutWidget_4);
        cell3->setObjectName(QStringLiteral("cell3"));
        cell3->setEnabled(true);
        sizePolicy.setHeightForWidth(cell3->sizePolicy().hasHeightForWidth());
        cell3->setSizePolicy(sizePolicy);
        cell3->setMinimumSize(QSize(25, 30));
        cell3->setMaximumSize(QSize(35, 40));
        cell3->setFont(font);
        cell3->setInputMethodHints(Qt::ImhDigitsOnly);
        cell3->setMaxLength(1);
        cell3->setAlignment(Qt::AlignCenter);
        cell3->setReadOnly(true);

        SudokuGridHorizontalLayer1->addWidget(cell3);

        HorizontalSpacer1VLayer1 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer1->addItem(HorizontalSpacer1VLayer1);

        cell4 = new QLineEdit(layoutWidget_4);
        cell4->setObjectName(QStringLiteral("cell4"));
        cell4->setEnabled(true);
        sizePolicy.setHeightForWidth(cell4->sizePolicy().hasHeightForWidth());
        cell4->setSizePolicy(sizePolicy);
        cell4->setMinimumSize(QSize(25, 30));
        cell4->setMaximumSize(QSize(35, 40));
        cell4->setFont(font);
        cell4->setInputMethodHints(Qt::ImhDigitsOnly);
        cell4->setMaxLength(1);
        cell4->setAlignment(Qt::AlignCenter);
        cell4->setReadOnly(true);

        SudokuGridHorizontalLayer1->addWidget(cell4);

        cell5 = new QLineEdit(layoutWidget_4);
        cell5->setObjectName(QStringLiteral("cell5"));
        sizePolicy.setHeightForWidth(cell5->sizePolicy().hasHeightForWidth());
        cell5->setSizePolicy(sizePolicy);
        cell5->setMinimumSize(QSize(25, 30));
        cell5->setMaximumSize(QSize(35, 40));
        cell5->setFont(font);
        cell5->setInputMethodHints(Qt::ImhDigitsOnly);
        cell5->setMaxLength(1);
        cell5->setAlignment(Qt::AlignCenter);
        cell5->setReadOnly(true);

        SudokuGridHorizontalLayer1->addWidget(cell5);

        cell6 = new QLineEdit(layoutWidget_4);
        cell6->setObjectName(QStringLiteral("cell6"));
        sizePolicy.setHeightForWidth(cell6->sizePolicy().hasHeightForWidth());
        cell6->setSizePolicy(sizePolicy);
        cell6->setMinimumSize(QSize(25, 30));
        cell6->setMaximumSize(QSize(35, 40));
        cell6->setFont(font);
        cell6->setInputMethodHints(Qt::ImhDigitsOnly);
        cell6->setMaxLength(1);
        cell6->setAlignment(Qt::AlignCenter);
        cell6->setReadOnly(true);

        SudokuGridHorizontalLayer1->addWidget(cell6);

        HorizontalSpacer2VLayer1 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer1->addItem(HorizontalSpacer2VLayer1);

        cell7 = new QLineEdit(layoutWidget_4);
        cell7->setObjectName(QStringLiteral("cell7"));
        sizePolicy.setHeightForWidth(cell7->sizePolicy().hasHeightForWidth());
        cell7->setSizePolicy(sizePolicy);
        cell7->setMinimumSize(QSize(25, 30));
        cell7->setMaximumSize(QSize(35, 40));
        cell7->setFont(font);
        cell7->setInputMethodHints(Qt::ImhDigitsOnly);
        cell7->setMaxLength(1);
        cell7->setAlignment(Qt::AlignCenter);
        cell7->setReadOnly(true);

        SudokuGridHorizontalLayer1->addWidget(cell7);

        cell8 = new QLineEdit(layoutWidget_4);
        cell8->setObjectName(QStringLiteral("cell8"));
        sizePolicy.setHeightForWidth(cell8->sizePolicy().hasHeightForWidth());
        cell8->setSizePolicy(sizePolicy);
        cell8->setMinimumSize(QSize(25, 30));
        cell8->setMaximumSize(QSize(35, 40));
        cell8->setFont(font);
        cell8->setInputMethodHints(Qt::ImhDigitsOnly);
        cell8->setMaxLength(1);
        cell8->setAlignment(Qt::AlignCenter);
        cell8->setReadOnly(true);

        SudokuGridHorizontalLayer1->addWidget(cell8);

        cell9 = new QLineEdit(layoutWidget_4);
        cell9->setObjectName(QStringLiteral("cell9"));
        sizePolicy.setHeightForWidth(cell9->sizePolicy().hasHeightForWidth());
        cell9->setSizePolicy(sizePolicy);
        cell9->setMinimumSize(QSize(25, 30));
        cell9->setMaximumSize(QSize(35, 40));
        cell9->setFont(font);
        cell9->setInputMethodHints(Qt::ImhDigitsOnly);
        cell9->setMaxLength(1);
        cell9->setAlignment(Qt::AlignCenter);
        cell9->setReadOnly(true);

        SudokuGridHorizontalLayer1->addWidget(cell9);


        SudokuGridMainVerticalLayout->addLayout(SudokuGridHorizontalLayer1);

        SudokuGridHorizontalLayer2 = new QHBoxLayout();
        SudokuGridHorizontalLayer2->setSpacing(6);
        SudokuGridHorizontalLayer2->setObjectName(QStringLiteral("SudokuGridHorizontalLayer2"));
        cell10 = new QLineEdit(layoutWidget_4);
        cell10->setObjectName(QStringLiteral("cell10"));
        sizePolicy.setHeightForWidth(cell10->sizePolicy().hasHeightForWidth());
        cell10->setSizePolicy(sizePolicy);
        cell10->setMinimumSize(QSize(25, 30));
        cell10->setMaximumSize(QSize(35, 40));
        cell10->setFont(font);
        cell10->setInputMethodHints(Qt::ImhDigitsOnly);
        cell10->setMaxLength(1);
        cell10->setAlignment(Qt::AlignCenter);
        cell10->setReadOnly(true);

        SudokuGridHorizontalLayer2->addWidget(cell10);

        cell11 = new QLineEdit(layoutWidget_4);
        cell11->setObjectName(QStringLiteral("cell11"));
        sizePolicy.setHeightForWidth(cell11->sizePolicy().hasHeightForWidth());
        cell11->setSizePolicy(sizePolicy);
        cell11->setMinimumSize(QSize(25, 30));
        cell11->setMaximumSize(QSize(35, 40));
        cell11->setFont(font);
        cell11->setInputMethodHints(Qt::ImhDigitsOnly);
        cell11->setMaxLength(1);
        cell11->setAlignment(Qt::AlignCenter);
        cell11->setReadOnly(true);

        SudokuGridHorizontalLayer2->addWidget(cell11);

        cell12 = new QLineEdit(layoutWidget_4);
        cell12->setObjectName(QStringLiteral("cell12"));
        sizePolicy.setHeightForWidth(cell12->sizePolicy().hasHeightForWidth());
        cell12->setSizePolicy(sizePolicy);
        cell12->setMinimumSize(QSize(25, 30));
        cell12->setMaximumSize(QSize(35, 40));
        cell12->setFont(font);
        cell12->setInputMethodHints(Qt::ImhDigitsOnly);
        cell12->setMaxLength(1);
        cell12->setAlignment(Qt::AlignCenter);
        cell12->setReadOnly(true);

        SudokuGridHorizontalLayer2->addWidget(cell12);

        HorizontalSpacer1VLayer2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer2->addItem(HorizontalSpacer1VLayer2);

        cell13 = new QLineEdit(layoutWidget_4);
        cell13->setObjectName(QStringLiteral("cell13"));
        sizePolicy.setHeightForWidth(cell13->sizePolicy().hasHeightForWidth());
        cell13->setSizePolicy(sizePolicy);
        cell13->setMinimumSize(QSize(25, 30));
        cell13->setMaximumSize(QSize(35, 40));
        cell13->setFont(font);
        cell13->setInputMethodHints(Qt::ImhDigitsOnly);
        cell13->setMaxLength(1);
        cell13->setAlignment(Qt::AlignCenter);
        cell13->setReadOnly(true);

        SudokuGridHorizontalLayer2->addWidget(cell13);

        cell14 = new QLineEdit(layoutWidget_4);
        cell14->setObjectName(QStringLiteral("cell14"));
        sizePolicy.setHeightForWidth(cell14->sizePolicy().hasHeightForWidth());
        cell14->setSizePolicy(sizePolicy);
        cell14->setMinimumSize(QSize(25, 30));
        cell14->setMaximumSize(QSize(35, 40));
        cell14->setFont(font);
        cell14->setInputMethodHints(Qt::ImhDigitsOnly);
        cell14->setMaxLength(1);
        cell14->setAlignment(Qt::AlignCenter);
        cell14->setReadOnly(true);

        SudokuGridHorizontalLayer2->addWidget(cell14);

        cell15 = new QLineEdit(layoutWidget_4);
        cell15->setObjectName(QStringLiteral("cell15"));
        sizePolicy.setHeightForWidth(cell15->sizePolicy().hasHeightForWidth());
        cell15->setSizePolicy(sizePolicy);
        cell15->setMinimumSize(QSize(25, 30));
        cell15->setMaximumSize(QSize(35, 40));
        cell15->setFont(font);
        cell15->setInputMethodHints(Qt::ImhDigitsOnly);
        cell15->setMaxLength(1);
        cell15->setAlignment(Qt::AlignCenter);
        cell15->setReadOnly(true);

        SudokuGridHorizontalLayer2->addWidget(cell15);

        HorizontalSpacer2VLayer2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer2->addItem(HorizontalSpacer2VLayer2);

        cell16 = new QLineEdit(layoutWidget_4);
        cell16->setObjectName(QStringLiteral("cell16"));
        sizePolicy.setHeightForWidth(cell16->sizePolicy().hasHeightForWidth());
        cell16->setSizePolicy(sizePolicy);
        cell16->setMinimumSize(QSize(25, 30));
        cell16->setMaximumSize(QSize(35, 40));
        cell16->setFont(font);
        cell16->setInputMethodHints(Qt::ImhDigitsOnly);
        cell16->setMaxLength(1);
        cell16->setAlignment(Qt::AlignCenter);
        cell16->setReadOnly(true);

        SudokuGridHorizontalLayer2->addWidget(cell16);

        cell17 = new QLineEdit(layoutWidget_4);
        cell17->setObjectName(QStringLiteral("cell17"));
        sizePolicy.setHeightForWidth(cell17->sizePolicy().hasHeightForWidth());
        cell17->setSizePolicy(sizePolicy);
        cell17->setMinimumSize(QSize(25, 30));
        cell17->setMaximumSize(QSize(35, 40));
        cell17->setFont(font);
        cell17->setInputMethodHints(Qt::ImhDigitsOnly);
        cell17->setMaxLength(1);
        cell17->setAlignment(Qt::AlignCenter);
        cell17->setReadOnly(true);

        SudokuGridHorizontalLayer2->addWidget(cell17);

        cell18 = new QLineEdit(layoutWidget_4);
        cell18->setObjectName(QStringLiteral("cell18"));
        sizePolicy.setHeightForWidth(cell18->sizePolicy().hasHeightForWidth());
        cell18->setSizePolicy(sizePolicy);
        cell18->setMinimumSize(QSize(25, 30));
        cell18->setMaximumSize(QSize(35, 40));
        cell18->setFont(font);
        cell18->setInputMethodHints(Qt::ImhDigitsOnly);
        cell18->setMaxLength(1);
        cell18->setAlignment(Qt::AlignCenter);
        cell18->setReadOnly(true);

        SudokuGridHorizontalLayer2->addWidget(cell18);


        SudokuGridMainVerticalLayout->addLayout(SudokuGridHorizontalLayer2);

        SudokuGridHorizontalLayer3 = new QHBoxLayout();
        SudokuGridHorizontalLayer3->setSpacing(6);
        SudokuGridHorizontalLayer3->setObjectName(QStringLiteral("SudokuGridHorizontalLayer3"));
        cell19 = new QLineEdit(layoutWidget_4);
        cell19->setObjectName(QStringLiteral("cell19"));
        sizePolicy.setHeightForWidth(cell19->sizePolicy().hasHeightForWidth());
        cell19->setSizePolicy(sizePolicy);
        cell19->setMinimumSize(QSize(25, 30));
        cell19->setMaximumSize(QSize(35, 40));
        cell19->setFont(font);
        cell19->setInputMethodHints(Qt::ImhDigitsOnly);
        cell19->setMaxLength(1);
        cell19->setAlignment(Qt::AlignCenter);
        cell19->setReadOnly(true);

        SudokuGridHorizontalLayer3->addWidget(cell19);

        cell20 = new QLineEdit(layoutWidget_4);
        cell20->setObjectName(QStringLiteral("cell20"));
        sizePolicy.setHeightForWidth(cell20->sizePolicy().hasHeightForWidth());
        cell20->setSizePolicy(sizePolicy);
        cell20->setMinimumSize(QSize(25, 30));
        cell20->setMaximumSize(QSize(35, 40));
        cell20->setFont(font);
        cell20->setInputMethodHints(Qt::ImhDigitsOnly);
        cell20->setMaxLength(1);
        cell20->setAlignment(Qt::AlignCenter);
        cell20->setReadOnly(true);

        SudokuGridHorizontalLayer3->addWidget(cell20);

        cell21 = new QLineEdit(layoutWidget_4);
        cell21->setObjectName(QStringLiteral("cell21"));
        sizePolicy.setHeightForWidth(cell21->sizePolicy().hasHeightForWidth());
        cell21->setSizePolicy(sizePolicy);
        cell21->setMinimumSize(QSize(25, 30));
        cell21->setMaximumSize(QSize(35, 40));
        cell21->setFont(font);
        cell21->setInputMethodHints(Qt::ImhDigitsOnly);
        cell21->setMaxLength(1);
        cell21->setAlignment(Qt::AlignCenter);
        cell21->setReadOnly(true);

        SudokuGridHorizontalLayer3->addWidget(cell21);

        HorizontalSpacer1VLayer3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer3->addItem(HorizontalSpacer1VLayer3);

        cell22 = new QLineEdit(layoutWidget_4);
        cell22->setObjectName(QStringLiteral("cell22"));
        sizePolicy.setHeightForWidth(cell22->sizePolicy().hasHeightForWidth());
        cell22->setSizePolicy(sizePolicy);
        cell22->setMinimumSize(QSize(25, 30));
        cell22->setMaximumSize(QSize(35, 40));
        cell22->setFont(font);
        cell22->setInputMethodHints(Qt::ImhDigitsOnly);
        cell22->setMaxLength(1);
        cell22->setAlignment(Qt::AlignCenter);
        cell22->setReadOnly(true);

        SudokuGridHorizontalLayer3->addWidget(cell22);

        cell23 = new QLineEdit(layoutWidget_4);
        cell23->setObjectName(QStringLiteral("cell23"));
        sizePolicy.setHeightForWidth(cell23->sizePolicy().hasHeightForWidth());
        cell23->setSizePolicy(sizePolicy);
        cell23->setMinimumSize(QSize(25, 30));
        cell23->setMaximumSize(QSize(35, 40));
        cell23->setFont(font);
        cell23->setInputMethodHints(Qt::ImhDigitsOnly);
        cell23->setMaxLength(1);
        cell23->setAlignment(Qt::AlignCenter);
        cell23->setReadOnly(true);

        SudokuGridHorizontalLayer3->addWidget(cell23);

        cell24 = new QLineEdit(layoutWidget_4);
        cell24->setObjectName(QStringLiteral("cell24"));
        sizePolicy.setHeightForWidth(cell24->sizePolicy().hasHeightForWidth());
        cell24->setSizePolicy(sizePolicy);
        cell24->setMinimumSize(QSize(25, 30));
        cell24->setMaximumSize(QSize(35, 40));
        cell24->setFont(font);
        cell24->setInputMethodHints(Qt::ImhDigitsOnly);
        cell24->setMaxLength(1);
        cell24->setAlignment(Qt::AlignCenter);
        cell24->setReadOnly(true);

        SudokuGridHorizontalLayer3->addWidget(cell24);

        HorizontalSpacer2VLayer3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer3->addItem(HorizontalSpacer2VLayer3);

        cell25 = new QLineEdit(layoutWidget_4);
        cell25->setObjectName(QStringLiteral("cell25"));
        sizePolicy.setHeightForWidth(cell25->sizePolicy().hasHeightForWidth());
        cell25->setSizePolicy(sizePolicy);
        cell25->setMinimumSize(QSize(25, 30));
        cell25->setMaximumSize(QSize(35, 40));
        cell25->setFont(font);
        cell25->setInputMethodHints(Qt::ImhDigitsOnly);
        cell25->setMaxLength(1);
        cell25->setAlignment(Qt::AlignCenter);
        cell25->setReadOnly(true);

        SudokuGridHorizontalLayer3->addWidget(cell25);

        cell26 = new QLineEdit(layoutWidget_4);
        cell26->setObjectName(QStringLiteral("cell26"));
        sizePolicy.setHeightForWidth(cell26->sizePolicy().hasHeightForWidth());
        cell26->setSizePolicy(sizePolicy);
        cell26->setMinimumSize(QSize(25, 30));
        cell26->setMaximumSize(QSize(35, 40));
        cell26->setFont(font);
        cell26->setInputMethodHints(Qt::ImhDigitsOnly);
        cell26->setMaxLength(1);
        cell26->setAlignment(Qt::AlignCenter);
        cell26->setReadOnly(true);

        SudokuGridHorizontalLayer3->addWidget(cell26);

        cell27 = new QLineEdit(layoutWidget_4);
        cell27->setObjectName(QStringLiteral("cell27"));
        sizePolicy.setHeightForWidth(cell27->sizePolicy().hasHeightForWidth());
        cell27->setSizePolicy(sizePolicy);
        cell27->setMinimumSize(QSize(25, 30));
        cell27->setMaximumSize(QSize(35, 40));
        cell27->setFont(font);
        cell27->setInputMethodHints(Qt::ImhDigitsOnly);
        cell27->setMaxLength(1);
        cell27->setAlignment(Qt::AlignCenter);
        cell27->setReadOnly(true);

        SudokuGridHorizontalLayer3->addWidget(cell27);


        SudokuGridMainVerticalLayout->addLayout(SudokuGridHorizontalLayer3);

        SudokuGridHorizontalLayer4 = new QHBoxLayout();
        SudokuGridHorizontalLayer4->setSpacing(6);
        SudokuGridHorizontalLayer4->setObjectName(QStringLiteral("SudokuGridHorizontalLayer4"));
        cell28 = new QLineEdit(layoutWidget_4);
        cell28->setObjectName(QStringLiteral("cell28"));
        sizePolicy.setHeightForWidth(cell28->sizePolicy().hasHeightForWidth());
        cell28->setSizePolicy(sizePolicy);
        cell28->setMinimumSize(QSize(25, 30));
        cell28->setMaximumSize(QSize(35, 40));
        cell28->setFont(font);
        cell28->setInputMethodHints(Qt::ImhDigitsOnly);
        cell28->setMaxLength(1);
        cell28->setAlignment(Qt::AlignCenter);
        cell28->setReadOnly(true);

        SudokuGridHorizontalLayer4->addWidget(cell28);

        cell29 = new QLineEdit(layoutWidget_4);
        cell29->setObjectName(QStringLiteral("cell29"));
        sizePolicy.setHeightForWidth(cell29->sizePolicy().hasHeightForWidth());
        cell29->setSizePolicy(sizePolicy);
        cell29->setMinimumSize(QSize(25, 30));
        cell29->setMaximumSize(QSize(35, 40));
        cell29->setFont(font);
        cell29->setInputMethodHints(Qt::ImhDigitsOnly);
        cell29->setMaxLength(1);
        cell29->setAlignment(Qt::AlignCenter);
        cell29->setReadOnly(true);

        SudokuGridHorizontalLayer4->addWidget(cell29);

        cell30 = new QLineEdit(layoutWidget_4);
        cell30->setObjectName(QStringLiteral("cell30"));
        sizePolicy.setHeightForWidth(cell30->sizePolicy().hasHeightForWidth());
        cell30->setSizePolicy(sizePolicy);
        cell30->setMinimumSize(QSize(25, 30));
        cell30->setMaximumSize(QSize(35, 40));
        cell30->setFont(font);
        cell30->setInputMethodHints(Qt::ImhDigitsOnly);
        cell30->setMaxLength(1);
        cell30->setAlignment(Qt::AlignCenter);
        cell30->setReadOnly(true);

        SudokuGridHorizontalLayer4->addWidget(cell30);

        HorizontalSpacer1VLayer4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer4->addItem(HorizontalSpacer1VLayer4);

        cell31 = new QLineEdit(layoutWidget_4);
        cell31->setObjectName(QStringLiteral("cell31"));
        sizePolicy.setHeightForWidth(cell31->sizePolicy().hasHeightForWidth());
        cell31->setSizePolicy(sizePolicy);
        cell31->setMinimumSize(QSize(25, 30));
        cell31->setMaximumSize(QSize(35, 40));
        cell31->setFont(font);
        cell31->setInputMethodHints(Qt::ImhDigitsOnly);
        cell31->setMaxLength(1);
        cell31->setAlignment(Qt::AlignCenter);
        cell31->setReadOnly(true);

        SudokuGridHorizontalLayer4->addWidget(cell31);

        cell32 = new QLineEdit(layoutWidget_4);
        cell32->setObjectName(QStringLiteral("cell32"));
        sizePolicy.setHeightForWidth(cell32->sizePolicy().hasHeightForWidth());
        cell32->setSizePolicy(sizePolicy);
        cell32->setMinimumSize(QSize(25, 30));
        cell32->setMaximumSize(QSize(35, 40));
        cell32->setFont(font);
        cell32->setInputMethodHints(Qt::ImhDigitsOnly);
        cell32->setMaxLength(1);
        cell32->setAlignment(Qt::AlignCenter);
        cell32->setReadOnly(true);

        SudokuGridHorizontalLayer4->addWidget(cell32);

        cell33 = new QLineEdit(layoutWidget_4);
        cell33->setObjectName(QStringLiteral("cell33"));
        sizePolicy.setHeightForWidth(cell33->sizePolicy().hasHeightForWidth());
        cell33->setSizePolicy(sizePolicy);
        cell33->setMinimumSize(QSize(25, 30));
        cell33->setMaximumSize(QSize(35, 40));
        cell33->setFont(font);
        cell33->setInputMethodHints(Qt::ImhDigitsOnly);
        cell33->setMaxLength(1);
        cell33->setAlignment(Qt::AlignCenter);
        cell33->setReadOnly(true);

        SudokuGridHorizontalLayer4->addWidget(cell33);

        HorizontalSpacer2VLayer4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer4->addItem(HorizontalSpacer2VLayer4);

        cell34 = new QLineEdit(layoutWidget_4);
        cell34->setObjectName(QStringLiteral("cell34"));
        sizePolicy.setHeightForWidth(cell34->sizePolicy().hasHeightForWidth());
        cell34->setSizePolicy(sizePolicy);
        cell34->setMinimumSize(QSize(25, 30));
        cell34->setMaximumSize(QSize(35, 40));
        cell34->setFont(font);
        cell34->setInputMethodHints(Qt::ImhDigitsOnly);
        cell34->setMaxLength(1);
        cell34->setAlignment(Qt::AlignCenter);
        cell34->setReadOnly(true);

        SudokuGridHorizontalLayer4->addWidget(cell34);

        cell35 = new QLineEdit(layoutWidget_4);
        cell35->setObjectName(QStringLiteral("cell35"));
        sizePolicy.setHeightForWidth(cell35->sizePolicy().hasHeightForWidth());
        cell35->setSizePolicy(sizePolicy);
        cell35->setMinimumSize(QSize(25, 30));
        cell35->setMaximumSize(QSize(35, 40));
        cell35->setFont(font);
        cell35->setInputMethodHints(Qt::ImhDigitsOnly);
        cell35->setMaxLength(1);
        cell35->setAlignment(Qt::AlignCenter);
        cell35->setReadOnly(true);

        SudokuGridHorizontalLayer4->addWidget(cell35);

        cell36 = new QLineEdit(layoutWidget_4);
        cell36->setObjectName(QStringLiteral("cell36"));
        sizePolicy.setHeightForWidth(cell36->sizePolicy().hasHeightForWidth());
        cell36->setSizePolicy(sizePolicy);
        cell36->setMinimumSize(QSize(25, 30));
        cell36->setMaximumSize(QSize(35, 40));
        cell36->setFont(font);
        cell36->setInputMethodHints(Qt::ImhDigitsOnly);
        cell36->setMaxLength(1);
        cell36->setAlignment(Qt::AlignCenter);
        cell36->setReadOnly(true);

        SudokuGridHorizontalLayer4->addWidget(cell36);


        SudokuGridMainVerticalLayout->addLayout(SudokuGridHorizontalLayer4);

        SudokuGridHorizontalLayer5 = new QHBoxLayout();
        SudokuGridHorizontalLayer5->setSpacing(6);
        SudokuGridHorizontalLayer5->setObjectName(QStringLiteral("SudokuGridHorizontalLayer5"));
        cell37 = new QLineEdit(layoutWidget_4);
        cell37->setObjectName(QStringLiteral("cell37"));
        sizePolicy.setHeightForWidth(cell37->sizePolicy().hasHeightForWidth());
        cell37->setSizePolicy(sizePolicy);
        cell37->setMinimumSize(QSize(25, 30));
        cell37->setMaximumSize(QSize(35, 40));
        cell37->setFont(font);
        cell37->setInputMethodHints(Qt::ImhDigitsOnly);
        cell37->setMaxLength(1);
        cell37->setAlignment(Qt::AlignCenter);
        cell37->setReadOnly(true);

        SudokuGridHorizontalLayer5->addWidget(cell37);

        cell38 = new QLineEdit(layoutWidget_4);
        cell38->setObjectName(QStringLiteral("cell38"));
        sizePolicy.setHeightForWidth(cell38->sizePolicy().hasHeightForWidth());
        cell38->setSizePolicy(sizePolicy);
        cell38->setMinimumSize(QSize(25, 30));
        cell38->setMaximumSize(QSize(35, 40));
        cell38->setFont(font);
        cell38->setInputMethodHints(Qt::ImhDigitsOnly);
        cell38->setMaxLength(1);
        cell38->setAlignment(Qt::AlignCenter);
        cell38->setReadOnly(true);

        SudokuGridHorizontalLayer5->addWidget(cell38);

        cell39 = new QLineEdit(layoutWidget_4);
        cell39->setObjectName(QStringLiteral("cell39"));
        sizePolicy.setHeightForWidth(cell39->sizePolicy().hasHeightForWidth());
        cell39->setSizePolicy(sizePolicy);
        cell39->setMinimumSize(QSize(25, 30));
        cell39->setMaximumSize(QSize(35, 40));
        cell39->setFont(font);
        cell39->setInputMethodHints(Qt::ImhDigitsOnly);
        cell39->setMaxLength(1);
        cell39->setAlignment(Qt::AlignCenter);
        cell39->setReadOnly(true);

        SudokuGridHorizontalLayer5->addWidget(cell39);

        HorizontalSpacer1VLayer5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer5->addItem(HorizontalSpacer1VLayer5);

        cell40 = new QLineEdit(layoutWidget_4);
        cell40->setObjectName(QStringLiteral("cell40"));
        sizePolicy.setHeightForWidth(cell40->sizePolicy().hasHeightForWidth());
        cell40->setSizePolicy(sizePolicy);
        cell40->setMinimumSize(QSize(25, 30));
        cell40->setMaximumSize(QSize(35, 40));
        cell40->setFont(font);
        cell40->setInputMethodHints(Qt::ImhDigitsOnly);
        cell40->setMaxLength(1);
        cell40->setAlignment(Qt::AlignCenter);
        cell40->setReadOnly(true);

        SudokuGridHorizontalLayer5->addWidget(cell40);

        cell41 = new QLineEdit(layoutWidget_4);
        cell41->setObjectName(QStringLiteral("cell41"));
        sizePolicy.setHeightForWidth(cell41->sizePolicy().hasHeightForWidth());
        cell41->setSizePolicy(sizePolicy);
        cell41->setMinimumSize(QSize(25, 30));
        cell41->setMaximumSize(QSize(35, 40));
        cell41->setFont(font);
        cell41->setInputMethodHints(Qt::ImhDigitsOnly);
        cell41->setMaxLength(1);
        cell41->setAlignment(Qt::AlignCenter);
        cell41->setReadOnly(true);

        SudokuGridHorizontalLayer5->addWidget(cell41);

        cell42 = new QLineEdit(layoutWidget_4);
        cell42->setObjectName(QStringLiteral("cell42"));
        sizePolicy.setHeightForWidth(cell42->sizePolicy().hasHeightForWidth());
        cell42->setSizePolicy(sizePolicy);
        cell42->setMinimumSize(QSize(25, 30));
        cell42->setMaximumSize(QSize(35, 40));
        cell42->setFont(font);
        cell42->setInputMethodHints(Qt::ImhDigitsOnly);
        cell42->setMaxLength(1);
        cell42->setAlignment(Qt::AlignCenter);
        cell42->setReadOnly(true);

        SudokuGridHorizontalLayer5->addWidget(cell42);

        HorizontalSpacer2VLayer5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer5->addItem(HorizontalSpacer2VLayer5);

        cell43 = new QLineEdit(layoutWidget_4);
        cell43->setObjectName(QStringLiteral("cell43"));
        sizePolicy.setHeightForWidth(cell43->sizePolicy().hasHeightForWidth());
        cell43->setSizePolicy(sizePolicy);
        cell43->setMinimumSize(QSize(25, 30));
        cell43->setMaximumSize(QSize(35, 40));
        cell43->setFont(font);
        cell43->setInputMethodHints(Qt::ImhDigitsOnly);
        cell43->setMaxLength(1);
        cell43->setAlignment(Qt::AlignCenter);
        cell43->setReadOnly(true);

        SudokuGridHorizontalLayer5->addWidget(cell43);

        cell44 = new QLineEdit(layoutWidget_4);
        cell44->setObjectName(QStringLiteral("cell44"));
        sizePolicy.setHeightForWidth(cell44->sizePolicy().hasHeightForWidth());
        cell44->setSizePolicy(sizePolicy);
        cell44->setMinimumSize(QSize(25, 30));
        cell44->setMaximumSize(QSize(35, 40));
        cell44->setFont(font);
        cell44->setInputMethodHints(Qt::ImhDigitsOnly);
        cell44->setMaxLength(1);
        cell44->setAlignment(Qt::AlignCenter);
        cell44->setReadOnly(true);

        SudokuGridHorizontalLayer5->addWidget(cell44);

        cell45 = new QLineEdit(layoutWidget_4);
        cell45->setObjectName(QStringLiteral("cell45"));
        sizePolicy.setHeightForWidth(cell45->sizePolicy().hasHeightForWidth());
        cell45->setSizePolicy(sizePolicy);
        cell45->setMinimumSize(QSize(25, 30));
        cell45->setMaximumSize(QSize(35, 40));
        cell45->setFont(font);
        cell45->setInputMethodHints(Qt::ImhDigitsOnly);
        cell45->setMaxLength(1);
        cell45->setAlignment(Qt::AlignCenter);
        cell45->setReadOnly(true);

        SudokuGridHorizontalLayer5->addWidget(cell45);


        SudokuGridMainVerticalLayout->addLayout(SudokuGridHorizontalLayer5);

        SudokuGridHorizontalLayer6 = new QHBoxLayout();
        SudokuGridHorizontalLayer6->setSpacing(6);
        SudokuGridHorizontalLayer6->setObjectName(QStringLiteral("SudokuGridHorizontalLayer6"));
        cell46 = new QLineEdit(layoutWidget_4);
        cell46->setObjectName(QStringLiteral("cell46"));
        sizePolicy.setHeightForWidth(cell46->sizePolicy().hasHeightForWidth());
        cell46->setSizePolicy(sizePolicy);
        cell46->setMinimumSize(QSize(25, 30));
        cell46->setMaximumSize(QSize(35, 40));
        cell46->setFont(font);
        cell46->setInputMethodHints(Qt::ImhDigitsOnly);
        cell46->setMaxLength(1);
        cell46->setAlignment(Qt::AlignCenter);
        cell46->setReadOnly(true);

        SudokuGridHorizontalLayer6->addWidget(cell46);

        cell47 = new QLineEdit(layoutWidget_4);
        cell47->setObjectName(QStringLiteral("cell47"));
        sizePolicy.setHeightForWidth(cell47->sizePolicy().hasHeightForWidth());
        cell47->setSizePolicy(sizePolicy);
        cell47->setMinimumSize(QSize(25, 30));
        cell47->setMaximumSize(QSize(35, 40));
        cell47->setFont(font);
        cell47->setInputMethodHints(Qt::ImhDigitsOnly);
        cell47->setMaxLength(1);
        cell47->setAlignment(Qt::AlignCenter);
        cell47->setReadOnly(true);

        SudokuGridHorizontalLayer6->addWidget(cell47);

        cell48 = new QLineEdit(layoutWidget_4);
        cell48->setObjectName(QStringLiteral("cell48"));
        sizePolicy.setHeightForWidth(cell48->sizePolicy().hasHeightForWidth());
        cell48->setSizePolicy(sizePolicy);
        cell48->setMinimumSize(QSize(25, 30));
        cell48->setMaximumSize(QSize(35, 40));
        cell48->setFont(font);
        cell48->setInputMethodHints(Qt::ImhDigitsOnly);
        cell48->setMaxLength(1);
        cell48->setAlignment(Qt::AlignCenter);
        cell48->setReadOnly(true);

        SudokuGridHorizontalLayer6->addWidget(cell48);

        HorizontalSpacer1VLayer6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer6->addItem(HorizontalSpacer1VLayer6);

        cell49 = new QLineEdit(layoutWidget_4);
        cell49->setObjectName(QStringLiteral("cell49"));
        sizePolicy.setHeightForWidth(cell49->sizePolicy().hasHeightForWidth());
        cell49->setSizePolicy(sizePolicy);
        cell49->setMinimumSize(QSize(25, 30));
        cell49->setMaximumSize(QSize(35, 40));
        cell49->setFont(font);
        cell49->setInputMethodHints(Qt::ImhDigitsOnly);
        cell49->setMaxLength(1);
        cell49->setAlignment(Qt::AlignCenter);
        cell49->setReadOnly(true);

        SudokuGridHorizontalLayer6->addWidget(cell49);

        cell50 = new QLineEdit(layoutWidget_4);
        cell50->setObjectName(QStringLiteral("cell50"));
        sizePolicy.setHeightForWidth(cell50->sizePolicy().hasHeightForWidth());
        cell50->setSizePolicy(sizePolicy);
        cell50->setMinimumSize(QSize(25, 30));
        cell50->setMaximumSize(QSize(35, 40));
        cell50->setFont(font);
        cell50->setInputMethodHints(Qt::ImhDigitsOnly);
        cell50->setMaxLength(1);
        cell50->setAlignment(Qt::AlignCenter);
        cell50->setReadOnly(true);

        SudokuGridHorizontalLayer6->addWidget(cell50);

        cell51 = new QLineEdit(layoutWidget_4);
        cell51->setObjectName(QStringLiteral("cell51"));
        sizePolicy.setHeightForWidth(cell51->sizePolicy().hasHeightForWidth());
        cell51->setSizePolicy(sizePolicy);
        cell51->setMinimumSize(QSize(25, 30));
        cell51->setMaximumSize(QSize(35, 40));
        cell51->setFont(font);
        cell51->setInputMethodHints(Qt::ImhDigitsOnly);
        cell51->setMaxLength(1);
        cell51->setAlignment(Qt::AlignCenter);
        cell51->setReadOnly(true);

        SudokuGridHorizontalLayer6->addWidget(cell51);

        HorizontalSpacer2VLayer6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer6->addItem(HorizontalSpacer2VLayer6);

        cell52 = new QLineEdit(layoutWidget_4);
        cell52->setObjectName(QStringLiteral("cell52"));
        sizePolicy.setHeightForWidth(cell52->sizePolicy().hasHeightForWidth());
        cell52->setSizePolicy(sizePolicy);
        cell52->setMinimumSize(QSize(25, 30));
        cell52->setMaximumSize(QSize(35, 40));
        cell52->setFont(font);
        cell52->setInputMethodHints(Qt::ImhDigitsOnly);
        cell52->setMaxLength(1);
        cell52->setAlignment(Qt::AlignCenter);
        cell52->setReadOnly(true);

        SudokuGridHorizontalLayer6->addWidget(cell52);

        cell53 = new QLineEdit(layoutWidget_4);
        cell53->setObjectName(QStringLiteral("cell53"));
        sizePolicy.setHeightForWidth(cell53->sizePolicy().hasHeightForWidth());
        cell53->setSizePolicy(sizePolicy);
        cell53->setMinimumSize(QSize(25, 30));
        cell53->setMaximumSize(QSize(35, 40));
        cell53->setFont(font);
        cell53->setInputMethodHints(Qt::ImhDigitsOnly);
        cell53->setMaxLength(1);
        cell53->setAlignment(Qt::AlignCenter);
        cell53->setReadOnly(true);

        SudokuGridHorizontalLayer6->addWidget(cell53);

        cell54 = new QLineEdit(layoutWidget_4);
        cell54->setObjectName(QStringLiteral("cell54"));
        sizePolicy.setHeightForWidth(cell54->sizePolicy().hasHeightForWidth());
        cell54->setSizePolicy(sizePolicy);
        cell54->setMinimumSize(QSize(25, 30));
        cell54->setMaximumSize(QSize(35, 40));
        cell54->setFont(font);
        cell54->setInputMethodHints(Qt::ImhDigitsOnly);
        cell54->setMaxLength(1);
        cell54->setAlignment(Qt::AlignCenter);
        cell54->setReadOnly(true);

        SudokuGridHorizontalLayer6->addWidget(cell54);


        SudokuGridMainVerticalLayout->addLayout(SudokuGridHorizontalLayer6);

        SudokuGridHorizontalLayer7 = new QHBoxLayout();
        SudokuGridHorizontalLayer7->setSpacing(6);
        SudokuGridHorizontalLayer7->setObjectName(QStringLiteral("SudokuGridHorizontalLayer7"));
        cell55 = new QLineEdit(layoutWidget_4);
        cell55->setObjectName(QStringLiteral("cell55"));
        sizePolicy.setHeightForWidth(cell55->sizePolicy().hasHeightForWidth());
        cell55->setSizePolicy(sizePolicy);
        cell55->setMinimumSize(QSize(25, 30));
        cell55->setMaximumSize(QSize(35, 40));
        cell55->setFont(font);
        cell55->setInputMethodHints(Qt::ImhDigitsOnly);
        cell55->setMaxLength(1);
        cell55->setAlignment(Qt::AlignCenter);
        cell55->setReadOnly(true);

        SudokuGridHorizontalLayer7->addWidget(cell55);

        cell56 = new QLineEdit(layoutWidget_4);
        cell56->setObjectName(QStringLiteral("cell56"));
        sizePolicy.setHeightForWidth(cell56->sizePolicy().hasHeightForWidth());
        cell56->setSizePolicy(sizePolicy);
        cell56->setMinimumSize(QSize(25, 30));
        cell56->setMaximumSize(QSize(35, 40));
        cell56->setFont(font);
        cell56->setInputMethodHints(Qt::ImhDigitsOnly);
        cell56->setMaxLength(1);
        cell56->setAlignment(Qt::AlignCenter);
        cell56->setReadOnly(true);

        SudokuGridHorizontalLayer7->addWidget(cell56);

        cell57 = new QLineEdit(layoutWidget_4);
        cell57->setObjectName(QStringLiteral("cell57"));
        sizePolicy.setHeightForWidth(cell57->sizePolicy().hasHeightForWidth());
        cell57->setSizePolicy(sizePolicy);
        cell57->setMinimumSize(QSize(25, 30));
        cell57->setMaximumSize(QSize(35, 40));
        cell57->setFont(font);
        cell57->setInputMethodHints(Qt::ImhDigitsOnly);
        cell57->setMaxLength(1);
        cell57->setAlignment(Qt::AlignCenter);
        cell57->setReadOnly(true);

        SudokuGridHorizontalLayer7->addWidget(cell57);

        HorizontalSpacer1VLayer7 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer7->addItem(HorizontalSpacer1VLayer7);

        cell58 = new QLineEdit(layoutWidget_4);
        cell58->setObjectName(QStringLiteral("cell58"));
        sizePolicy.setHeightForWidth(cell58->sizePolicy().hasHeightForWidth());
        cell58->setSizePolicy(sizePolicy);
        cell58->setMinimumSize(QSize(25, 30));
        cell58->setMaximumSize(QSize(35, 40));
        cell58->setFont(font);
        cell58->setInputMethodHints(Qt::ImhDigitsOnly);
        cell58->setMaxLength(1);
        cell58->setAlignment(Qt::AlignCenter);
        cell58->setReadOnly(true);

        SudokuGridHorizontalLayer7->addWidget(cell58);

        cell59 = new QLineEdit(layoutWidget_4);
        cell59->setObjectName(QStringLiteral("cell59"));
        sizePolicy.setHeightForWidth(cell59->sizePolicy().hasHeightForWidth());
        cell59->setSizePolicy(sizePolicy);
        cell59->setMinimumSize(QSize(25, 30));
        cell59->setMaximumSize(QSize(35, 40));
        cell59->setFont(font);
        cell59->setInputMethodHints(Qt::ImhDigitsOnly);
        cell59->setMaxLength(1);
        cell59->setAlignment(Qt::AlignCenter);
        cell59->setReadOnly(true);

        SudokuGridHorizontalLayer7->addWidget(cell59);

        cell60 = new QLineEdit(layoutWidget_4);
        cell60->setObjectName(QStringLiteral("cell60"));
        sizePolicy.setHeightForWidth(cell60->sizePolicy().hasHeightForWidth());
        cell60->setSizePolicy(sizePolicy);
        cell60->setMinimumSize(QSize(25, 30));
        cell60->setMaximumSize(QSize(35, 40));
        cell60->setFont(font);
        cell60->setInputMethodHints(Qt::ImhDigitsOnly);
        cell60->setMaxLength(1);
        cell60->setAlignment(Qt::AlignCenter);
        cell60->setReadOnly(true);

        SudokuGridHorizontalLayer7->addWidget(cell60);

        HorizontalSpacer2VLayer7 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer7->addItem(HorizontalSpacer2VLayer7);

        cell61 = new QLineEdit(layoutWidget_4);
        cell61->setObjectName(QStringLiteral("cell61"));
        sizePolicy.setHeightForWidth(cell61->sizePolicy().hasHeightForWidth());
        cell61->setSizePolicy(sizePolicy);
        cell61->setMinimumSize(QSize(25, 30));
        cell61->setMaximumSize(QSize(35, 40));
        cell61->setFont(font);
        cell61->setInputMethodHints(Qt::ImhDigitsOnly);
        cell61->setMaxLength(1);
        cell61->setAlignment(Qt::AlignCenter);
        cell61->setReadOnly(true);

        SudokuGridHorizontalLayer7->addWidget(cell61);

        cell62 = new QLineEdit(layoutWidget_4);
        cell62->setObjectName(QStringLiteral("cell62"));
        sizePolicy.setHeightForWidth(cell62->sizePolicy().hasHeightForWidth());
        cell62->setSizePolicy(sizePolicy);
        cell62->setMinimumSize(QSize(25, 30));
        cell62->setMaximumSize(QSize(35, 40));
        cell62->setFont(font);
        cell62->setInputMethodHints(Qt::ImhDigitsOnly);
        cell62->setMaxLength(1);
        cell62->setAlignment(Qt::AlignCenter);
        cell62->setReadOnly(true);

        SudokuGridHorizontalLayer7->addWidget(cell62);

        cell63 = new QLineEdit(layoutWidget_4);
        cell63->setObjectName(QStringLiteral("cell63"));
        sizePolicy.setHeightForWidth(cell63->sizePolicy().hasHeightForWidth());
        cell63->setSizePolicy(sizePolicy);
        cell63->setMinimumSize(QSize(25, 30));
        cell63->setMaximumSize(QSize(35, 40));
        cell63->setFont(font);
        cell63->setInputMethodHints(Qt::ImhDigitsOnly);
        cell63->setMaxLength(1);
        cell63->setAlignment(Qt::AlignCenter);
        cell63->setReadOnly(true);

        SudokuGridHorizontalLayer7->addWidget(cell63);


        SudokuGridMainVerticalLayout->addLayout(SudokuGridHorizontalLayer7);

        SudokuGridHorizontalLayer8 = new QHBoxLayout();
        SudokuGridHorizontalLayer8->setSpacing(6);
        SudokuGridHorizontalLayer8->setObjectName(QStringLiteral("SudokuGridHorizontalLayer8"));
        cell64 = new QLineEdit(layoutWidget_4);
        cell64->setObjectName(QStringLiteral("cell64"));
        sizePolicy.setHeightForWidth(cell64->sizePolicy().hasHeightForWidth());
        cell64->setSizePolicy(sizePolicy);
        cell64->setMinimumSize(QSize(25, 30));
        cell64->setMaximumSize(QSize(35, 40));
        cell64->setFont(font);
        cell64->setInputMethodHints(Qt::ImhDigitsOnly);
        cell64->setMaxLength(1);
        cell64->setAlignment(Qt::AlignCenter);
        cell64->setReadOnly(true);

        SudokuGridHorizontalLayer8->addWidget(cell64);

        cell65 = new QLineEdit(layoutWidget_4);
        cell65->setObjectName(QStringLiteral("cell65"));
        sizePolicy.setHeightForWidth(cell65->sizePolicy().hasHeightForWidth());
        cell65->setSizePolicy(sizePolicy);
        cell65->setMinimumSize(QSize(25, 30));
        cell65->setMaximumSize(QSize(35, 40));
        cell65->setFont(font);
        cell65->setInputMethodHints(Qt::ImhDigitsOnly);
        cell65->setMaxLength(1);
        cell65->setAlignment(Qt::AlignCenter);
        cell65->setReadOnly(true);

        SudokuGridHorizontalLayer8->addWidget(cell65);

        cell66 = new QLineEdit(layoutWidget_4);
        cell66->setObjectName(QStringLiteral("cell66"));
        sizePolicy.setHeightForWidth(cell66->sizePolicy().hasHeightForWidth());
        cell66->setSizePolicy(sizePolicy);
        cell66->setMinimumSize(QSize(25, 30));
        cell66->setMaximumSize(QSize(35, 40));
        cell66->setFont(font);
        cell66->setInputMethodHints(Qt::ImhDigitsOnly);
        cell66->setMaxLength(1);
        cell66->setAlignment(Qt::AlignCenter);
        cell66->setReadOnly(true);

        SudokuGridHorizontalLayer8->addWidget(cell66);

        HorizontalSpacer1VLayer8 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer8->addItem(HorizontalSpacer1VLayer8);

        cell67 = new QLineEdit(layoutWidget_4);
        cell67->setObjectName(QStringLiteral("cell67"));
        sizePolicy.setHeightForWidth(cell67->sizePolicy().hasHeightForWidth());
        cell67->setSizePolicy(sizePolicy);
        cell67->setMinimumSize(QSize(25, 30));
        cell67->setMaximumSize(QSize(35, 40));
        cell67->setFont(font);
        cell67->setInputMethodHints(Qt::ImhDigitsOnly);
        cell67->setMaxLength(1);
        cell67->setAlignment(Qt::AlignCenter);
        cell67->setReadOnly(true);

        SudokuGridHorizontalLayer8->addWidget(cell67);

        cell68 = new QLineEdit(layoutWidget_4);
        cell68->setObjectName(QStringLiteral("cell68"));
        sizePolicy.setHeightForWidth(cell68->sizePolicy().hasHeightForWidth());
        cell68->setSizePolicy(sizePolicy);
        cell68->setMinimumSize(QSize(25, 30));
        cell68->setMaximumSize(QSize(35, 40));
        cell68->setFont(font);
        cell68->setInputMethodHints(Qt::ImhDigitsOnly);
        cell68->setMaxLength(1);
        cell68->setAlignment(Qt::AlignCenter);
        cell68->setReadOnly(true);

        SudokuGridHorizontalLayer8->addWidget(cell68);

        cell69 = new QLineEdit(layoutWidget_4);
        cell69->setObjectName(QStringLiteral("cell69"));
        sizePolicy.setHeightForWidth(cell69->sizePolicy().hasHeightForWidth());
        cell69->setSizePolicy(sizePolicy);
        cell69->setMinimumSize(QSize(25, 30));
        cell69->setMaximumSize(QSize(35, 40));
        cell69->setFont(font);
        cell69->setInputMethodHints(Qt::ImhDigitsOnly);
        cell69->setMaxLength(1);
        cell69->setAlignment(Qt::AlignCenter);
        cell69->setReadOnly(true);

        SudokuGridHorizontalLayer8->addWidget(cell69);

        HorizontalSpacer2VLayer8 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer8->addItem(HorizontalSpacer2VLayer8);

        cell70 = new QLineEdit(layoutWidget_4);
        cell70->setObjectName(QStringLiteral("cell70"));
        sizePolicy.setHeightForWidth(cell70->sizePolicy().hasHeightForWidth());
        cell70->setSizePolicy(sizePolicy);
        cell70->setMinimumSize(QSize(25, 30));
        cell70->setMaximumSize(QSize(35, 40));
        cell70->setFont(font);
        cell70->setInputMethodHints(Qt::ImhDigitsOnly);
        cell70->setMaxLength(1);
        cell70->setAlignment(Qt::AlignCenter);
        cell70->setReadOnly(true);

        SudokuGridHorizontalLayer8->addWidget(cell70);

        cell71 = new QLineEdit(layoutWidget_4);
        cell71->setObjectName(QStringLiteral("cell71"));
        sizePolicy.setHeightForWidth(cell71->sizePolicy().hasHeightForWidth());
        cell71->setSizePolicy(sizePolicy);
        cell71->setMinimumSize(QSize(25, 30));
        cell71->setMaximumSize(QSize(35, 40));
        cell71->setFont(font);
        cell71->setInputMethodHints(Qt::ImhDigitsOnly);
        cell71->setMaxLength(1);
        cell71->setAlignment(Qt::AlignCenter);
        cell71->setReadOnly(true);

        SudokuGridHorizontalLayer8->addWidget(cell71);

        cell72 = new QLineEdit(layoutWidget_4);
        cell72->setObjectName(QStringLiteral("cell72"));
        sizePolicy.setHeightForWidth(cell72->sizePolicy().hasHeightForWidth());
        cell72->setSizePolicy(sizePolicy);
        cell72->setMinimumSize(QSize(25, 30));
        cell72->setMaximumSize(QSize(35, 40));
        cell72->setFont(font);
        cell72->setInputMethodHints(Qt::ImhDigitsOnly);
        cell72->setMaxLength(1);
        cell72->setAlignment(Qt::AlignCenter);
        cell72->setReadOnly(true);

        SudokuGridHorizontalLayer8->addWidget(cell72);


        SudokuGridMainVerticalLayout->addLayout(SudokuGridHorizontalLayer8);

        SudokuGridHorizontalLayer9 = new QHBoxLayout();
        SudokuGridHorizontalLayer9->setSpacing(6);
        SudokuGridHorizontalLayer9->setObjectName(QStringLiteral("SudokuGridHorizontalLayer9"));
        cell73 = new QLineEdit(layoutWidget_4);
        cell73->setObjectName(QStringLiteral("cell73"));
        sizePolicy.setHeightForWidth(cell73->sizePolicy().hasHeightForWidth());
        cell73->setSizePolicy(sizePolicy);
        cell73->setMinimumSize(QSize(25, 30));
        cell73->setMaximumSize(QSize(35, 40));
        cell73->setFont(font);
        cell73->setInputMethodHints(Qt::ImhDigitsOnly);
        cell73->setMaxLength(1);
        cell73->setAlignment(Qt::AlignCenter);
        cell73->setReadOnly(true);

        SudokuGridHorizontalLayer9->addWidget(cell73);

        cell74 = new QLineEdit(layoutWidget_4);
        cell74->setObjectName(QStringLiteral("cell74"));
        sizePolicy.setHeightForWidth(cell74->sizePolicy().hasHeightForWidth());
        cell74->setSizePolicy(sizePolicy);
        cell74->setMinimumSize(QSize(25, 30));
        cell74->setMaximumSize(QSize(35, 40));
        cell74->setFont(font);
        cell74->setInputMethodHints(Qt::ImhDigitsOnly);
        cell74->setMaxLength(1);
        cell74->setAlignment(Qt::AlignCenter);
        cell74->setReadOnly(true);

        SudokuGridHorizontalLayer9->addWidget(cell74);

        cell75 = new QLineEdit(layoutWidget_4);
        cell75->setObjectName(QStringLiteral("cell75"));
        sizePolicy.setHeightForWidth(cell75->sizePolicy().hasHeightForWidth());
        cell75->setSizePolicy(sizePolicy);
        cell75->setMinimumSize(QSize(25, 30));
        cell75->setMaximumSize(QSize(35, 40));
        cell75->setFont(font);
        cell75->setInputMethodHints(Qt::ImhDigitsOnly);
        cell75->setMaxLength(1);
        cell75->setAlignment(Qt::AlignCenter);
        cell75->setReadOnly(true);

        SudokuGridHorizontalLayer9->addWidget(cell75);

        HorizontalSpacer1VLayer9 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer9->addItem(HorizontalSpacer1VLayer9);

        cell76 = new QLineEdit(layoutWidget_4);
        cell76->setObjectName(QStringLiteral("cell76"));
        sizePolicy.setHeightForWidth(cell76->sizePolicy().hasHeightForWidth());
        cell76->setSizePolicy(sizePolicy);
        cell76->setMinimumSize(QSize(25, 30));
        cell76->setMaximumSize(QSize(35, 40));
        cell76->setFont(font);
        cell76->setInputMethodHints(Qt::ImhDigitsOnly);
        cell76->setMaxLength(1);
        cell76->setAlignment(Qt::AlignCenter);
        cell76->setReadOnly(true);

        SudokuGridHorizontalLayer9->addWidget(cell76);

        cell77 = new QLineEdit(layoutWidget_4);
        cell77->setObjectName(QStringLiteral("cell77"));
        sizePolicy.setHeightForWidth(cell77->sizePolicy().hasHeightForWidth());
        cell77->setSizePolicy(sizePolicy);
        cell77->setMinimumSize(QSize(25, 30));
        cell77->setMaximumSize(QSize(35, 40));
        cell77->setFont(font);
        cell77->setInputMethodHints(Qt::ImhDigitsOnly);
        cell77->setMaxLength(1);
        cell77->setAlignment(Qt::AlignCenter);
        cell77->setReadOnly(true);

        SudokuGridHorizontalLayer9->addWidget(cell77);

        cell78 = new QLineEdit(layoutWidget_4);
        cell78->setObjectName(QStringLiteral("cell78"));
        sizePolicy.setHeightForWidth(cell78->sizePolicy().hasHeightForWidth());
        cell78->setSizePolicy(sizePolicy);
        cell78->setMinimumSize(QSize(25, 30));
        cell78->setMaximumSize(QSize(35, 40));
        cell78->setFont(font);
        cell78->setInputMethodHints(Qt::ImhDigitsOnly);
        cell78->setMaxLength(1);
        cell78->setAlignment(Qt::AlignCenter);
        cell78->setReadOnly(true);

        SudokuGridHorizontalLayer9->addWidget(cell78);

        HorizontalSpacer2VLayer9 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SudokuGridHorizontalLayer9->addItem(HorizontalSpacer2VLayer9);

        cell79 = new QLineEdit(layoutWidget_4);
        cell79->setObjectName(QStringLiteral("cell79"));
        sizePolicy.setHeightForWidth(cell79->sizePolicy().hasHeightForWidth());
        cell79->setSizePolicy(sizePolicy);
        cell79->setMinimumSize(QSize(25, 30));
        cell79->setMaximumSize(QSize(35, 40));
        cell79->setFont(font);
        cell79->setInputMethodHints(Qt::ImhDigitsOnly);
        cell79->setMaxLength(1);
        cell79->setAlignment(Qt::AlignCenter);
        cell79->setReadOnly(true);

        SudokuGridHorizontalLayer9->addWidget(cell79);

        cell80 = new QLineEdit(layoutWidget_4);
        cell80->setObjectName(QStringLiteral("cell80"));
        sizePolicy.setHeightForWidth(cell80->sizePolicy().hasHeightForWidth());
        cell80->setSizePolicy(sizePolicy);
        cell80->setMinimumSize(QSize(25, 30));
        cell80->setMaximumSize(QSize(35, 40));
        cell80->setFont(font);
        cell80->setInputMethodHints(Qt::ImhDigitsOnly);
        cell80->setMaxLength(1);
        cell80->setAlignment(Qt::AlignCenter);
        cell80->setReadOnly(true);

        SudokuGridHorizontalLayer9->addWidget(cell80);

        cell81 = new QLineEdit(layoutWidget_4);
        cell81->setObjectName(QStringLiteral("cell81"));
        sizePolicy.setHeightForWidth(cell81->sizePolicy().hasHeightForWidth());
        cell81->setSizePolicy(sizePolicy);
        cell81->setMinimumSize(QSize(25, 30));
        cell81->setMaximumSize(QSize(35, 40));
        cell81->setFont(font);
        cell81->setInputMethodHints(Qt::ImhDigitsOnly);
        cell81->setMaxLength(1);
        cell81->setAlignment(Qt::AlignCenter);
        cell81->setReadOnly(true);

        SudokuGridHorizontalLayer9->addWidget(cell81);


        SudokuGridMainVerticalLayout->addLayout(SudokuGridHorizontalLayer9);

        TimeLabel = new QLabel(centralWidget);
        TimeLabel->setObjectName(QStringLiteral("TimeLabel"));
        TimeLabel->setGeometry(QRect(490, 278, 104, 16));
        RepetitionLabel = new QLabel(centralWidget);
        RepetitionLabel->setObjectName(QStringLiteral("RepetitionLabel"));
        RepetitionLabel->setGeometry(QRect(490, 200, 104, 16));
        OperationLabel = new QLabel(centralWidget);
        OperationLabel->setObjectName(QStringLiteral("OperationLabel"));
        OperationLabel->setGeometry(QRect(490, 330, 104, 16));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(150, 10, 21, 371));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(310, 10, 21, 371));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 120, 481, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 250, 481, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        SudokuGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SudokuGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 670, 26));
        SudokuGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SudokuGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SudokuGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SudokuGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setMinimumSize(QSize(670, 18));
        statusBar->setMaximumSize(QSize(670, 18));
        SudokuGUIClass->setStatusBar(statusBar);

        retranslateUi(SudokuGUIClass);

        QMetaObject::connectSlotsByName(SudokuGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *SudokuGUIClass)
    {
        SudokuGUIClass->setWindowTitle(QApplication::translate("SudokuGUIClass", "SudokuGUI", 0));
        okButton->setText(QApplication::translate("SudokuGUIClass", "OK", 0));
        TimeField->setText(QApplication::translate("SudokuGUIClass", "0", 0));
        DifficultyLevelLabel->setText(QApplication::translate("SudokuGUIClass", "Poziom trudno\305\233ci:", 0));
        RepetitionField->setText(QApplication::translate("SudokuGUIClass", "0", 0));
        OperationsField->setText(QApplication::translate("SudokuGUIClass", "0", 0));
        MethodGroup->setTitle(QApplication::translate("SudokuGUIClass", "Spos\303\263b rozwi\304\205zania", 0));
        MostNeighboursButton->setText(QApplication::translate("SudokuGUIClass", "Najbli\305\274si s\304\205siedzi", 0));
        RandomButtom->setText(QApplication::translate("SudokuGUIClass", "Losowo", 0));
        cell1->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell2->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell3->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell4->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell5->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell6->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell7->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell8->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell9->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell10->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell11->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell12->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell13->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell14->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell15->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell16->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell17->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell18->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell19->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell20->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell21->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell22->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell23->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell24->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell25->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell26->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell27->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell28->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell29->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell30->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell31->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell32->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell33->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell34->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell35->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell36->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell37->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell38->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell39->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell40->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell41->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell42->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell43->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell44->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell45->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell46->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell47->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell48->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell49->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell50->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell51->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell52->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell53->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell54->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell55->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell56->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell57->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell58->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell59->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell60->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell61->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell62->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell63->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell64->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell65->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell66->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell67->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell68->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell69->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell70->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell71->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell72->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell73->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell74->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell75->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell76->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell77->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell78->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell79->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell80->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        cell81->setText(QApplication::translate("SudokuGUIClass", "9", 0));
        TimeLabel->setText(QApplication::translate("SudokuGUIClass", "Czas rozwi\304\205zania:", 0));
        RepetitionLabel->setText(QApplication::translate("SudokuGUIClass", "Liczba powtorze\305\204:", 0));
        OperationLabel->setText(QApplication::translate("SudokuGUIClass", "Liczba operacji:", 0));
    } // retranslateUi

};

namespace Ui {
    class SudokuGUIClass: public Ui_SudokuGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUGUI_H
