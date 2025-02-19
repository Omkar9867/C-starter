#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// void printArr(int param[], size_t size){
//     for(int i = 0; i < size; i++){
//         printf(" %d \n", param[i]); 
//     }
    // printf("param-size = %ld\n", sizeof(param));
// }

//------------here we will use the struct i.e. custom arrat_t data type 
array_t* arrInit(size_t size){
    array_t* newArr = (array_t*)malloc(sizeof(array_t));
    newArr->size = size;
    newArr->data = (int*)malloc(sizeof(int)*size);

    return newArr;
}
//The above function used to assign size and initialize the array in malloc with its size passed and return


void printArr(array_t* myArr){
    for(int i = 0; i < myArr->size; i++){
        printf(" %ld\n", myArr->data[i]); 
    }
}
//Important: int param[] is 'decaying' to a pointer (type *int param). Complier also warn us that this happens
//In a way, this is very efficent other wise have to 'pass-by-value' and 'copy' the entire array
//Decaying is efficient but we do loose the size information that the actual array have which we pass by.

// int main(int argc, char** argv){
    // int array[7];
    // for(int i = 0; i < 7; i++){
    //     array[i] = i; 
    // }
    // for(int i = 0; i < 7; i++){
    //     printf("%d \n", array[i]); 
    // }
    // printf("%ld \n", sizeof(array));
    // Two equivalent ways, to create a pointer that points to the start of an array.
    // int* prarr = array;

    // printArr(array);

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

//     array_t* myArray = arrInit(7);
//     printArr(myArray);
//     free(myArray);
//     return 0;
// }

//sizeOf - is an operator that returns the size (in bytes) of a variable. Example the size of an int -> 4bytes
//For 'stack allocated' array, in the current block scope we can return the size of an array

//sizeOf - When used on a pointer, returns the size of the pointer data type.
// The size is typically '8 bytes' on a 64-bit architecture. 
// Example on above we passed the first elememt pointer to the new variable. so its size is of the single size. 


//The memory allocator (malloc and free) will otherwize know how big the block of memoey is. But for arbitary pointers again we store an address(&), and not 
// the size of heap allocated block memory

// ---------------------------------------------------------------------------------------

//Function to print 1D array as 2D as pointer
void print2DArrWithPointer(int* arr, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d\t", arr[i * cols + j]); // Accessing 2D array as a 1D array (ith row * size of cols + jth elem) 
        }
        printf("\n");
    }
}


int main(int argc, char** argv){
    //ROWS by COLS
    int* array2D[5][4];
    // int counter = 0;
    // for(int i=0; i<5; i++){
    //     for(int j = 0; j < 4; j++){
    //         array2D[i][j] = counter++;
    //         printf("%d\t", array2D[i][j]);
    //     }
    //     printf("\n");
    // }
    //In actual we have 1D array itself pitch in line.

    print2DArrWithPointer(array2D, 5, 4);

    //Since it can result warning we can use malloc and free to store in the pointer style.
    return 0;
}


//2D array-->
// Visually , it's like to draw a 2D array with multiple rows and columns.
//Conceptually, it is still one linear address space.

//The order you 'traverse' or visit each element in a multi-dimensional araay matters!
//The more it's 'skip' , the worse typically for hardware, which otherwise tries to prefetch data laid out sequentially

//Pitch of an array ---> How many bytes a single row has?
//If we store '4ints' in a row, and those are 4 bytes each, the pitch is 16 bytes.