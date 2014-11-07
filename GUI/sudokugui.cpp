#include "sudokugui.h"
#define SETCELLTEXT(x,y) ui.cell##x##->setText(QString::number(table[##y##])); 
#define READCELLTEXT(x,y) table[##x##]=ui.cell##y##->text().toInt()

SudokuGUI::SudokuGUI(QWidget *parent)
    : QMainWindow(parent)
{
    QStringList levelsList=(QStringList()<<"Ekstremalnie latwy"<<"Latwy"<<"Sredni"<<"Trudny"<<"Piekielnie trudny");
    method = 0;
    level = static_cast<COMPLEXITY_LEVELS>(1);
    repetitions=0;
    ui.setupUi(this);
    ui.DifficultyLevelSelector->addItems(levelsList);
    QObject::connect(ui.generateButton, SIGNAL(clicked()),this,SLOT(generateButtonClicked()));
    QObject::connect(ui.solveButton, SIGNAL(clicked()),this,SLOT(solveButtonClicked()));
    QObject::connect(ui.DifficultyLevelSelector, SIGNAL(currentIndexChanged(int)),this,SLOT(setDifficultyLevel(int)));
    QObject::connect(ui.RepetitionField, SIGNAL(textChanged(const QString &)),this, SLOT(setRepetitionCount(const QString &)));
    QObject::connect(ui.MostNeighboursButton, SIGNAL(clicked()), this,SLOT(mostNeighboursSelected()));
    QObject::connect(ui.RandomButtom, SIGNAL(clicked()),this,SLOT(randomSelected()));
}

SudokuGUI::~SudokuGUI()
{

}
void SudokuGUI::setRepetitionCount(const QString & repCount){
    repetitions=repCount.toInt();
}

void SudokuGUI::displayTime(string time){
    ui.TimeField->setText(QString::fromStdString(time));
}

void SudokuGUI::changeGridToArray(int* table){
    table[0]=ui.cell1->text().toInt();
    table[1]=ui.cell2->text().toInt();
    table[2]=ui.cell3->text().toInt();
    table[3]=ui.cell4->text().toInt();
    table[4]=ui.cell5->text().toInt();
    table[5]=ui.cell6->text().toInt();
    table[6]=ui.cell7->text().toInt();
    table[7]=ui.cell8->text().toInt();
    table[8]=ui.cell9->text().toInt();
    table[9]=ui.cell10->text().toInt();
    table[10]=ui.cell11->text().toInt();
    table[11]=ui.cell12->text().toInt();
    table[12]=ui.cell13->text().toInt();
    table[13]=ui.cell14->text().toInt();
    table[14]=ui.cell15->text().toInt();
    table[15]=ui.cell16->text().toInt();
    table[16]=ui.cell17->text().toInt();
    table[17]=ui.cell18->text().toInt();
    table[18]=ui.cell19->text().toInt();
    table[19]=ui.cell20->text().toInt();
    table[20]=ui.cell21->text().toInt();
    table[21]=ui.cell22->text().toInt();
    table[22]=ui.cell23->text().toInt();
    table[23]=ui.cell24->text().toInt();
    table[24]=ui.cell25->text().toInt();
    table[25]=ui.cell26->text().toInt();
    table[26]=ui.cell27->text().toInt();
    table[27]=ui.cell28->text().toInt();
    table[28]=ui.cell29->text().toInt();
    table[29]=ui.cell30->text().toInt();
    table[30]=ui.cell31->text().toInt();
    table[31]=ui.cell32->text().toInt();
    table[32]=ui.cell33->text().toInt();
    table[33]=ui.cell34->text().toInt();
    table[34]=ui.cell35->text().toInt();
    table[35]=ui.cell36->text().toInt();
    table[36]=ui.cell37->text().toInt();
    table[37]=ui.cell38->text().toInt();
    table[38]=ui.cell39->text().toInt();
    table[39]=ui.cell40->text().toInt();
    table[40]=ui.cell41->text().toInt();
    table[41]=ui.cell42->text().toInt();
    table[42]=ui.cell43->text().toInt();
    table[43]=ui.cell44->text().toInt();
    table[44]=ui.cell45->text().toInt();
    table[45]=ui.cell46->text().toInt();
    table[46]=ui.cell47->text().toInt();
    table[47]=ui.cell48->text().toInt();
    table[48]=ui.cell49->text().toInt();
    table[49]=ui.cell50->text().toInt();
    table[50]=ui.cell51->text().toInt();
    table[51]=ui.cell52->text().toInt();
    table[52]=ui.cell53->text().toInt();
    table[53]=ui.cell54->text().toInt();
    table[54]=ui.cell55->text().toInt();
    table[55]=ui.cell56->text().toInt();
    table[56]=ui.cell57->text().toInt();
    table[57]=ui.cell58->text().toInt();
    table[58]=ui.cell59->text().toInt();
    table[59]=ui.cell60->text().toInt();
    table[60]=ui.cell61->text().toInt();
    table[61]=ui.cell62->text().toInt();
    table[62]=ui.cell63->text().toInt();
    table[63]=ui.cell64->text().toInt();
    table[64]=ui.cell65->text().toInt();
    table[65]=ui.cell66->text().toInt();
    table[66]=ui.cell67->text().toInt();
    table[67]=ui.cell68->text().toInt();
    table[68]=ui.cell69->text().toInt();
    table[69]=ui.cell70->text().toInt();
    table[70]=ui.cell71->text().toInt();
    table[71]=ui.cell72->text().toInt();
    table[72]=ui.cell73->text().toInt();
    table[73]=ui.cell74->text().toInt();
    table[74]=ui.cell75->text().toInt();
    table[75]=ui.cell76->text().toInt();
    table[76]=ui.cell77->text().toInt();
    table[77]=ui.cell78->text().toInt();
    table[78]=ui.cell79->text().toInt();
    table[79]=ui.cell80->text().toInt();
    table[80]=ui.cell81->text().toInt();
}

