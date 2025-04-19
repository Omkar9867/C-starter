#include <stdio.h>

// typedef struct StagesCompleted{
//     int leve1Completed;
//     int level2Completed;
//     int level3Completed;
//     int level4Completed;
//     int level5Completed;
//     int level6Completed;
//     int level7Completed;
//     int level8Completed;
// }StagesCompleted_t;

// But lets say if we want to store value less than the int size.
// typedef struct StagesCompleted{
//     char leve1Completed;
//     char level2Completed;
//     char level3Completed;
//     char level4Completed;
//     char level5Completed;
//     char level6Completed;
//     char level7Completed;
//     char level8Completed;
// }StagesCompleted_t;

// But what if we only want to store values : example 1, 0. Then we could assign number of bit to each level
typedef struct StagesCompleted{
    char leve1Completed: 1;
    char level2Completed: 1;
    char level3Completed: 1;
    char level4Completed: 1;
    char level5Completed: 1;
    char level6Completed: 1;
    char level7Completed: 1;
    char level8Completed: 1;
}StagesCompleted_t;
// Here internally some kind of bit shifting is done to offset/shift by 1 byte.

int main(){

    // printf("Size of StagesCompleted_t = %ld\n", sizeof(StagesCompleted_t));
    // answer could be : 28
    // printf("Size of StagesCompleted_t = %ld\n", sizeof(StagesCompleted_t));
    // answer could be : 8
    printf("Size of StagesCompleted_t = %ld\n", sizeof(StagesCompleted_t));
    // answer could be : 1
    return 0;
}


//? Bit Fields
// internally some kind of bit shifting is done to offset/shift respective to the assigned byte
// If we try to use only 3 bit in the struct and not 8, the c compiler by default compiles to 8 bits kind of padding as 1 byte is the minimum size of a data type.