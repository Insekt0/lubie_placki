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
Enumeracja opisuj�ca mo�liwe wydarzenia, wy�wietlane na pasku stanu.
*/
enum STATUS_BAR_INFO {
    EMPTY = 0,
    WRONG_SUDOKU_BOARD,
    SUDOKU_UNSOLVABLE,
    NO_BOARD_LOADED
};
/*!
Klasa okna g��wnego programu.
*/
class SudokuGUI : public QMainWindow
{
    Q_OBJECT
    public slots:
        /*!
        Funkcja odbieraj�ca sygna� wci�ni�cia klawisza odpowiedzialnego za generacj�. Wywo�uje proces generacji.
        */
        void generateButtonClicked();
        /*!
        Funkcja odbieraj�ca sygna� wci�ni�cia klawisza odpowiedzialnego za rozwi�zywanie Sudoku. Wywo�uje proces rozwi�zywania.
        */
        void solveButtonClicked();
        /*!
        Funkcja odbieraj�ca sygna� wci�ni�cia klawisza odpowiedzialnego za wczytywane Sudoku z pliku. Wywo�uje okno wyboru pliku.
        */
        void loadSudokuButtonClicked();
        /*!
        Funkcja odbieraj�ca sygna� wci�ni�cia menu odpowiedzialnego za wy�wietlanie informacji o autorach. Wy�wietla okno z informacjami.
        */
        void aboutAuthorsClicked();
        /*!
        Funkcja odbieraj�ca sygna� wci�ni�cia klawisza odpowiedzialnego za wyb�r metody rozwi�zywania Sudoku - najwi�cej s�siad�w.
        */
        void mostNeighboursSelected() { m_solveMethod = MOST_NEIGHBOURS; }
        /*!
        Funkcja odbieraj�ca sygna� wci�ni�cia klawisza odpowiedzialnego za wyb�r metody rozwi�zywania Sudoku - losowy.
        */
        void randomSelected() { m_solveMethod = RANDOM; }
        /*!
        Funkcja odbieraj�ca sygna� wci�ni�cia klawisza odpowiedzialnego za wyb�r poziomu trudno�ci.
        @param lvl - wybrany poziom trudno�ci.
        */
        void setDifficultyLevel(int lvl) { m_level = static_cast<COMPLEXITY_LEVELS>(lvl+1); }
        /*!
        Funkcja odbieraj�ca sygna� wpisania ilo�ci powt�rze�.
        @param repCount - wpisana ilo�� powt�rze�.
        */
        void setRepetitionCount(const QString & repCount) { m_repetitionsCount = repCount.toInt(); }
        /*!
        Funkcja odbieraj�ca sygna� wybrania opcji zapisu do pliku.
        @param flag - przyjmuje warto�� true, gdy u�ytkownik wybierze tryb zapisu do pliku.
        */
        void setSaveFlag(bool flag) { m_saveFlag = flag; }

    public:
        /*!
        Konstruktor klasy SudokuGUI. Inicjuje zmienne i wi��e sygna�y i funkcje je odbieraj�ce ze sob�.
        */
        SudokuGUI(QWidget *parent = 0);

    private:
        /*!
        Funkcja zmieniaj�ca warto�ci kom�rek w graficznej siatce Sudoku,
        @param table - tablica, z kt�rej maj� by� odczytywane nowe warto�ci
        @param justAfterSolve - flaga informuj�ca, jak� czcionk� maj� by� wy�wietlane warto�ci.
        */
        void changeCellsValue(int* table, bool justAfterSolve = false);
        /*!
        Funkcja wy�wietlaj�ca czas rozwi�zywania.
        @param time - czas rozwi�zywania.
        */
        void displayTime(long long time);
        /*!
        Funkcja wy�wietlaj�ca liczb� operacji.
        @param operations - liczba operacji.
        */
        void displayOperations(long long operations);
        /*!
        Zamiana tablicy z graficzn� siatk� Sudoku na tablic� int�w.
        */
        void changeGridToArray(int* table);
        /*!
        Funkcja grupuj�ca kom�rki z graficznej siatki Sudoku w tablic�.
        */
        void moveCellsIntoTable();
        /*!
        Funkcja wywo�uj�ca metody klasy SudokuGenerator, odpowiadaj�ce za generowanie Sudoku.
        */
        void generate();
        /*!
        Funkcja wywo�uj�ca metody klasy SudokuSolver, odpowiadaj�ce za rozwi�zanie Sudoku.
        */
        void solve();
        /*!
        Funkcja odpowiedzialna za zapis do pliku.
        @param stream - dane, kt�re maj� by� zapisane w pliku.
        */
        void saveToFile(string stream);
        /*!
        Funkcja odpowiedzialna za aktualizowanie paska stanu.
        @param status - informacja, ktora ma zosta� wy�wietlona.
        */
        void updateStatusBar(STATUS_BAR_INFO status);

        /*!
        Plik, w kt�rym maj� by� zapisywane wyniki.
        */
        ofstream m_file;
        /*!
        Ilo�� powt�rze�.
        */
        unsigned m_repetitionsCount;
        /*!
        Tablica z wygenerowanym Sudoku.
        */
        int m_sudokuGeneratedArray[81];
        /*!
        Tablica z rozwi�zanym Sudoku.
        */
        int m_sudokuSolvedArray[81];
        /*!
        Flaga informuj�ca, czy wyniki maj� by� zapisywane do pliku.
        */
        bool m_saveFlag;
        /*!
        Flaga informuj�ca, czy wczytane Sudoku jest poprawne.
        */
        bool m_canBeSolved;
        /*!
        Spos�b rozwi�zywania Sudoku.
        */
        NEXT_POINT_SEARCHING_SCENARIO m_solveMethod;
        /*!
        Poziom trudno�ci Sudoku.
        */
        COMPLEXITY_LEVELS m_level;
        /*!
        Obiekt opisuj�cy uklad graficzny programu.
        */
        Ui::SudokuGUIClass m_ui;
        /*!
        Graficzna siatka Sudoku.
        */
        QLineEdit* m_cellsArray[81];
};

#endif // SUDOKUGUI_H
