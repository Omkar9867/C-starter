#include <stdio.h>

void printArr(int param[]){
    for(int i = 0; i < 7; i++){
        printf(" %d \n", param[i]); 
    }
    printf("param-size = %ld\n", sizeof(param));
}
//Important: int param[] is 'decaying' to a pointer (type *int param). Complier also warn us that this happens
//In a way, this is very efficent other wise have to 'pass-by-value' and 'copy' the entire array
//Decaying is efficient but we do loose the size information that the actual array have which we pass by.

int main(){
    int array[7];
    for(int i = 0; i < 7; i++){
        array[i] = i; 
    }
    // for(int i = 0; i < 7; i++){
    //     printf("%d \n", array[i]); 
    // }
    // printf("%ld \n", sizeof(array));
    // Two equivalent ways, to create a pointer that points to the start of an array.
    // int* prarr = array;

    printArr(array);

    // int* prarr = &array[0];
    // for(int i = 0; i < 7; i++){
    //     printf(" %d \n", prarr[i]); 
    // }
    // printf("pointer arr size %ld \n", sizeof(prarr));

    //We can treat array lik a pointer
    //Example:
    // int array[7];
    // int* pArray = array;

    //Can treat pointer like an array?
    // int* pArray2;
    // int array2[7] = pArray2;
    // Output : invalid initializer
    return 0;
}

//sizeOf - is an operator that returns the size (in bytes) of a variable. Example the size of an int -> 4bytes
//For 'stack allocated' array, in the current block scope we can return the size of an array

//sizeOf - When used on a pointer, returns the size of the pointer data type.
// The size is typically '8 bytes' on a 64-bit architecture. 
// Example on above we passed the first elememt pointer to the new variable. so its size is of the single size. 