#ifndef MATH_H
#define MATH_H

typedef struct vector {
    float x;
    float y;
} vector_h;

//vector_h Add(vector_h v1,vector_h v2); //just define the function signature.

void Add(vector_h* out, const vector_h* in); //just define the function signature.

#endif
// if and endif used to prevent multiple inclusion of the same header file





//The intertface (.h header file) serves as a reference for the available functions or data structures that we create
