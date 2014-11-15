#ifndef SudokuSolver_h
#define SudokuSolver_h

#include "Common.h"

#include <vector>

/*!
Struktura opisuj¹ca komórkê w siatce ³amig³ówki Sudoku.
*/
struct Cell {
    /*!
    WskaŸnik na wiersz, w której znajduje siê dana komórka.
    */
    int* m_row;
    /*!
    WskaŸnik na kolumnê, w której znajduje siê dana komórka.
    */
    int* m_column;
    /*!
    WskaŸnik na grupê 3x3, w której znajduje siê dana komórka.
    */
    int* m_square;
};

/*!
* Klasa implementuj¹ca algorytm rozwi¹zywania Sudoku.
*/
class SudokuSolver {
public:
    /*!
    Konstruktor klasy SudokuSolver.
    @param sudokuArray - Sudoku, które mamy rozwi¹zaæ.
    */
    SudokuSolver(int* sudokuArray);
    /*!
    Funkcja s³u¿¹ca do zarz¹dzania procesem rozwi¹zania Sudoku.
    @param SCENARIO - sposób rozwi¹zania
    @param isGenerating - flaga, mówi¹ca o tym, czy proces rozwi¹zywania jest wywo³any do celów generacji sudoku.
    */
    int* solve(NEXT_POINT_SEARCHING_SCENARIO SCENARIO, bool isGenerating = false);
    /*!
    Funkcja zwracaj¹ca tablicê, w której znajduje siê informacja na temat mo¿liwych do wstawienia wartoœci w dan¹ komórkê.
    @param itsY - pozycja komórki w osi Y
    @param itsX - pozycja komórki w osi X
    @param sudokuArray - tablica z badanym sudoku
    @param resultArray - tablica mo¿liwych do wstawienia wartoœci
    */
    static void checkPossibleValues(int itsY, int itsX, int* sudokuArray, bool* resultArray);
    /*!
    Funkcja do znalezienia wolnych komórek w siatce Sudoku i poszeregowaniu ich wg podanego scenariusza.
    @param SCENARIO - sposób rozwi¹zania Sudoku
    */
    void findAndSortEmptyCells(NEXT_POINT_SEARCHING_SCENARIO SCENARIO);
    /*!
    Funkcja rekurencyjna, poszukuj¹ca rozwi¹zania Sudoku poprzez rozpinanie kolejnych ga³êzi drzewa mo¿liwych rozwi¹zañ.
    @param position - pozycja komórki, dla której aktualnie poszukujemy rozwi¹zania
    @param isGenerating - flaga, mówi¹ca o tym, czy proces rozwi¹zywania jest wywo³any do celów generacji sudoku.
    @param newIndex - pozycja komórki w posortowanej tablicy, dla której aktualnie poszukujemy rozwi¹zania. Jest to informacja któr¹ komórkê z rzêdu analizujemy.
    @return 0 - jeœli znaleziono rozwi¹zanie, -1 - gdy nie znaleziono rozwi¹zania, -2 - gdy Sudoku by³o zbyt d³ugo rozwi¹zywane (przy generacji)
    */
    int recursiveSearchInTree(int position, bool isGenerating, unsigned newIndex);
    /*!
    Funkcja s³u¿aca do inicjalizacji zmiennych.
    */
    void initializeValues();
    /*!
    Funkcja sprawdza, czy wstawienie danej wartoœci nie spowoduje kolizji w siatce Sudoku (czy mo¿emy wstawiæ dan¹ wartoœæ w dane miejsce)
    @param position - pozycja do sprawdzenia
    @param value - wartoœæ, któr¹ chcemy wstawiæ
    @return true - jeœli wystêpuje kolizja, false - jeœli dan¹ wartoœæ mo¿na wstawiæ.
    */
    inline bool checkCollision(int position, int value);
    /*!
    Funkcja s³u¿aca do wstawienia wartoœci w struktury reprezentuj¹ce wiersz, kolumnê i grupê 3x3.
    @param position - pozycja, w któr¹ chcemy wstawiæ wartoœæ
    @param value - wartoœæ, któr¹ chcemy wstawiæ
    */
    inline void setCellValue(int position, int value);
    /*!
    Funkcja do usuwania wartoœci z danej pozycji w strukturach reprezentuj¹cych wiersz, kolumnê i grupê 3x3.
    @param position - pozycja, z której chcemy usun¹æ wartoœæ
    @param value - wartoœæ, któr¹ chcemy usun¹æ
    */
    inline void removeCellValue(int position, int value);

    /*!
    Funkcja konwertuj¹ca pozycjê w tablicy jednowymiarowej na pozycjê dwuwymiarow¹.
    @param position - pozycja jednowymiarowa
    @param newX - nowa pozycja w osi x
    @param newY - nowa pozycja w osi y
    */
    static void convert1Dto2D(int position, int& newY, int& newX) { newY = (position / 9) + 1, newX = (position % 9) + 1; }
    /*!
    Funkcja zwracaj¹ca czas rozwi¹zania Sudoku.
    @return czas rozwi¹zania Sudoku
    */
    long long getSolveTime() { return m_solveTime; }
    /*!
    Funkcja zwracaj¹ca iloœæ operacji.
    @return iloœæ operacji
    */
    long long getSolveComplexity() { return m_solveComplexity; }

private:
    /*!
    Tablica komórek siatki Sudoku.
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
    Tablica zawieraj¹ca Sudoku.
    */
    int m_sudokuArray[81];
    /*!
    Tablica tymczasowa.
    */
    int m_sudokuTemporaryArray[81];
    /*!
    Czas rozwi¹zania Sudoku
    */
    long long m_solveTime;
    /*!
    Iloœæ operacji
    */
    long long m_solveComplexity;
    /*!
    Wektor par numer komórki, liczba s¹siadów.
    */
    vector< pair<int,int> > m_cellsVector;
    /*!
    Tablica wolnych komórek, posortowana w zale¿noœci od trybu rozwi¹zywania.
    */
    int m_cellsArray[81];
    /*!
    Liczba wolnych komórek.
    */
    unsigned m_cellsNumber;
    /*!
    Flaga mówi¹ca o tym, czy Sudoku, ktore zostalo podane do konstruktora tej klasy, jest ju¿ rozwi¹zane.
    */
    bool isSudokuAlreadySolved;
};


#endif // SudokuSolver_h