#ifndef SudokuSolver_h
#define SudokuSolver_h

#include "Common.h"

#include <vector>

/*!
Struktura opisuj�ca kom�rk� w siatce �amig��wki Sudoku.
*/
struct Cell {
    /*!
    Pozycja w wierszu.
    */
    int* m_row;
    /*!
    Pozycja w kolumnie.
    */
    int* m_column;
    /*!
    Pozycja w grupie 3x3.
    */
    int* m_square;
};

/*!
* Klasa implementuj�ca algorytm przeszukiwania w g��b do rozwi�zywania Sudoku.
*/
class SudokuSolver {
public:
    /*!
    Konstruktor klasy SudokuSolver.
    @param sudokuArray - Sudoku, kt�re mamy rozwi�za�.
    */
    SudokuSolver(int* sudokuArray);
    /*!
    Funkcja s�u��ca do zarz�dzania procesem rozwi�zania Sudoku.
    @param SCENARIO - spos�b rozwi�zania
    @param isGenerating - flaga, m�wi�ca o tym, czy proces rozwi�zywania ma uwzgl�dnia� ograniczenie na ilo�� operacji.
    */
    int* solve(NEXT_POINT_SEARCHING_SCENARIO SCENARIO, bool isGenerating = false);
    /*!
    Funkcja sprawdzaj�ca mo�liwo�� wstawienia danej cyfry w dane miejsce.
    @param itsY - pozycja kom�rki w osi Y
    @param itsX - pozycja kom�rki w osi X
    @param sudokuArray - tablica z rozwi�zywanym Sudoku
    @param resultArray - tablica mo�liwych do wstawienia warto�ci
    */
    static void checkPossibleValues(int itsY, int itsX, int* sudokuArray, bool* resultArray);
    /*!
    Funkcja do znalezienia wolnych kom�rek w siatce Sudoku.
    @param SCENARIO - spos�b rozwi�zania Sudoku
    */
    void findAndSortEmptyCells(NEXT_POINT_SEARCHING_SCENARIO SCENARIO);
    /*!
    Funkcja rekurencyjna, poszukuj�ca rozwi�zania Sudoku poprzez rozpinanie kolejnych ga��zi drzewa mo�liwych rozwi�za�.
    @param position - pozycja, dla kt�rej aktualnie poszukujemy rozwi�zania
    @param isGenerating - flaga informuj�ca o tym, czy nale�y uwzgl�dnia� ograniczenie na liczb� operacji
    @param newIndex - nast�pna pozycja do poszukiwania rowi�zania
    @return 0 - je�li znaleziono rozwi�zanie, -1 - gdy nie znaleziono rozwi�zania, -2 - gdy Sudoku by�o zbyt d�ugo rozwi�zywane (przy generacji)
    */
    int recursiveSearchInTree(int position, bool isGenerating, unsigned newIndex);
    /*!
    Funkcja s�u�aca do inicjalizacji zmiennych.
    */
    void initializeValues();
    /*!
    Funkcja sprawdza, czy wstawienie danej warto�ci nie spowoduje kolizji w siatce Sudoku (czy mo�emy wstawi� dan� warto�� w dane miejsce)
    @param position - pozycja do sprawdzenia
    @param value - warto��, kt�r� chcemy wstawi�
    @return true - je�li wyst�puje kolizja, false - je�li dan� warto�� mo�na wstawi�.
    */
    inline bool checkCollision(int position, int value);
    /*!
    Funkcja s�u�aca do wstawienia warto�ci w struktury reprezntuj�ce wiersz, kolumn� i grup� 3x3.
    @param position - pozycja, na kt�r� chcemy wstawi� warto��
    @param value - warto��, kt�r� chcemy wstawi�
    */
    inline void setCellValue(int position, int value);
    /*!
    Funkcja do usuwania warto�ci z danej pozycji w strukturach reprezntuj�cych wiersz, kolumn� i grup� 3x3.
    @param position - pozycja, z kt�rej chcemy usun�� warto��
    @param value - warto��, kt�r� chcemy wstawi�
    */
    inline void removeCellValue(int position, int value);

    /*!
    Akcesor s�u��cy do odnalezienia odpowiedniej warto�ci w tablicy jednowymiarowej z Sudoku.
    @param x - pozycja w x
    @param y - pozycja w y
    @return warto�� w tablicy jednowymiarowej
    */
    inline int& accessSudokuArray(int y, int x) { return m_sudokuArray[(x-1) + (y-1)*9]; }
    /*!
    Akcesor s�u��cy do odnalezienia odpowiedniej warto�ci w tablicy jednowymiarowej tymczasowej.
    @param x - pozycja w x
    @param y - pozycja w y
    @return warto�� w tablicy jednowymiarowej
    */
    inline int& accessTemporaryArray(int y, int x) { return m_sudokuTemporaryArray[x-1 + (y-1)*9]; }
    /*!
    Funkcja konwertuj�ca pozycj� w tablicy jednowymiarowej na pozycj� dwuwymiarow�.
    @param position - pozycja jednowymiarowa
    @param newX - nowa pozycja w osi x
    @param newY - nowa pozycja w osi y
    */
    static void convert1Dto2D(int position, int& newY, int& newX) { newY = (position / 9) + 1, newX = (position % 9) + 1; }
    /*!
    Funkcja zwracaj�ca czas rozwi�zania Sudoku.
    @return czas rozwi�zania Sudoku
    */
    long long getSolveTime() { return m_solveTime; }
    /*!
    Funkcja zwracaj�ca ilo�� operacji.
    @return ilo�� operacji
    */
    long long getSolveComplexity() { return m_solveComplexity; }

private:
    /*!
    Tablica kom�rek siatki Sudoku.
    */
    Cell m_cells[81];
    /*!
    Tablica wierszy siatki Sudoku.
    */
    int m_rows[9];
    /*!
    Tablica kolumn siatki Sudoku.
    */
    int m_columns[9];
    /*!
    Tablica grup 3x3 siatki Sudoku.
    */
    int m_squares[9];
    /*!
    Tablica zawieraj�ca Sudoku.
    */
    int m_sudokuArray[81];
    /*!
    Tablica tymczasowa.
    */
    int m_sudokuTemporaryArray[81];
    /*!
    Czas rozwi�zania Sudoku
    */
    long long m_solveTime;
    /*!
    Ilo�� operacji
    */
    long long m_solveComplexity;
    /*!
    Wektor par numer kom�rki, liczba s�siad�w.
    */
    vector< pair<int,int> > m_cellsVector;
    /*!
    Tablica wolnych kom�rek, posortowana w zale�no�ci od trybu rozwi�zywania.
    */
    int m_cellsArray[81];
    /*!
    Liczba wolnych kom�rek.
    */
    unsigned m_cellsNumber;
    /*!
    Flaga m�wi�ca o tym, czy Sudoku jest ju� rozwi�zane.
    */
    bool isSudokuAlreadySolved;
};


#endif // SudokuSolver_h