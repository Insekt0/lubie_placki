#ifndef Common_h
#define Common_h

#include <string>
#define DEBUG_MODE 0

using namespace std;

enum COMPLEXITY_LEVELS {
    EXTREMELY_EASY = 1,
    EASY,
    MEDIUM,
    DIFFICULT,
    EVIL
};


#if DEBUG_MODE
#define LOG(args, ...) printf(args, ##__VA_ARGS__)
#else
#define LOG(args, ...) (void)0
#endif


#endif // Common_h