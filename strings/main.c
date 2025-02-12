#include <stdio.h>

//find the length of a string
// int str_length(char* input){
//     int length = 0;
//     while(input[length] != '\0'){
//         length++;
//     }
//     return length;
// }

//strlen is a function in string.h that does the same thing as the above function
//but there is some different approach in those strlen function that we will correct in our function
size_t str_length(const char* input){ //const is a way to not allow the function to modify the input
    size_t length = 0;                   //int when used can be negative also, so we used sixe_t which is unsigned int i.e. it can't be below 0
    while(input[length] != '\0'){
        length++;
    }
    return length;
}

int main(){
    char hello[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    // Since it is an array we can add or modify the values individually too. example: hello[0] = 'h';
    // printf("size of hello = %d\n ",sizeof(hello)); //Not used sizeof as it will give the size of the array not the length of the string
    // char hello[] = "Hello, World\0";
    printf("%s\n", hello);
    hello[0] = 'B';
    printf("%s\n", hello);
    printf("size of hello = %ld\n ",str_length(hello));
    return 0;
}

// A character array (i.e. char name[0]) and a pointer to char (i.e. char *name) are two different things.