#ifndef SudokuGenerator_h
#define SudokuGenerator_h

#include "Common.h"

/*!
* Klasa generuj¹ca Sudoku.
*/
class SudokuGenerator {
public:
    /*!
    * Funkcja s³u¿¹ca do generacji Sudoku.
    * @param sudokuArray - wskaŸnik na tablicê, do której nale¿y zapisaæ wygenerowane Sudoku.
    * @param LEVEL - poziom trudnoœci Sudoku.
    */
    void generate(int* sudokuArray, COMPLEXITY_LEVELS LEVEL);
    /*!
    * Funkcja do odczytu Sudoku z pliku.
    * @param sudokuArray - wskaŸnik na tablicê, do której nale¿y zapisaæ wygenerowane Sudoku.
    * @param filename - œcie¿ka do pliku, który ma zostaæ otworzony.
    */
    void readFromFile(int* sudokuArray, string filename);
    /*!
    * Funkcja s³u¿aca do zapisu do pliku wygenerowanego Sudoku.
    * @param sudokuArray - wskaŸnik na tablicê, w którym znajduje siê Sudoku.
    */
    void saveToFile(int* sudokuArray);
    /*!
    * Funkcja do wyœwietlania Sudoku w konsoli.
    * @param sudokuArray - wskaŸnik na tablicê, w którym znajduje siê Sudoku.
    * @param name - opis Sudoku.
    * @param baseArray - wskaŸnk na tablice z pocz¹tkowo wygenerowanym Sudoku.
    */
    void printSudoku(int* sudokuArray, string name, int* baseArray = 0);
};


#endif // SudokuGenerator_h