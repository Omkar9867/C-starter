#include <stdio.h>

// Functions must exist before they are called.
// int multiply(int a, int b){
//     return a*b;
// }

// Second method is to declare the function and then can define it later
int square(int x);

int main() {

    // puts("Hello, World2!");

    //Variables
    // int x = 40;
    // x = 70;
    // printf("Value of x is: %d\n", x);

    // float pi = 3.14f;
    // printf("Value of pi is %f\n", pi);

    //Arrays
    // int marks[3];
    // marks[0] = 34;
    // marks[1] = 45;
    // marks[2] = 67;
    // printf("Marks of student 1 is %d\n", marks[0]);
    // printf("Marks of student 2 is %d\n", marks[1]);
    // printf("Marks of student 3 is %d\n", marks[2]);

    //Loops
    // int marks[3];
    // marks[0] = 34;
    // marks[1] = 45;
    // marks[2] = 67;
    //for loop ----->
    // for(int i=0; i<3; i++){
    //     printf("Marks of students marks[%d] is %d\n", i, marks[i]);
    // }
    
    //while loop ----->
    // int countdown = 0;
    // while(countdown <= 5){
    //     printf("Marks of students marks[%d] is %d\n", countdown, marks[countdown]);
    //     countdown++;
    // }

    //Block scope
    // int x = 40;
    // {
    //     int x = 30;
    //     x++;
    //     printf("Value of x inside curly braces is %d\n", x); // the value is x in this curly braces only
    // }
    // printf("Value of x outside curly braces is %d\n", x); // so this value of x will not have access to the value of x inside the curly braces


    //Functions
    // int value = multiply(2, 3);
    // printf("The value of 2 * 3 is:  %d\n", value);

    printf("The square of 5 is: %d\n", square(5));
    return 0;
}

//Here i am defining the function
int square(int x){
    return x*x;
}

//Compilation --->
//Every time we change the code, we need to recomplie it. Generally we donot do this in javascript, python etc.

//Bugs
//Tips while solving bus:
//1. Start by fixing the first error.
//2. Don't panic
//3. Make a fewer changes, save, compile and then retest your code. 