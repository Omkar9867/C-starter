#include <stdio.h>
#include <assert.h>

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
    int x = 10;
    printf("Value of x in memory is: %p\n", &x); //will print the memory value if the actual value, %p is the format specifier for printing the values of pointers
    // if we want the value from the (&x)
    printf("Actual value of x is: %d\n", *(&x)); // pointer helps to extract the value stored in the address

    //Pointers
    //Creating the pointer
    int* px = &x; // * is used to create the pointer, and & is used to get the address of the variable

    //Accessing the value to what we pointed to.
    printf("The value of pointed valu: %d\n", *px);
    return 0;
}