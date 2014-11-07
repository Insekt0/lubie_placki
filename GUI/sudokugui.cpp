#include "sudokugui.h"

#include <sstream>
#include <QMessageBox>

SudokuGUI::SudokuGUI(QWidget *parent)
    : QMainWindow(parent), m_solveMethod(MOST_NEIGHBOURS), m_level(EXTREMELY_EASY), m_repetitionsCount(0)
{
    QStringList levelsList=(QStringList()<<"Ekstremalnie \305\202atwy"<<"\305\201atwy"<<"\305\232redni"<<"Trudny"<<"Piekielnie trudny");
    m_ui.setupUi(this);
    moveCellsIntoTable();
    m_ui.DifficultyLevelSelector->addItems(levelsList);
    QObject::connect(m_ui.generateButton, SIGNAL(clicked()),this,SLOT(generateButtonClicked()));
    QObject::connect(m_ui.solveButton, SIGNAL(clicked()),this,SLOT(solveButtonClicked()));
    QObject::connect(m_ui.DifficultyLevelSelector, SIGNAL(currentIndexChanged(int)),this,SLOT(setDifficultyLevel(int)));
    QObject::connect(m_ui.RepetitionField, SIGNAL(textChanged(const QString &)),this, SLOT(setRepetitionCount(const QString &)));
    QObject::connect(m_ui.MostNeighboursButton, SIGNAL(clicked()), this,SLOT(mostNeighboursSelected()));
    QObject::connect(m_ui.RandomButtom, SIGNAL(clicked()),this,SLOT(randomSelected()));
    QObject::connect(m_ui.loadButton, SIGNAL(clicked(bool)),this,SLOT(loadSudokuButtonClicked()));
    QObject::connect(m_ui.saveToFileCheckbox, SIGNAL(toggled(bool)),this, SLOT(setSaveFlag(bool)));
    QObject::connect(m_ui.aboutAuthors, SIGNAL(triggered()), this, SLOT(aboutAuthorsClicked()));
    QObject::connect(m_ui.close, SIGNAL(triggered()), this, SLOT(close()));    
    displayOperations(-1);
    displayTime(-1);
    updateStatusBar(EMPTY);
    for (int i = 0; i < 81; ++i)
    {
        m_sudokuGeneratedArray[i] = 0;
        m_sudokuSolvedArray[i] = 0;
    }
    changeCellsValue(m_sudokuGeneratedArray);
}


void SudokuGUI::displayTime(long long time){
    ostringstream ss;
    ss << "";
    if(time != -1)
        ss << time/1000000 << "s " << (time % 1000000)/1000 << "ms " << (time % 1000) << "us ";
    m_ui.TimeField->setText(QString::fromStdString(ss.str()));
}

