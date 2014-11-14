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

/*!
Enumeracja opisuj¹ca mo¿liwe wydarzenia, wyœwietlane na pasku stanu.
*/
enum STATUS_BAR_INFO {
    EMPTY = 0,
    WRONG_SUDOKU_BOARD,
    SUDOKU_UNSOLVABLE,
    NO_BOARD_LOADED
};
/*!
Klasa okna g³ównego programu.
*/
class SudokuGUI : public QMainWindow
{
    Q_OBJECT
    public slots:
        /*!
        Funkcja odbieraj¹ca sygna³ wciœniêcia klawisza odpowiedzialnego za generacjê. Wywo³uje proces generacji.
        */
        void generateButtonClicked();
        /*!
        Funkcja odbieraj¹ca sygna³ wciœniêcia klawisza odpowiedzialnego za rozwi¹zywanie Sudoku. Wywo³uje proces rozwi¹zywania.
        */
        void solveButtonClicked();
        /*!
        Funkcja odbieraj¹ca sygna³ wciœniêcia klawisza odpowiedzialnego za wczytywane Sudoku z pliku. Wywo³uje okno wyboru pliku.
        */
        void loadSudokuButtonClicked();
        /*!
        Funkcja odbieraj¹ca sygna³ wciœniêcia menu odpowiedzialnego za wyœwietlanie informacji o autorach. Wyœwietla okno z informacjami.
        */
        void aboutAuthorsClicked();
        /*!
        Funkcja odbieraj¹ca sygna³ wciœniêcia klawisza odpowiedzialnego za wybór metody rozwi¹zywania Sudoku - najwiêcej s¹siadów.
        */
        void mostNeighboursSelected() { m_solveMethod = MOST_NEIGHBOURS; }
        /*!
        Funkcja odbieraj¹ca sygna³ wciœniêcia klawisza odpowiedzialnego za wybór metody rozwi¹zywania Sudoku - losowy.
        */
        void randomSelected() { m_solveMethod = RANDOM; }
        /*!
        Funkcja odbieraj¹ca sygna³ wciœniêcia klawisza odpowiedzialnego za wybór poziomu trudnoœci.
        @param lvl - wybrany poziom trudnoœci.
        */
        void setDifficultyLevel(int lvl) { m_level = static_cast<COMPLEXITY_LEVELS>(lvl+1); }
        /*!
        Funkcja odbieraj¹ca sygna³ wpisania iloœci powtórzeñ.
        @param repCount - wpisana iloœæ powtórzeñ.
        */
        void setRepetitionCount(const QString & repCount) { m_repetitionsCount = repCount.toInt(); }
        /*!
        Funkcja odbieraj¹ca sygna³ wybrania opcji zapisu do pliku.
        @param flag - przyjmuje wartoœæ true, gdy u¿ytkownik wybierze tryb zapisu do pliku.
        */
        void setSaveFlag(bool flag) { m_saveFlag = flag; }

    public:
        /*!
        Konstruktor klasy SudokuGUI. Inicjuje zmienne i wi¹¿e sygna³y i funkcje je odbieraj¹ce ze sob¹.
        */
        SudokuGUI(QWidget *parent = 0);

    private:
        /*!
        Funkcja zmieniaj¹ca wartoœci komórek w graficznej siatce Sudoku,
        @param table - tablica, z której maj¹ byæ odczytywane nowe wartoœci
        @param justAfterSolve - flaga informuj¹ca, jak¹ czcionk¹ maj¹ byæ wyœwietlane wartoœci.
        */
        void changeCellsValue(int* table, bool justAfterSolve = false);
        /*!
        Funkcja wyœwietlaj¹ca czas rozwi¹zywania.
        @param time - czas rozwi¹zywania.
        */
        void displayTime(long long time);
        /*!
        Funkcja wyœwietlaj¹ca liczbê operacji.
        @param operations - liczba operacji.
        */
        void displayOperations(long long operations);
        /*!
        Zamiana tablicy z graficzn¹ siatk¹ Sudoku na tablicê intów.
        */
        void changeGridToArray(int* table);
        /*!
        Funkcja grupuj¹ca komórki z graficznej siatki Sudoku w tablicê.
        */
        void moveCellsIntoTable();
        /*!
        Funkcja wywo³uj¹ca metody klasy SudokuGenerator, odpowiadaj¹ce za generowanie Sudoku.
        */
        void generate();
        /*!
        Funkcja wywo³uj¹ca metody klasy SudokuSolver, odpowiadaj¹ce za rozwi¹zanie Sudoku.
        */
        void solve();
        /*!
        Funkcja odpowiedzialna za zapis do pliku.
        @param stream - dane, które maj¹ byæ zapisane w pliku.
        */
        void saveToFile(string stream);
        /*!
        Funkcja odpowiedzialna za aktualizowanie paska stanu.
        @param status - informacja, ktora ma zostaæ wyœwietlona.
        */
        void updateStatusBar(STATUS_BAR_INFO status);

        /*!
        Plik, w którym maj¹ byæ zapisywane wyniki.
        */
        ofstream m_file;
        /*!
        Iloœæ powtórzeñ.
        */
        unsigned m_repetitionsCount;
        /*!
        Tablica z wygenerowanym Sudoku.
        */
        int m_sudokuGeneratedArray[81];
        /*!
        Tablica z rozwi¹zanym Sudoku.
        */
        int m_sudokuSolvedArray[81];
        /*!
        Flaga informuj¹ca, czy wyniki maj¹ byæ zapisywane do pliku.
        */
        bool m_saveFlag;
        /*!
        Flaga informuj¹ca, czy wczytane Sudoku jest poprawne.
        */
        bool m_canBeSolved;
        /*!
        Sposób rozwi¹zywania Sudoku.
        */
        NEXT_POINT_SEARCHING_SCENARIO m_solveMethod;
        /*!
        Poziom trudnoœci Sudoku.
        */
        COMPLEXITY_LEVELS m_level;
        /*!
        Obiekt opisuj¹cy uklad graficzny programu.
        */
        Ui::SudokuGUIClass m_ui;
        /*!
        Graficzna siatka Sudoku.
        */
        QLineEdit* m_cellsArray[81];
};

#endif // SUDOKUGUI_H
