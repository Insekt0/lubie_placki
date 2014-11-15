#ifndef Common_h
#define Common_h

#include <iostream>
#include <string>

using namespace std;

/*!
Define dla trybu debuggowego, który w³¹cza asercje i dodatkowe logi
*/
#define DEBUG_MODE 0

/*!
Zapewnienie szybkiej generacji sudoku - jeœli liczba kroków przekroczy MAX_OPERATIONS, sudoku jest generowane od nowa
*/
#define ENSURE_FAST_GENERATION 1

#if ENSURE_FAST_GENERATION
/*!
Ustawienie maksymalnej liczby operacji przy generowaniu sudoku, po której jest ono generowane od nowa
*/
#define MAX_OPERATIONS 1000000
#endif


/*!
Enumeracja mo¿liwych poziomów trudnoœci
*/
enum COMPLEXITY_LEVELS {
    EXTREMELY_EASY = 1,
    EASY,
    MEDIUM,
    DIFFICULT,
    EVIL
};


/*!
Enumeracja mo¿liwych trybów przeszukiwania sudoku
*/
enum NEXT_POINT_SEARCHING_SCENARIO {
    MOST_NEIGHBOURS = 1,
    RANDOM
};

#if DEBUG_MODE
/*!
W³¹czenie dodatkowych logów debugowych
*/
#define LOG(args, ...) printf(args, ##__VA_ARGS__)
#else
/*!
Wy³¹czenie assercji
*/
#define NDEBUG 1
/*!
Wy³¹czenie dodatkowych logów
*/
#define LOG(args, ...) (void)0
#endif

#include <assert.h>

#endif // Common_h