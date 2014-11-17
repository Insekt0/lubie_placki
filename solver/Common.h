#ifndef Common_h
#define Common_h

#include <iostream>
#include <string>

using namespace std;

/*!
Define dla trybu debuggowego, ktory wlacza asercje i dodatkowe logi
*/
#define DEBUG_MODE 0

/*!
Zapewnienie szybkiej generacji sudoku - jesli liczba krokow przekroczy MAX_OPERATIONS, sudoku jest generowane od nowa
*/
#define ENSURE_FAST_GENERATION 1

#if ENSURE_FAST_GENERATION
/*!
Ustawienie maksymalnej liczby operacji przy generowaniu sudoku, po ktorej jest ono generowane od nowa
*/
#define MAX_OPERATIONS 1000000
#endif


/*!
Enumeracja mozliwych poziomow trudnosci
*/
enum COMPLEXITY_LEVELS {
    EXTREMELY_EASY = 1,
    EASY,
    MEDIUM,
    DIFFICULT,
    EVIL
};


/*!
Enumeracja mozliwych trybow przeszukiwania sudoku
*/
enum NEXT_POINT_SEARCHING_SCENARIO {
    MOST_NEIGHBOURS = 1,
    RANDOM
};

#if DEBUG_MODE
/*!
Wlaczenie dodatkowych logow debugowych
*/
#define LOG(args, ...) printf(args, ##__VA_ARGS__)
#else
/*!
Wylaczenie assercji
*/
#define NDEBUG 1
/*!
Wylaczenie dodatkowych logow
*/
#define LOG(args, ...) (void)0
#endif

#include <assert.h>

#endif // Common_h