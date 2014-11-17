#ifndef SudokuGenerator_h
#define SudokuGenerator_h

#include "Common.h"

/*!
* Klasa generujaca Sudoku.
*/
class SudokuGenerator {
public:
    /*!
    * Funkcja sluzaca do generacji Sudoku.
    * @param sudokuArray - wskaznik na tablice, do ktorej nalezy zapisac wygenerowane Sudoku.
    * @param LEVEL - poziom trudnosci Sudoku.
    */
    void generate(int* sudokuArray, COMPLEXITY_LEVELS LEVEL);
};


#endif // SudokuGenerator_h