void SudokuGUI::changeCellsValue(int* table){
    //for (int i=0; i<81;++i){
    ui.cell1->setText(QString::number(table[0]));
    ui.cell2->setText(QString::number(table[1]));
    ui.cell3->setText(QString::number(table[2]));
    ui.cell4->setText(QString::number(table[3]));
    ui.cell5->setText(QString::number(table[4]));
    ui.cell6->setText(QString::number(table[5]));
    ui.cell7->setText(QString::number(table[6]));
    ui.cell8->setText(QString::number(table[7]));
    ui.cell9->setText(QString::number(table[8]));
    ui.cell10->setText(QString::number(table[9]));
    ui.cell11->setText(QString::number(table[10]));
    ui.cell12->setText(QString::number(table[11]));
    ui.cell13->setText(QString::number(table[12]));
    ui.cell14->setText(QString::number(table[13]));
    ui.cell15->setText(QString::number(table[14]));
    ui.cell16->setText(QString::number(table[15]));
    ui.cell17->setText(QString::number(table[16]));
    ui.cell18->setText(QString::number(table[17]));
    ui.cell19->setText(QString::number(table[18]));
    ui.cell20->setText(QString::number(table[19]));
    ui.cell21->setText(QString::number(table[20]));
    ui.cell22->setText(QString::number(table[21]));
    ui.cell23->setText(QString::number(table[22]));
    ui.cell24->setText(QString::number(table[23]));
    ui.cell25->setText(QString::number(table[24]));
    ui.cell26->setText(QString::number(table[25]));
    ui.cell27->setText(QString::number(table[26]));
    ui.cell28->setText(QString::number(table[27]));
    ui.cell29->setText(QString::number(table[28]));
    ui.cell30->setText(QString::number(table[29]));
    ui.cell31->setText(QString::number(table[30]));
    ui.cell32->setText(QString::number(table[31]));
    ui.cell33->setText(QString::number(table[32]));
    ui.cell34->setText(QString::number(table[33]));
    ui.cell35->setText(QString::number(table[34]));
    ui.cell36->setText(QString::number(table[35]));
    ui.cell37->setText(QString::number(table[36]));
    ui.cell38->setText(QString::number(table[37]));
    ui.cell39->setText(QString::number(table[38]));
    ui.cell40->setText(QString::number(table[39]));
    ui.cell41->setText(QString::number(table[40]));
    ui.cell42->setText(QString::number(table[41]));
    ui.cell43->setText(QString::number(table[42]));
    ui.cell44->setText(QString::number(table[43]));
    ui.cell45->setText(QString::number(table[44]));
    ui.cell46->setText(QString::number(table[45]));
    ui.cell47->setText(QString::number(table[46]));
    ui.cell48->setText(QString::number(table[47]));
    ui.cell49->setText(QString::number(table[48]));
    ui.cell50->setText(QString::number(table[49]));
    ui.cell51->setText(QString::number(table[50]));
    ui.cell52->setText(QString::number(table[51]));
    ui.cell53->setText(QString::number(table[52]));
    ui.cell54->setText(QString::number(table[53]));
    ui.cell55->setText(QString::number(table[54]));
    ui.cell56->setText(QString::number(table[55]));
    ui.cell57->setText(QString::number(table[56]));
    ui.cell58->setText(QString::number(table[57]));
    ui.cell59->setText(QString::number(table[58]));
    ui.cell60->setText(QString::number(table[59]));
    ui.cell61->setText(QString::number(table[60]));
    ui.cell62->setText(QString::number(table[61]));
    ui.cell63->setText(QString::number(table[62]));
    ui.cell64->setText(QString::number(table[63]));
    ui.cell65->setText(QString::number(table[64]));
    ui.cell66->setText(QString::number(table[65]));
    ui.cell67->setText(QString::number(table[66]));
    ui.cell68->setText(QString::number(table[67]));
    ui.cell69->setText(QString::number(table[68]));
    ui.cell70->setText(QString::number(table[69]));
    ui.cell71->setText(QString::number(table[70]));
    ui.cell72->setText(QString::number(table[71]));
    ui.cell73->setText(QString::number(table[72]));
    ui.cell74->setText(QString::number(table[73]));
    ui.cell75->setText(QString::number(table[74]));
    ui.cell76->setText(QString::number(table[75]));
    ui.cell77->setText(QString::number(table[76]));
    ui.cell78->setText(QString::number(table[77]));
    ui.cell79->setText(QString::number(table[78]));
    ui.cell80->setText(QString::number(table[79]));
    ui.cell81->setText(QString::number(table[80]));
    //ui.STEP2(RESOLVE(i), 4);
    //}
}

void SudokuGUI::displayOperations(string operations){
    ui.OperationsField->setText(QString::fromStdString(operations));
}
void SudokuGUI::generateButtonClicked(){
    srand(unsigned(time(0)));
    int* sudokuArray = new int[81]();
    SudokuGenerator generator;
    generator.generate(sudokuArray, level);
    changeCellsValue(sudokuArray);
    delete[] sudokuArray;
}

void SudokuGUI::solveButtonClicked(){

}

void SudokuGUI::mostNeighboursSelected(){
    method = 0;
}

void SudokuGUI::randomSelected(){
    method = 1;
}

void SudokuGUI::setDifficultyLevel(int lvl){
    level = static_cast<COMPLEXITY_LEVELS>(lvl+1);
}

