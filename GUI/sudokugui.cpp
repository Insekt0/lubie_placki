#include "sudokugui.h"

#include <sstream>

SudokuGUI::SudokuGUI(QWidget *parent)
    : QMainWindow(parent), m_solveMethod(MOST_NEIGHBOURS), m_level(EXTREMELY_EASY), m_repetitionsCount(0)
{
    QStringList levelsList=(QStringList()<<"Ekstremalnie latwy"<<"Latwy"<<"Sredni"<<"Trudny"<<"Piekielnie trudny");
    ui.setupUi(this);
    moveCellsIntoTable();
    ui.DifficultyLevelSelector->addItems(levelsList);
    QObject::connect(ui.generateButton, SIGNAL(clicked()),this,SLOT(generateButtonClicked()));
    QObject::connect(ui.solveButton, SIGNAL(clicked()),this,SLOT(solveButtonClicked()));
    QObject::connect(ui.DifficultyLevelSelector, SIGNAL(currentIndexChanged(int)),this,SLOT(setDifficultyLevel(int)));
    QObject::connect(ui.RepetitionField, SIGNAL(textChanged(const QString &)),this, SLOT(setRepetitionCount(const QString &)));
    QObject::connect(ui.MostNeighboursButton, SIGNAL(clicked()), this,SLOT(mostNeighboursSelected()));
    QObject::connect(ui.RandomButtom, SIGNAL(clicked()),this,SLOT(randomSelected()));
    ui.OperationsField->setText("");
    ui.TimeField->setText("");
    for (int i = 0; i < 81; ++i)
    {
        m_sudokuGeneratedArray[i] = 0;
        m_sudokuSolvedArray[i] = 0;
    }
    changeCellsValue(m_sudokuGeneratedArray);
}


void SudokuGUI::displayTime(long long time){
    ostringstream ss;
    ss << time/1000000 << "s " << (time % 1000000)/1000 << "ms " << (time % 1000) << "us ";
    ui.TimeField->setText(QString::fromStdString(ss.str()));
}

void SudokuGUI::changeGridToArray(int* table){
    for(int i = 0; i < 81; ++i)
        table[i] = m_cellsArray[i]->text().toInt();
}

void SudokuGUI::changeCellsValue(int* table, bool justAfterSolve){
    
    QFont fontNormal("Times", 15, QFont::Light, false);
    QFont fontBold("Times", 18, QFont::Bold, false);
    for (int i=0; i<81;++i) 
    {
        if(!table[i])
            m_cellsArray[i]->setText("");
        else
            m_cellsArray[i]->setText(QString::number(table[i]));

        if (justAfterSolve && m_sudokuSolvedArray[i] != m_sudokuGeneratedArray[i])
            m_cellsArray[i]->setFont(fontBold);
        else
            m_cellsArray[i]->setFont(fontNormal);
    }
}

void SudokuGUI::displayOperations(long long operations) {
    ostringstream ss;
    ss << operations;
    ui.OperationsField->setText(QString::fromStdString(ss.str()));
}

void SudokuGUI::generateButtonClicked() {
    generate();
}

void SudokuGUI::generate() {
    srand(unsigned(time(0)));
    ui.OperationsField->setText("");
    ui.TimeField->setText("");
    SudokuGenerator generator;
    generator.generate(m_sudokuGeneratedArray, m_level);
    changeCellsValue(m_sudokuGeneratedArray);
}

void SudokuGUI::solveButtonClicked() {
    solve();
    unsigned counter = 1;
    
    while(counter < m_repetitionsCount)
    {
        ++counter;
        generate();
        solve();
    }
}

void SudokuGUI::solve() {
    SudokuSolver solver(m_sudokuGeneratedArray);
    int* result = solver.solve(m_solveMethod);
    for (int i = 0; i < 81; ++i)
        m_sudokuSolvedArray[i] = result[i];
    displayTime(solver.getSolveTime());
    displayOperations(solver.getSolveComplexity());
    changeCellsValue(m_sudokuSolvedArray, true);
}

