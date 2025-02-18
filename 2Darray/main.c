#include <stdio.h>

int main(){
    int array[7];
    for(int i = 0; i < 7; i++){
        array[i] = i; 
    }
    for(int i = 0; i < 7; i++){
        printf("%d \n", array[i]); 
    }
    printf("%ld \n", sizeof(array));
    // Two equivalent ways, to create a pointer that points to the start of an array.
    // int* prarr = array;
    int* prarr = &array[0];
    for(int i = 0; i < 7; i++){
        printf(" %d \n", prarr[i]); 
    }
    printf("pointer arr size %ld \n", sizeof(prarr));
    return 0;
}

//sizeOf - is an operator that returns the size (in bytes) of a variable. Example the size of an int -> 4bytes
//For 'stack allocated' array, in the current block scope we can return the size of an array

//sizeOf - When used on a pointer, returns the size of the pointer data type.
// The size is typically '8 bytes' on a 64-bit architecture. 
// Example on above we passed the first elememt pointer to the new variable. so its size is of the single size. 