void SudokuGUI::updateStatusBar(STATUS_BAR_INFO status)
{
    string result;
    switch(status)
    {
    case EMPTY:
        result = "";
        break;

    case WRONG_SUDOKU_BOARD:
        result = "Podany plik nie zawiera poprawnie sformatowanego sudoku";
        break;
        
    case SUDOKU_UNSOLVABLE:
        result = "Podane sudoku jest nierozwiazywalne";
        break;

    default:
        assert(false);
        result = "Wystapil niezdefiniowany blad";
        break;
    }

    m_ui.statusBar->showMessage(QString::fromStdString(result));
    QFont fontNormal("Times", 12, QFont::Bold, false);
    QPalette palette;
    palette.setColor( QPalette::WindowText, QColor(255,0,0) );
    m_ui.statusBar->setFont(fontNormal);
    m_ui.statusBar->setPalette(palette);
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

void SudokuGUI::aboutAuthorsClicked(){
    QMessageBox msgBox;
    msgBox.setText("O Autorach i programie:");
    msgBox.setInformativeText("Projekt z przedmiotu WMH wykonany przez Micha\305\202a Jurkiewicza i Joann\304\231 Wi\305\233niewsk\304\205.\n\nRozwi\304\205zywanie Sudoku z wykorzystaniem algorytmu przeszukiwania w g\305\202\304\205b.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
}

void SudokuGUI::loadSudokuButtonClicked(){
    string filename = QFileDialog::getOpenFileName(this,tr("Otw\303\263rz plik z Sudoku"), ".", tr("Pliki tekstowe (*.txt)")).toStdString();
    if(!filename.empty()){
        ifstream myfile;
        myfile.open(filename);
        int value;
        int counter = 0;
        while(myfile >> value)
            m_sudokuGeneratedArray[counter++] = value;
        changeCellsValue(m_sudokuGeneratedArray);
    }
}

void SudokuGUI::saveToFile(string stream){
    m_file << stream << "\n";
}

void SudokuGUI::displayOperations(long long operations) {
    ostringstream ss;
    ss << "";
    if(operations != -1)
        ss << operations;
    m_ui.OperationsField->setText(QString::fromStdString(ss.str()));
}

void SudokuGUI::generateButtonClicked() {
    generate();
}

void SudokuGUI::generate() {
    srand(unsigned(time(0)));
    updateStatusBar(EMPTY);
    displayOperations(-1);
    displayTime(-1);
    SudokuGenerator generator;
    generator.generate(m_sudokuGeneratedArray, m_level);
    changeCellsValue(m_sudokuGeneratedArray);
}

void SudokuGUI::solveButtonClicked() {
    if(m_saveFlag){
        m_file.open("result.txt");
    }
    solve();
    unsigned counter = 1;
    while(counter < m_repetitionsCount)
    {
        ++counter;
        generate();
        solve();
    }
    if(m_saveFlag){
        m_file.close();
    }
}

void SudokuGUI::solve() {
    SudokuSolver solver(m_sudokuGeneratedArray);
    int* result = solver.solve(m_solveMethod);

    if(!result)
    {
        updateStatusBar(SUDOKU_UNSOLVABLE);
        displayTime(-1);
        displayOperations(-1);
        return;
    }

    updateStatusBar(EMPTY);

    for (int i = 0; i < 81; ++i)
        m_sudokuSolvedArray[i] = result[i];

    displayTime(solver.getSolveTime());
    displayOperations(solver.getSolveComplexity());
    changeCellsValue(m_sudokuSolvedArray, true);

    if(m_saveFlag){
        ostringstream ss;
        ss << "metoda " << m_solveMethod << " poziom trudnosci " << m_level << " liczba operacji " << solver.getSolveComplexity() << 
            " czas " << solver.getSolveTime()/1000000 << "s " << (solver.getSolveTime() % 1000000)/1000 << 
            "ms " << (solver.getSolveTime() % 1000) << "us ";
        saveToFile(ss.str());
    }
}

void SudokuGUI::moveCellsIntoTable() {
    m_cellsArray[0] = m_ui.cell1;
    m_cellsArray[1] = m_ui.cell2;
    m_cellsArray[2] = m_ui.cell3;
    m_cellsArray[3] = m_ui.cell4;
    m_cellsArray[4] = m_ui.cell5;
    m_cellsArray[5] = m_ui.cell6;
    m_cellsArray[6] = m_ui.cell7;
    m_cellsArray[7] = m_ui.cell8;
    m_cellsArray[8] = m_ui.cell9;
    m_cellsArray[9] = m_ui.cell10;
    m_cellsArray[10] = m_ui.cell11;
    m_cellsArray[11] = m_ui.cell12;
    m_cellsArray[12] = m_ui.cell13;
    m_cellsArray[13] = m_ui.cell14;
    m_cellsArray[14] = m_ui.cell15;
    m_cellsArray[15] = m_ui.cell16;
    m_cellsArray[16] = m_ui.cell17;
    m_cellsArray[17] = m_ui.cell18;
    m_cellsArray[18] = m_ui.cell19;
    m_cellsArray[19] = m_ui.cell20;
    m_cellsArray[20] = m_ui.cell21;
    m_cellsArray[21] = m_ui.cell22;
    m_cellsArray[22] = m_ui.cell23;
    m_cellsArray[23] = m_ui.cell24;
    m_cellsArray[24] = m_ui.cell25;
    m_cellsArray[25] = m_ui.cell26;
    m_cellsArray[26] = m_ui.cell27;
    m_cellsArray[27] = m_ui.cell28;
    m_cellsArray[28] = m_ui.cell29;
    m_cellsArray[29] = m_ui.cell30;
    m_cellsArray[30] = m_ui.cell31;
    m_cellsArray[31] = m_ui.cell32;
    m_cellsArray[32] = m_ui.cell33;
    m_cellsArray[33] = m_ui.cell34;
    m_cellsArray[34] = m_ui.cell35;
    m_cellsArray[35] = m_ui.cell36;
    m_cellsArray[36] = m_ui.cell37;
    m_cellsArray[37] = m_ui.cell38;
    m_cellsArray[38] = m_ui.cell39;
    m_cellsArray[39] = m_ui.cell40;
    m_cellsArray[40] = m_ui.cell41;
    m_cellsArray[41] = m_ui.cell42;
    m_cellsArray[42] = m_ui.cell43;
    m_cellsArray[43] = m_ui.cell44;
    m_cellsArray[44] = m_ui.cell45;
    m_cellsArray[45] = m_ui.cell46;
    m_cellsArray[46] = m_ui.cell47;
    m_cellsArray[47] = m_ui.cell48;
    m_cellsArray[48] = m_ui.cell49;
    m_cellsArray[49] = m_ui.cell50;
    m_cellsArray[50] = m_ui.cell51;
    m_cellsArray[51] = m_ui.cell52;
    m_cellsArray[52] = m_ui.cell53;
    m_cellsArray[53] = m_ui.cell54;
    m_cellsArray[54] = m_ui.cell55;
    m_cellsArray[55] = m_ui.cell56;
    m_cellsArray[56] = m_ui.cell57;
    m_cellsArray[57] = m_ui.cell58;
    m_cellsArray[58] = m_ui.cell59;
    m_cellsArray[59] = m_ui.cell60;
    m_cellsArray[60] = m_ui.cell61;
    m_cellsArray[61] = m_ui.cell62;
    m_cellsArray[62] = m_ui.cell63;
    m_cellsArray[63] = m_ui.cell64;
    m_cellsArray[64] = m_ui.cell65;
    m_cellsArray[65] = m_ui.cell66;
    m_cellsArray[66] = m_ui.cell67;
    m_cellsArray[67] = m_ui.cell68;
    m_cellsArray[68] = m_ui.cell69;
    m_cellsArray[69] = m_ui.cell70;
    m_cellsArray[70] = m_ui.cell71;
    m_cellsArray[71] = m_ui.cell72;
    m_cellsArray[72] = m_ui.cell73;
    m_cellsArray[73] = m_ui.cell74;
    m_cellsArray[74] = m_ui.cell75;
    m_cellsArray[75] = m_ui.cell76;
    m_cellsArray[76] = m_ui.cell77;
    m_cellsArray[77] = m_ui.cell78;
    m_cellsArray[78] = m_ui.cell79;
    m_cellsArray[79] = m_ui.cell80;
    m_cellsArray[80] = m_ui.cell81;
}
