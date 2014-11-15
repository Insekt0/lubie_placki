#ifndef SudokuSolver_h
#define SudokuSolver_h

#include "Common.h"

#include <vector>

/*!
Struktura opisuj�ca kom�rk� w siatce �amig��wki Sudoku.
*/
struct Cell {
    /*!
    Wska�nik na wiersz, w kt�rej znajduje si� dana kom�rka.
    */
    int* m_row;
    /*!
    Wska�nik na kolumn�, w kt�rej znajduje si� dana kom�rka.
    */
    int* m_column;
    /*!
    Wska�nik na grup� 3x3, w kt�rej znajduje si� dana kom�rka.
    */
    int* m_square;
};

/*!
* Klasa implementuj�ca algorytm rozwi�zywania Sudoku.
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
    @param isGenerating - flaga, m�wi�ca o tym, czy proces rozwi�zywania jest wywo�any do cel�w generacji sudoku.
    */
    int* solve(NEXT_POINT_SEARCHING_SCENARIO SCENARIO, bool isGenerating = false);
    /*!
    Funkcja zwracaj�ca tablic�, w kt�rej znajduje si� informacja na temat mo�liwych do wstawienia warto�ci w dan� kom�rk�.
    @param itsY - pozycja kom�rki w osi Y
    @param itsX - pozycja kom�rki w osi X
    @param sudokuArray - tablica z badanym sudoku
    @param resultArray - tablica mo�liwych do wstawienia warto�ci
    */
    static void checkPossibleValues(int itsY, int itsX, int* sudokuArray, bool* resultArray);
    /*!
    Funkcja do znalezienia wolnych kom�rek w siatce Sudoku i poszeregowaniu ich wg podanego scenariusza.
    @param SCENARIO - spos�b rozwi�zania Sudoku
    */
    void findAndSortEmptyCells(NEXT_POINT_SEARCHING_SCENARIO SCENARIO);
    /*!
    Funkcja rekurencyjna, poszukuj�ca rozwi�zania Sudoku poprzez rozpinanie kolejnych ga��zi drzewa mo�liwych rozwi�za�.
    @param position - pozycja kom�rki, dla kt�rej aktualnie poszukujemy rozwi�zania
    @param isGenerating - flaga, m�wi�ca o tym, czy proces rozwi�zywania jest wywo�any do cel�w generacji sudoku.
    @param newIndex - pozycja kom�rki w posortowanej tablicy, dla kt�rej aktualnie poszukujemy rozwi�zania. Jest to informacja kt�r� kom�rk� z rz�du analizujemy.
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
    Funkcja s�u�aca do wstawienia warto�ci w struktury reprezentuj�ce wiersz, kolumn� i grup� 3x3.
    @param position - pozycja, w kt�r� chcemy wstawi� warto��
    @param value - warto��, kt�r� chcemy wstawi�
    */
    inline void setCellValue(int position, int value);
    /*!
    Funkcja do usuwania warto�ci z danej pozycji w strukturach reprezentuj�cych wiersz, kolumn� i grup� 3x3.
    @param position - pozycja, z kt�rej chcemy usun�� warto��
    @param value - warto��, kt�r� chcemy usun��
    */
    inline void removeCellValue(int position, int value);

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
    Flaga m�wi�ca o tym, czy Sudoku, ktore zostalo podane do konstruktora tej klasy, jest ju� rozwi�zane.
    */
    bool isSudokuAlreadySolved;
};


#endif // SudokuSolver_h