#include <stdio.h>

void print(){
    printf("Hello World\n");
}

int returnType(){
    return 42;
}

int add(int a, int b){
    return a + b;
}

int main(){
    // void* to a int*
    int x = 10;
    void* genericPointer = &x;
    // To dereference the void pointer, we need to cast it to the correct type first.
    printf("Value of x: %d\n", *(int*)genericPointer);

    // void* to a function
    genericPointer = print;
    ((void(*)())genericPointer)();  // (void(*)()) is the function pointer type. then wrap them in a () to call the function.

    genericPointer = returnType;
    int result = ((int(*)())genericPointer)();
    printf("Result %d\n", result);

    genericPointer = add;
    int a = 5, b = 10;
    int sum = ((int(*)(int, int))genericPointer)(a, b);
    printf("Sum: %d\n", sum);
    return 0;
}


// * Void Pointer
// A void* is a 'generic' pointer that can hold any data type.
//! void* pointers cannot be dereference, we have to cast it to the correct type first. Example above...
// The example where void* is used is //*malloc
// Example we assign the memory type to malloc: int* p = (int*)malloc(sizeOf(int)*10); 