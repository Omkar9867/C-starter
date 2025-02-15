#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
// size_t str_length(const char* input){ //const is a way to not allow the function to modify the input
//     size_t length = 0;                   //int when used can be negative also, so we used size_t which is unsigned int i.e. it can't be below 0
//     while(input[length] != '\0'){
//         length++;
//     }
//     return length;
// }

// Function StrAppend -> probably done by strcat
// char* str_append(char* src_1, const char* src_2){ // commin abbrevation dst = "destination" and src = "source"
//     size_t dst_length = str_length(src_1);
//     size_t src_length = str_length(src_2);
    
//     char* new_string = (char*)malloc(sizeof(char)*(dst_length + src_length + 1)); // +1 for the \0
//     // Copy the destination string to the new string
//     int i = 0;
//     while(i<dst_length){
//         new_string[i] = src_1[i];
//         i++;
//     }
//     // Copy the source string to the new string
//     int j = 0;
//     while(j<src_length){
//         new_string[dst_length+j] = src_2[j];
//         j++;
//     }
//     // Add the null terminator
//     new_string[dst_length+src_length] = '\0';
//     // destination[0] = 'B';
//     // destination = new_string;
//     return new_string;
// }

//Modular approach
// char* str_append(char* dest, const char* src){
//     size_t dest_len = str_length(dest);
//     size_t src_len = str_length(src);
//     size_t i;
//     for(i=0; i<src_len && src[i] != '\0'; i++){
//         dest[dest_len+i] = src[i];
//     }
//     dest[dest_len+i] = '\0'; //since i was incremented in the loop
//     return dest;
// }

//realloc
// char* str_append(char* src_1, const char* src_2){  // make sure when passing the char used malloc cause realloc works on heap memory
//     size_t dst_length = str_length(src_1);
//     size_t src_length = str_length(src_2);
    
//     char* new_string = (char*)realloc(src_1,sizeof(char)*(dst_length + src_length + 1)); 
//     // Here the realloc copies the content of the src_1 to the new_string and then adds the new memory to the new_string
//     //So no need for the src_1 to copy in the new_string explicitly
//     // int i = 0;
//     // while(i<dst_length){
//     //     new_string[i] = src_1[i];
//     //     i++;
//     // }
//     int j = 0;
//     while(j<src_length){
//         new_string[dst_length+j] = src_2[j];
//         j++;
//     }
//     new_string[dst_length+src_length] = '\0';
//     return new_string;
// }

//memcpy && strlen
char* str_append(char* src_1, const char* src_2){  // make sure when passing the char used malloc cause realloc works on heap memory
    size_t dst_length = strlen(src_1);
    size_t src_length = strlen(src_2);
    
    char* new_string = (char*)realloc(src_1,sizeof(char)*(dst_length + src_length + 1)); 
    memcpy(new_string+dst_length, src_2, src_length); // plus dst_length because we want to append the src_2 to the end of the src_1 which is in the new_string
    // Here no need of the src_2 to copy explicitly in the new_string because memcpy copies it.
    // int j = 0;
    // while(j<src_length){
    //     new_string[dst_length+j] = src_2[j];
    //     j++;
    // }
    new_string[dst_length+src_length] = '\0';
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

    // char name[20] = {'J', 'o', 'h', 'n', 'n', 'y', '\0'};
    char* name = (char*)malloc(sizeof(char)*6);
    name[0] = 'J';
    name[1] = 'o';
    name[2] = 'h';
    name[3] = 'n'; 
    name[4] = '\0'; 
    char* new_name = str_append(name, " Doe");
    printf("%s\n", new_name);
    free(new_name);
    return 0;
}

// A character array (i.e. char name[0]) and a pointer to char (i.e. char *name) are two different things.

// The reason that string literal are not modifiable is because , the C compilar will generate assembly code 
// and eventually (a binary from the assemble), which stores the string literal in readonly region of the executable binary.

// IN char name[] i added 20 cause name only has enough space to store "Johnny\0". Appending " Doe" would write beyond the bounds of the array, leading to undefined behavior.like buffer overflow.


// realloc allows us to expand the memory that has been previously malloc'd
//Remember the realloc works on heap memory, thus the memory previously should be allocated using malloc, not on the stack.

//Last Step
//Instead of thinking about one byte at a time, think of moving chunks of memory of any size(as long as chunks are continous). Less operation means better performance. 