void SudokuGUI::moveCellsIntoTable() {
    m_cellsArray[0] = ui.cell1;
    m_cellsArray[1] = ui.cell2;
    m_cellsArray[2] = ui.cell3;
    m_cellsArray[3] = ui.cell4;
    m_cellsArray[4] = ui.cell5;
    m_cellsArray[5] = ui.cell6;
    m_cellsArray[6] = ui.cell7;
    m_cellsArray[7] = ui.cell8;
    m_cellsArray[8] = ui.cell9;
    m_cellsArray[9] = ui.cell10;
    m_cellsArray[10] = ui.cell11;
    m_cellsArray[11] = ui.cell12;
    m_cellsArray[12] = ui.cell13;
    m_cellsArray[13] = ui.cell14;
    m_cellsArray[14] = ui.cell15;
    m_cellsArray[15] = ui.cell16;
    m_cellsArray[16] = ui.cell17;
    m_cellsArray[17] = ui.cell18;
    m_cellsArray[18] = ui.cell19;
    m_cellsArray[19] = ui.cell20;
    m_cellsArray[20] = ui.cell21;
    m_cellsArray[21] = ui.cell22;
    m_cellsArray[22] = ui.cell23;
    m_cellsArray[23] = ui.cell24;
    m_cellsArray[24] = ui.cell25;
    m_cellsArray[25] = ui.cell26;
    m_cellsArray[26] = ui.cell27;
    m_cellsArray[27] = ui.cell28;
    m_cellsArray[28] = ui.cell29;
    m_cellsArray[29] = ui.cell30;
    m_cellsArray[30] = ui.cell31;
    m_cellsArray[31] = ui.cell32;
    m_cellsArray[32] = ui.cell33;
    m_cellsArray[33] = ui.cell34;
    m_cellsArray[34] = ui.cell35;
    m_cellsArray[35] = ui.cell36;
    m_cellsArray[36] = ui.cell37;
    m_cellsArray[37] = ui.cell38;
    m_cellsArray[38] = ui.cell39;
    m_cellsArray[39] = ui.cell40;
    m_cellsArray[40] = ui.cell41;
    m_cellsArray[41] = ui.cell42;
    m_cellsArray[42] = ui.cell43;
    m_cellsArray[43] = ui.cell44;
    m_cellsArray[44] = ui.cell45;
    m_cellsArray[45] = ui.cell46;
    m_cellsArray[46] = ui.cell47;
    m_cellsArray[47] = ui.cell48;
    m_cellsArray[48] = ui.cell49;
    m_cellsArray[49] = ui.cell50;
    m_cellsArray[50] = ui.cell51;
    m_cellsArray[51] = ui.cell52;
    m_cellsArray[52] = ui.cell53;
    m_cellsArray[53] = ui.cell54;
    m_cellsArray[54] = ui.cell55;
    m_cellsArray[55] = ui.cell56;
    m_cellsArray[56] = ui.cell57;
    m_cellsArray[57] = ui.cell58;
    m_cellsArray[58] = ui.cell59;
    m_cellsArray[59] = ui.cell60;
    m_cellsArray[60] = ui.cell61;
    m_cellsArray[61] = ui.cell62;
    m_cellsArray[62] = ui.cell63;
    m_cellsArray[63] = ui.cell64;
    m_cellsArray[64] = ui.cell65;
    m_cellsArray[65] = ui.cell66;
    m_cellsArray[66] = ui.cell67;
    m_cellsArray[67] = ui.cell68;
    m_cellsArray[68] = ui.cell69;
    m_cellsArray[69] = ui.cell70;
    m_cellsArray[70] = ui.cell71;
    m_cellsArray[71] = ui.cell72;
    m_cellsArray[72] = ui.cell73;
    m_cellsArray[73] = ui.cell74;
    m_cellsArray[74] = ui.cell75;
    m_cellsArray[75] = ui.cell76;
    m_cellsArray[76] = ui.cell77;
    m_cellsArray[77] = ui.cell78;
    m_cellsArray[78] = ui.cell79;
    m_cellsArray[79] = ui.cell80;
    m_cellsArray[80] = ui.cell81;
}