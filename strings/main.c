#include <stdio.h>
#include <stdlib.h>

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
    size_t length = 0;                   //int when used can be negative also, so we used size_t which is unsigned int i.e. it can't be below 0
    while(input[length] != '\0'){
        length++;
    }
    return length;
}

// Function StrAppend -> probably done by strcat
char* str_append(char* destination, const char* source){ // commin abbrevation dst = "destination" and src = "source"
    size_t dst_length = str_length(destination);
    size_t src_length = str_length(source);
    
    char* new_string = (char*)malloc(sizeof(char)*(dst_length + src_length + 1)); // +1 for the \0
    // Copy the destination string to the new string
    int i = 0;
    while(i<dst_length){
        new_string[i] = destination[i];
        i++;
    }
    // Copy the source string to the new string
    int j = 0;
    while(j<src_length){
        new_string[dst_length+j] = source[j];
        j++;
    }
    // Add the null terminator
    new_string[dst_length+src_length] = '\0';
    // destination[0] = 'B';
    destination = new_string;
    return new_string;
}

int main(){
    // char hello[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    // Since it is an array we can add or modify the values individually too. example: hello[0] = 'h';
    // printf("size of hello = %d\n ",sizeof(hello)); //Not used sizeof as it will give the size of the array not the length of the string
    // char hello[] = "Hello, World\0";
    // printf("%s\n", hello);
    // hello[0] = 'B';
    // printf("%s\n", hello);
    // printf("size of hello = %ld\n ",str_length(hello));
    //Malloc the char
    // char* name = (char*)malloc(sizeof(char)*5); // not to forget to add the size of the \0 also
    // name[0] = 'J';
    // name[1] = 'o';
    // name[2] = 'h';
    // name[3] = 'n';
    // name[4] = '\0';
    // printf("%s\n", name);
    // free(name);

    // char* name2 = "Johnny"; // --> string literal
    // printf("%s\n", name2);
    // printf("size of name2 = %ld\n ",str_length(name2)); // output is 6 because it also counts the \0
    // name2[0] = 'B'; // This will give an error because we can't modify the string literal. It has only read-only memory.
    // const char* name3 = "Johnny2"; // This is a way to make the string literal read-only
    // printf("%s\n", name3);

    char name[] = {'J', 'o', 'h', 'n', 'n', 'y', '\0'};
    char* new_name = str_append(name, " Doe");
    printf("%s\n", new_name);
    return 0;
}

// A character array (i.e. char name[0]) and a pointer to char (i.e. char *name) are two different things.

// The reason that string literal are not modifiable is because , the C compilar will generate assembly code 
// and eventually (a binary from the assemble), which stores the string literal in readonly region of the executable binary.