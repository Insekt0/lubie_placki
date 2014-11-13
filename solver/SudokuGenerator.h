#ifndef SudokuGenerator_h
#define SudokuGenerator_h

#include "Common.h"

/*!
* Klasa generuj�ca Sudoku.
*/
class SudokuGenerator {
public:
    /*!
    * Funkcja s�u��ca do generacji Sudoku.
    * @param sudokuArray - wska�nik na tablic�, do kt�rej nale�y zapisa� wygenerowane Sudoku.
    * @param LEVEL - poziom trudno�ci Sudoku.
    */
    void generate(int* sudokuArray, COMPLEXITY_LEVELS LEVEL);
    /*!
    * Funkcja do odczytu Sudoku z pliku.
    * @param sudokuArray - wska�nik na tablic�, do kt�rej nale�y zapisa� wygenerowane Sudoku.
    * @param filename - �cie�ka do pliku, kt�ry ma zosta� otworzony.
    */
    void readFromFile(int* sudokuArray, string filename);
    /*!
    * Funkcja s�u�aca do zapisu do pliku wygenerowanego Sudoku.
    * @param sudokuArray - wska�nik na tablic�, w kt�rym znajduje si� Sudoku.
    */
    void saveToFile(int* sudokuArray);
    /*!
    * Funkcja do wy�wietlania Sudoku w konsoli.
    * @param sudokuArray - wska�nik na tablic�, w kt�rym znajduje si� Sudoku.
    * @param name - opis Sudoku.
    * @param baseArray - wska�nk na tablice z pocz�tkowo wygenerowanym Sudoku.
    */
    void printSudoku(int* sudokuArray, string name, int* baseArray = 0);
};


#endif // SudokuGenerator_h