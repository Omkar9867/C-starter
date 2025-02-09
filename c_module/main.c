#include <stdio.h>
#include "math.h"
#include "math.c"

//Entry point of the program
int main(){
    vector_h first;
    first.x = 1.0f;
    first.y = 2.0f;
    
    vector_h second;
    second.x = 3.0f;
    second.y = 4.0f;

    Add(&first,&second);
    printf("Result of first.x = %f, and first.y = %f", first.x, first.y);

    return 0;
}