#include <stdio.h>

int function(){
    // int i = 0;        // i is a local variable, so it will be initialized to 0 every time function is called.

    static int i = 0; // i is a static variable, so it will be initialized to 0 only once and retain its value between function calls
    // So basically, if the variable is modified once the value in the next call will the last modified value.
    i++;
    printf("%d\n", i);
    return 0;
}

int main(){

    for(int i=0; i<10; i++){
        function();
    }

    return 0;
}

// *Static
// 'static' means the duration of the variable is 'forever' or 'until' the program ends.
// The memory for that variable will be reserved within the actual binary. 
// The scope of the variable where it is declared.

// Also if i make a global variable static, it's limitation is only within the file (in this case main.c).
// The storage static is allocated in the data segment of the program, not on the stack. Meaning where the main.c is stored , the static is stored at that level.
// This is the reason it is persist forever in the function.