#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

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

    //Struct
    // struct student{
    //     char name[50];
    //     int age;
    //     float marks;
    // };

    // struct student mike;
    // mike.age = 20;
    // mike.marks = 90.5;
    // printf("Age of mike is: %d\n", mike.age);

    //Alternately we can add typedef to the struct so no need to write struct when declaring the variable
    typedef struct student{
        char* name;
        int age;
        float marks;
    } student_t;

    // void printStudent(student_t s){
    //     printf("Name:          %d\n", s.name);
    //     printf("Age:           %d\n", s.age);
    //     printf("Marks:         %d\n", s.marks);
    // }

    void printStudent(student_t* s){               //If expecting as pointer to struct then we need to use -> to access the values
        printf("Name:          %d\n", s->name);  // '->' is done similar as (*s).name ====> first dereference i.e find the address of the pointer field and then access the value
        printf("Age:           %d\n", s->age);
        printf("Marks:         %d\n", s->marks);
    }

    //Linked List struct
    typedef struct node{
        int data;
        struct node* next;
    }node_t;

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
    // int sizeOfArr = 0;
    // scanf("%d", &sizeOfArr);
    // int* dynamicArr = malloc(sizeof(int)*sizeOfArr);
    // dynamicArr[0] = 1;
    // dynamicArr[1] = 2;
    // dynamicArr[2] = 3;
    // dynamicArr[3] = 4;
    // dynamicArr[4] = 5;
    // dynamicArr[5] = 6;
    // dynamicArr[6] = 6;
    // dynamicArr[7] = 6;
    // dynamicArr[8] = 6;
    // for (int i = 0; i < sizeOfArr; i++){
    //     printf("%d\n", dynamicArr[i]);
    // } 
    // printf("Size of arr is: %d\n", sizeof(dynamicArr));
    // free(dynamicArr);
    // printf("Size of arr is: %d\n", sizeof(dynamicArr));
    
    //The reason to use Malloc and Free is because it allows to determine while our program is running how much memory to allocate,
    //And we use pointer to 'point-to' the dynamically allocated memory.

    //Pass by value
    // void setVal(int* val) {
    //     *(val) = 999;
    // };
    // int x = 10;
    // setVal(x); //When we pass the x to the fucntion it makes a copy of the value of x and pass it to the function, so the value of x will not change
    // printf("Value of x is: %d\n", x);
    //but if you want to change value:
    // setVal(&x); //passing the address of x, but the function need to access this address by making its value to pointer
    // printf("Value of x is: %d\n", x);

    //Strings and Literals
    char* x = "Hello World\0";
    char y[] = "Hello World";
    //there's difference between char* and char[], char* is the pointer to the string literal, and char[] is the array of characters, and array can be modified
    // x[0] = '2';
    // y[0] = '2';
    // printf("Value of x is: %c", x);
    printf("Value of x is: %c\n", x[0]);
    printf("Length of str x is: %d\n", strlen(x));


    student_t mike;
    mike.name = "Mike";
    mike.age = 20;
    mike.marks = 90.5;
    printStudent(&mike);
    // printf("Age of mike is: %d\n", mike.age);

    // linkedList acccess
    node_t one;
    node_t two;
    node_t three;

    one.data = 1;
    one.next = &two;
    two.data = 2;
    two.next = &three;
    three.data = 3;
    three.next = NULL;

    // In this step i linked each node together by pointing the field of each node_t next field to the address of the another node.
    // the last node points to NUll to indicate that it is the last node in the linked list.
    // Linked data structures can have any numbers of connections. One reason to use linked data structures is that they can grow and shrink in size by
    //removing or rearranging the pointers

    // Looping through the linked data structures
    node_t* iterate = &one;
    while(iterate != NULL){
        printf("Data: %d\n", iterate->data);
        iterate = iterate->next;
    }

    return 0;
}

//Malloc [M-Memory, alloc-allocator] ==> Return a pointer to the start of a specific number of bytes. (Note 'sizeof(type)' retrieves the number of bytes of a type)
//Free ==> Release the memory that was allocated by malloc. (Note: It is important to free the memory that was allocated by malloc to avoid memory leaks)

//Linked list
// Linked list are the linked data structure, where each node contains the data and the address of the next node.
// The key idea is that a part of our 'node_t' struct is a pointer to another 'node_t' struct.