#include <stdio.h>

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
    int marks[3];
    marks[0] = 34;
    marks[1] = 45;
    marks[2] = 67;
    //for loop ----->
    // for(int i=0; i<3; i++){
    //     printf("Marks of students marks[%d] is %d\n", i, marks[i]);
    // }
    
    //while loop ----->
    int countdown = 0;
    while(countdown <= 5){
        printf("Marks of students marks[%d] is %d\n", countdown, marks[countdown]);
        countdown++;
    }

    return 0;
}

//Compilation --->
//Every time we change the code, we need to recomplie it. Generally we donot do this in javascript, python etc.