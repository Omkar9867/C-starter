#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int add(int a, int b){
    return a+b;
}

int multiply(int a, int b){
    return a*b;
}

//* A function signature consist of the function return type and it's arguments at the very least. When we declare function, we also provide name to reference that function.

int main(int argc, char** argv){

    // printf("&add: %p\n", &add);

    //Create a Function Pointer
    //'pfn' is a common prefix for the funtion pointer data types. 
    // int (* pfn)(int, int) = add; //or &a
    // printf("2 + 3 = %d", pfn(2, 3));
    //Can also use assign multiply function as it has same signature

    srand(time(NULL));

    int (* pfn)(int, int) = NULL;
    int randomNumber = rand()%2 +1;
    if(randomNumber == 1){
        pfn = add;
        printf("2 + 3 = %d", pfn(2, 3));
    }else{
        pfn = multiply;
        printf("2 * 3 = %d", pfn(2, 3));
    }
// Here we will observe that while the program is running, anywhere we have pfn we can ressign that pointer
// thus chnaging the behaviour of the program. Common in every event driven programming
// Function pointer can also be passed into argument of the fucntion as well

    return 0;
}


// Function-Pointers: Ability to store the function adderess of a specific function signature.
//It is often recommended to read the function pointer 'inside out'
//-Start with the name i.e. *pfn
//-Look at the return type i.e. int
//-Then look at the arguments i.e. (int, int)

//? What is ia signature?
//Basically a function has a name i.e. add, arguments i.e. 'a' and 'b', and returns val i.e. a+b.
//Helps to Encapsulate or hold the behaviour of the function in a pointer.

//In other language we have OOP like classes , but in C we have 'structs'


//When tried to compile gcc -S main.c --> It will create an main.s i.e. an assembly file
//Assembly is generally a textual representation of binary  

//When using linux, 
//objump --> is a neat tool that allows to inspect binary files. Can be very useful while debugging.
//cmd --> objump -t ./prog