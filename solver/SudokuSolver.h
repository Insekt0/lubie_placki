#ifndef SudokuSolver_h
#define SudokuSolver_h

#include "Common.h"

#include <vector>

/*!
Struktura opisujaca komorke w siatce lamiglowki Sudoku.
*/
struct Cell {
    /*!
    Wskaznik na wiersz, w ktorej znajduje sie dana komorka.
    */
    int* m_row;
    /*!
    Wskaznik na kolumne, w ktorej znajduje sie dana komorka.
    */
    int* m_column;
    /*!
    Wskaznik na grupe 3x3, w ktorej znajduje sie dana komorka.
    */
    int* m_square;
};

/*!
* Klasa implementujaca algorytm rozwiazywania Sudoku.
*/
class SudokuSolver {
public:
    /*!
    Konstruktor klasy SudokuSolver.
    @param sudokuArray - Sudoku, ktore mamy rozwiazac.
    */
    SudokuSolver(int* sudokuArray);
    /*!
    Funkcja sluzaca do zarzadzania procesem rozwiazania Sudoku.
    @param SCENARIO - sposob rozwiazania
    @param isGenerating - flaga, mowiaca o tym, czy proces rozwiazywania jest wywolany do celow generacji sudoku.
    @param higherTimeResolution - flaga informujaca o tym, czy powinny byc wykonane dokladne obliczenia czasu
    @param sudokuLevel - poziom trudnosci Sudoku, na podstawie ktorego wyznaczymy liczbe powtorzen do wyznaczenia dokladnego czasu
    */
    int* solve(NEXT_POINT_SEARCHING_SCENARIO SCENARIO, bool isGenerating = false, bool higherTimeResolution = false, COMPLEXITY_LEVELS sudokuLevel = EXTREMELY_EASY);
    /*!
    Funkcja zwracajaca tablice, w ktorej znajduje sie informacja na temat mozliwych do wstawienia wartosci w dana komorke.
    @param itsY - pozycja komorki w osi Y
    @param itsX - pozycja komorki w osi X
    @param sudokuArray - tablica z badanym sudoku
    @param resultArray - tablica mozliwych do wstawienia wartosci
    */
    static void checkPossibleValues(int itsY, int itsX, int* sudokuArray, bool* resultArray);
    /*!
    Funkcja do znalezienia wolnych komorek w siatce Sudoku i poszeregowaniu ich wg podanego scenariusza.
    @param SCENARIO - sposob rozwiazania Sudoku
    */
    void findAndSortEmptyCells(NEXT_POINT_SEARCHING_SCENARIO SCENARIO);
    /*!
    Funkcja rekurencyjna, poszukujaca rozwiazania Sudoku poprzez rozpinanie kolejnych galezi drzewa mozliwych rozwiazan.
    @param position - pozycja komorki, dla ktorej aktualnie poszukujemy rozwiazania
    @param isGenerating - flaga, mowiaca o tym, czy proces rozwiazywania jest wywolany do celow generacji sudoku.
    @param newIndex - pozycja komorki w posortowanej tablicy, dla ktorej aktualnie poszukujemy rozwiazania. Jest to informacja ktora komorke z rzedu analizujemy.
    @return 0 - jesli znaleziono rozwiazanie, -1 - gdy nie znaleziono rozwiazania, -2 - gdy Sudoku bylo zbyt dlugo rozwiazywane (przy generacji)
    */
    int recursiveSearchInTree(int position, bool isGenerating, unsigned newIndex);
    /*!
    Funkcja sluzaca do inicjalizacji zmiennych.
    */
    void initializeValues();
    /*!
    Funkcja sprawdza, czy wstawienie danej wartosci nie spowoduje kolizji w siatce Sudoku (czy mozemy wstawic dana wartosc w dane miejsce)
    @param position - pozycja do sprawdzenia
    @param value - wartosc, ktora chcemy wstawic
    @return true - jesli wystepuje kolizja, false - jesli dana wartosc mozna wstawic.
    */
    inline bool checkCollision(int position, int value);
    /*!
    Funkcja sluzaca do wstawienia wartosci w struktury reprezentujace wiersz, kolumne i grupe 3x3.
    @param position - pozycja, w ktora chcemy wstawic wartosc
    @param value - wartosc, ktora chcemy wstawic
    */
    inline void setCellValue(int position, int value);
    /*!
    Funkcja do usuwania wartosci z danej pozycji w strukturach reprezentujacych wiersz, kolumne i grupe 3x3.
    @param position - pozycja, z ktorej chcemy usunac wartosc
    @param value - wartosc, ktora chcemy usunac
    */
    inline void removeCellValue(int position, int value);

    /*!
    Funkcja konwertujaca pozycje w tablicy jednowymiarowej na pozycje dwuwymiarowa.
    @param position - pozycja jednowymiarowa
    @param newX - nowa pozycja w osi x
    @param newY - nowa pozycja w osi y
    */
    static void convert1Dto2D(int position, int& newY, int& newX) { newY = (position / 9) + 1, newX = (position % 9) + 1; }
    /*!
    Funkcja zwracajaca czas rozwiazania Sudoku.
    @return czas rozwiazania Sudoku
    */
    long long getSolveTime() { return m_solveTime; }
    /*!
    Funkcja zwracajaca ilosc operacji.
    @return ilosc operacji
    */
    long long getSolveComplexity() { return m_solveComplexity; }

private:
    /*!
    Tablica komorek siatki Sudoku.
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
    Tablica zawierajaca Sudoku.
    */
    int m_sudokuArray[81];
    /*!
    Tablica tymczasowa.
    */
    int m_sudokuTemporaryArray[81];
    /*!
    Czas rozwiazania Sudoku
    */
    long long m_solveTime;
    /*!
    Ilosc operacji
    */
    long long m_solveComplexity;
    /*!
    Wektor par numer komorki, liczba sasiadow.
    */
    vector< pair<int,int> > m_cellsVector;
    /*!
    Tablica wolnych komorek, posortowana w zaleznosci od trybu rozwiazywania.
    */
    int m_cellsArray[81];
    /*!
    Liczba wolnych komorek.
    */
    unsigned m_cellsNumber;
    /*!
    Flaga mowiaca o tym, czy Sudoku, ktore zostalo podane do konstruktora tej klasy, jest juz rozwiazane.
    */
    bool isSudokuAlreadySolved;
};


#endif // SudokuSolver_h