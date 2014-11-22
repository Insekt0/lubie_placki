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
Enumeracja opisujaca mozliwe wydarzenia, wyswietlane na pasku stanu.
*/
enum STATUS_BAR_INFO {
    EMPTY = 0,
    WRONG_SUDOKU_BOARD,
    SUDOKU_UNSOLVABLE,
    NO_BOARD_LOADED,
    LONG_TIME
};
/*!
Klasa okna glownego programu.
*/
class SudokuGUI : public QMainWindow
{
    Q_OBJECT
    public slots:
        /*!
        Funkcja odbierajaca sygnal wcisniecia klawisza odpowiedzialnego za generacje. Wywoluje proces generacji.
        */
        void generateButtonClicked();
        /*!
        Funkcja odbierajaca sygnal wcisniecia klawisza odpowiedzialnego za rozwiazywanie Sudoku. Wywoluje proces rozwiazywania.
        */
        void solveButtonClicked();
        /*!
        Funkcja odbierajaca sygnal wcisniecia klawisza odpowiedzialnego za wczytywane Sudoku z pliku. Wywoluje okno wyboru pliku.
        */
        void loadSudokuButtonClicked();
        /*!
        Funkcja odbierajaca sygnal wcisniecia menu odpowiedzialnego za wyswietlanie informacji o autorach. Wyswietla okno z informacjami.
        */
        void aboutAuthorsClicked();
        /*!
        Funkcja odbierajaca sygnal wcisniecia klawisza odpowiedzialnego za wybor metody rozwiazywania Sudoku - najwiecej sasiadow.
        */
        void mostNeighboursSelected() { m_solveMethod = MOST_NEIGHBOURS; }
        /*!
        Funkcja odbierajaca sygnal wcisniecia klawisza odpowiedzialnego za wybor metody rozwiazywania Sudoku - losowy.
        */
        void randomSelected() { m_solveMethod = RANDOM; }
        /*!
        Funkcja odbierajaca sygnal wcisniecia klawisza odpowiedzialnego za wybor poziomu trudnosci.
        @param lvl - wybrany poziom trudnosci.
        */
        void setDifficultyLevel(int lvl) { m_level = static_cast<COMPLEXITY_LEVELS>(lvl+1); }
        /*!
        Funkcja odbierajaca sygnal wpisania ilosci powtorzen.
        @param repCount - wpisana ilosc powtorzen.
        */
        void setRepetitionCount(const QString & repCount) { m_repetitionsCount = repCount.toInt(); }
        /*!
        Funkcja odbierajaca sygnal wybrania opcji zapisu do pliku.
        @param flag - przyjmuje wartosc true, gdy uzytkownik wybierze tryb zapisu do pliku.
        */
        void setSaveFlag(bool flag) { m_saveFlag = flag; }
        /*!
        Funkcja odbierajaca sygnal wybrania opcji zwiekszenia rozdzielczosci czasowej wynikow.
        @param flag - przyjmuje wartosc true, gdy uzytkownik wybierze dokladniejsze obliczanie wynikow czasowych.
        */
        void setHigherTimeResolutionFlag(bool flag);
    public:
        /*!
        Konstruktor klasy SudokuGUI. Inicjuje zmienne i wiaze sygnaly i funkcje je odbierajace ze soba.
        */
        SudokuGUI(QWidget *parent = 0);

    private:
        /*!
        Funkcja zmieniajaca wartosci komorek w graficznej siatce Sudoku,
        @param table - tablica, z ktorej maja byc odczytywane nowe wartosci
        @param justAfterSolve - flaga informujaca, jaka czcionka maja byc wyswietlane wartosci.
        */
        void changeCellsValue(int* table, bool justAfterSolve = false);
        /*!
        Funkcja wyswietlajaca czas rozwiazywania.
        @param time - czas rozwiazywania.
        */
        void displayTime(long long time);
        /*!
        Funkcja wyswietlajaca liczbe operacji.
        @param operations - liczba operacji.
        */
        void displayOperations(long long operations);
        /*!
        Funkcja grupujaca komorki z graficznej siatki Sudoku w tablice.
        */
        void moveCellsIntoTable();
        /*!
        Funkcja wywolujaca metody klasy SudokuGenerator, odpowiadajace za generowanie Sudoku.
        */
        void generate();
        /*!
        Funkcja wywolujaca metody klasy SudokuSolver, odpowiadajace za rozwiazanie Sudoku.
        */
        void solve();
        /*!
        Funkcja odpowiedzialna za zapis do pliku.
        @param stream - dane, ktore maja byc zapisane w pliku.
        */
        void saveToFile(string stream);
        /*!
        Funkcja odpowiedzialna za aktualizowanie paska stanu.
        @param status - informacja, ktora ma zostac wyswietlona.
        */
        void updateStatusBar(STATUS_BAR_INFO status);

        /*!
        Plik, w ktorym maja byc zapisywane wyniki.
        */
        ofstream m_file;
        /*!
        Ilosc powtorzen.
        */
        unsigned m_repetitionsCount;
        /*!
        Tablica z wygenerowanym Sudoku.
        */
        int m_sudokuGeneratedArray[81];
        /*!
        Tablica z rozwiazanym Sudoku.
        */
        int m_sudokuSolvedArray[81];
        /*!
        Flaga informujaca, czy wyniki maja byc zapisywane do pliku.
        */
        bool m_saveFlag;
        /*!
        Flaga informujaca, czy maja byc wykonane dokladniejsze obliczenia czasow rozwiazania.
        */
        bool m_higherTimeResolution;
        /*!
        Flaga informujaca, czy wczytane Sudoku jest poprawne.
        */
        bool m_canBeSolved;
        /*!
        Sposob rozwiazywania Sudoku.
        */
        NEXT_POINT_SEARCHING_SCENARIO m_solveMethod;
        /*!
        Poziom trudnosci Sudoku.
        */
        COMPLEXITY_LEVELS m_level;
        /*!
        Obiekt opisujacy uklad graficzny programu.
        */
        Ui::SudokuGUIClass m_ui;
        /*!
        Graficzna siatka Sudoku.
        */
        QLineEdit* m_cellsArray[81];
};

#endif // SUDOKUGUI_H
