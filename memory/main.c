#include <stdio.h>
#include <stdlib.h>

//Block scope
// void foo(){
//     int a = 4; //local variable which is used inside this block only.
// }
// If we made a loop and called the function foo(), the variable will be created every time foo is called and can use our memory.
// Stack
// The stack is where our temporary (local variable) memory is stored. It pushs/add variables to the top of the stack and pops/removes variables from the top of the stack.

// void foo(int x){ //temporary copy in the stack
//     int a = 4; 
//     int b = 5;
//     int c = 6;

//     bar();
// }

// void bar(){
//     int d = 8;
// }


//Heap memory
// The heap is where our dynamic memory is stored. It is a large pool of memory that can be used to store data that needs to be accessed from anywhere in the program.
// We can allocat or free this memory i.e malloc and free.

//Lets call the malloc on heap as a function.
int* allocateOnHeap(int size){
    int* array = (int*)malloc(sizeof(int)*size);
    printf("Heap memory address = %p\n", array); // we can see the address of the memory
    printf("Heap memory address = %p\n", &array); // we can see the address of the memory
    for(int i=0; i<size; i++){
        array[i] = i;
    }
    return array;
}

//We allocated memory on heap using malloc, but we have to free it as well. so the array when return and done using, we have to free it.


int main(){

    // int x = 4; //local variable
    // foo();

    // malloc(sizeof(int)*5000); //heap has large memory so can store this much , but in stack it may overflow. But it returns a void* pointer. What is it?
    //void* means any data type, but we have to explicitly cast it to the data type first.
    // int* arr = (int*)malloc(sizeof(int)*5000); //casting void* to int*.
    // Since it is a long lived memory we have to free it.
    // free(arr);
    int size = 7;
    int* heapArr = allocateOnHeap(size);
    printf("Heap memory address = %p\n", heapArr); // Address would be same what the function returned array is as it is a pointer.
    printf("Heap memory address = %p\n", &heapArr); // But the local variable i.e. stack address is different in this case &heapArr and in func &arr
    for(int i=0; i<size; i++){
        printf("heapData[%d] = %d\n",i, heapArr[i]);
    };
    free(heapArr);
    return 0;
}


// The memory is a process (a running program) that has its own memory space. Typically this means 'RAM' (Random Access Memory) -> the green sticks you put in your machine.
// The memory is divided into two parts: the stack and the heap.

// Each variable takes different number of bytes to a memory
// Can use sizeof() to get how many bytes a data type needs.
// In other languages, the memory is controlled by the language itself, but in C, we have control over the memory to use.