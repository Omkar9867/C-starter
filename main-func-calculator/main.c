#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    // printf("argc: %d", argc);

    // for(int i=0; i<argc; i++){
    //     printf("\t%s\n", argv[i]);
    // }

    //We will write to assume this program will add two numbers and return the result 
    //==================================
    //First write fallback
    // if(argc != 3){
    //     printf("usage: ./add 1 2\n");
    //     return 0;
    // }
    // // int a = argv[1];
    // // int b = argv[2];
    // int a = strtol(argv[1], NULL, 10); //with default and fallback
    // int b = strtol(argv[2], NULL, 10);

    // int result = a+b;
    // printf("%d + %d = %d", a, b, result); // ----------> Will throw error cause argv is char type and we assining to int. 

    //More modular and add more numbers
    if(argc < 2){
        printf("usage: ./add 1 2 3......\n");
        return 0;
    }

    long result = 0;
    for(int i = 1; i < argc; i++){
        result += strtol(argv[i], NULL, 10);
    };
    printf("Result = %d", result);

    return 0;
}


//argc:  The total number of space separated arguments when our program is invoked.
//argv:  A vector of strings, including the filename of the program being run as the first argument. The last element argv[argc] is a null pointer
//Simple terms argc=argument counts and argv= variable arguments

//Example:
// If run : gcc main.c && a.exe
// output :argc: 1
// If run : gcc main.c && a.exe some_content
// output :argc: 2
// If run : gcc main.c && a.exe some_content awesome
// output :argc: 3

//char** is an array of strings-> A pointer to pointers type of char

//===============================================
//We can explicitly type cast (i.e. casting) one data type to be trated as another data type.
//Often we can do this with primitive type by specifying the type (e.g. printf(%f, float-variable)).
//Working with c strings, we have functions like "----strtol----" (string to long) to assist this process.