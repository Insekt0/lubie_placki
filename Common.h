#ifndef Common_h
#define Common_h

#include <assert.h>
#include <iostream>
#include <string>

using namespace std;


#define DEBUG_MODE 0

enum COMPLEXITY_LEVELS {
    EXTREMELY_EASY = 1,
    EASY,
    MEDIUM,
    DIFFICULT,
    EVIL
};

enum NEXT_POINT_SEARCHING_SCENARIO {
    MOST_NEIGHBOURS = 1,
    RANDOM
};

#if DEBUG_MODE
#define LOG(args, ...) printf(args, ##__VA_ARGS__)
#else
#define NDEBUG
#define LOG(args, ...) (void)0
#endif

#endif // Common_h