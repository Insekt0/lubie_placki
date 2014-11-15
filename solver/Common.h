#ifndef Common_h
#define Common_h

#include <iostream>
#include <string>

using namespace std;

/*!
Define dla trybu debuggowego, kt�ry w��cza asercje i dodatkowe logi
*/
#define DEBUG_MODE 0

/*!
Zapewnienie szybkiej generacji sudoku - je�li liczba krok�w przekroczy MAX_OPERATIONS, sudoku jest generowane od nowa
*/
#define ENSURE_FAST_GENERATION 1

#if ENSURE_FAST_GENERATION
/*!
Ustawienie maksymalnej liczby operacji przy generowaniu sudoku, po kt�rej jest ono generowane od nowa
*/
#define MAX_OPERATIONS 1000000
#endif


/*!
Enumeracja mo�liwych poziom�w trudno�ci
*/
enum COMPLEXITY_LEVELS {
    EXTREMELY_EASY = 1,
    EASY,
    MEDIUM,
    DIFFICULT,
    EVIL
};


/*!
Enumeracja mo�liwych tryb�w przeszukiwania sudoku
*/
enum NEXT_POINT_SEARCHING_SCENARIO {
    MOST_NEIGHBOURS = 1,
    RANDOM
};

#if DEBUG_MODE
/*!
W��czenie dodatkowych log�w debugowych
*/
#define LOG(args, ...) printf(args, ##__VA_ARGS__)
#else
/*!
Wy��czenie assercji
*/
#define NDEBUG 1
/*!
Wy��czenie dodatkowych log�w
*/
#define LOG(args, ...) (void)0
#endif

#include <assert.h>

#endif // Common_h