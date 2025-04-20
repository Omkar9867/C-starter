#include <stdio.h>

typedef union{
    char c;
    int i;
    long long l;
}example_t;

typedef struct{
    char c;
    int i;
    long long l;
}example2_t;

// In a Matrix Example:
// ---           ---
// | 1 | 0 | 0 | 0 |     // --> 4x4 matrix
// | 0 | 1 | 0 | 0 |
// | 0 | 0 | 1 | 0 |
// | 0 | 0 | 0 | 1 |
// --            ---

typedef struct{
    float w, x, y, z;
} vect4_t;

typedef union{
    float elem[16];
    vect4_t row[4];
} matrix_t;


int main(){
    example_t myExample;
    example2_t my2Example;
    // printf("Size of union: %lu\n", sizeof(myExample)); // Result the max size of the member: long long: //*8
    // printf("Size of struct: %lu\n", sizeof(my2Example)); // Result the sum of the size of all members: //*8 + 4 + 1 + some-padding

    matrix_t myMatrix;
    for(int i=0; i<16; i++){
        myMatrix.elem[i] = i;
    }
    printf("%f\n", myMatrix.row[0].w); // Result: 0.000000
    printf("%f\n", myMatrix.row[0].x); // Result: 1.000000
    printf("%f\n", myMatrix.row[0].y); // Result: 2.000000
    printf("%f\n", myMatrix.row[0].z); // Result: 3.000000
    return 0;
}

//Union
// A union is a data structure that allows you to store different data types in the same memory location.
// It is similar to a struct, but with a key difference: in a union, all members share the same memory location.
// A union data type occupies the size of its largest member

// A library called: SDL Event
// SDL_Event is a union that can store different types of events, such as keyword events, mouse events, etc.
// The union allows you to save memory by only using the amount of space needed for the largest event type.