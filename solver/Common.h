#ifndef Common_h
#define Common_h

#include <iostream>
#include <string>

using namespace std;

#define DEBUG_MODE 1
#define ENSURE_FAST_GENERATION 1

#if ENSURE_FAST_GENERATION
#define MAX_OPERATIONS 1000000
#endif

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
#define NDEBUG 1
#define LOG(args, ...) (void)0
#endif

#include <assert.h>

#endif // Common_h