#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//Recurssion
// void func(int a){
//     if (a < 0){
//         return;
//     }
//     printf("%d\n", a);
//     func(a-1);
// }

//Asserts
// void func(unsigned int a){ //unsigned just represent a big positive number so while calling with negative it will not get error but crash though 
//    void func(int a){ 
//     assert(a > 0 && "Value was not greater than 0"); //It checks the a should be greater than 0 so it can initially throw error rathar then crash
//     if (a < 0){
//         return;
//     }
//     printf("%d\n", a);
//     func(a-1);
// }

int main(){
    //Conditional statements
    // func(-3);
    // int x = 0;
    // puts("Enter a number for x: ");
    // scanf("%d", &x); //scanf is used to take input from the user, and & is used to store the value of x in the memory location of x
    // if(x>0){
    //     printf("x is positive\n");
    // }else if (x==0){
    //     printf("x is zero\n");
    // }else{
    //     printf("x is negative\n");
    // }

    //Ampercend operator
    // int x = 10;
    // printf("Value of x in memory is: %p\n", &x); //will print the memory value if the actual value, %p is the format specifier for printing the values of pointers
    // if we want the value from the (&x)
    // printf("Actual value of x is: %d\n", *(&x)); // pointer helps to extract the value stored in the address

    //Pointers
    //Creating the pointer
    // int* px = &x; // * is used to create the pointer, and & is used to get the address of the variable

    //Accessing the value to what we pointed to.
    // printf("The value of pointed valu: %d\n", *px);


    //Malloc & Free
    int sizeOfArr = 0;
    // scanf("%d", &sizeOfArr);
    int* dynamicArr = malloc(sizeof(int)*sizeOfArr);
    // dynamicArr[0] = 1;
    // dynamicArr[1] = 2;
    // dynamicArr[2] = 3;
    // dynamicArr[3] = 4;
    // dynamicArr[4] = 5;
    // dynamicArr[5] = 6;
    // dynamicArr[6] = 6;
    // dynamicArr[7] = 6;
    // dynamicArr[8] = 6;
    for (int i = 0; i < sizeOfArr; i++){
        printf("%d\n", dynamicArr[i]);
    } 
    printf("Size of arr is: %d\n", sizeof(dynamicArr));
    free(dynamicArr);
    printf("Size of arr is: %d\n", sizeof(dynamicArr));
    
    //The reason to use Malloc and Free is because it allows to determine while our program is running how much memory to allocate,
    //And we use pointer to 'point-to' the dynamically allocated memory.

    //Pass by value
    void setVal(int* val) {
        *(val) = 999;
    };
    int x = 10;
    // setVal(x); //When we pass the x to the fucntion it makes a copy of the value of x and pass it to the function, so the value of x will not change
    // printf("Value of x is: %d\n", x);
    //but if you want to chnage value:
    setVal(&x); //passing the address of x, but the function need to access this address by making its value to pointer
    printf("Value of x is: %d\n", x);
    return 0;
}

//Malloc [M-Memory, alloc-allocator] ==> Return a pointer to the start of a specific number of bytes. (Note 'sizeof(type)' retrieves the number of bytes of a type)
//Free ==> Release the memory that was allocated by malloc. (Note: It is important to free the memory that was allocated by malloc to avoid memory leaks)