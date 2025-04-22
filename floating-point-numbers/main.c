#include <stdio.h>
#include <math.h>

int main(){

    float number1 = 0.000001f;
    float number2 = 1.0 - .999999f; // 0.0000001

    printf("number1: %f\n", number1);
    printf("number2: %f\n", number2);

    // Comparing the two variable will result in false because the precision of float is not enough to represent the number accurately/
    if(number1 == number2){
        printf("number1 and number2 are equal\n");
    }
    // Making the precision same:
    // printf("number1: %.12f\n", number1);
    // printf("number2: %.12f\n", number2);  //Even for the double the same

    //To make them equal:
    if(fabs(number1 - number2) < 0.000001f){
        printf("number1 and number2 are equal\n");
    }


    return 0;
}

// the 'f' in the number explicitly tells the compiler to treat the number as 'float' instead of 'double'
// Since double and float both used for floating point numbers, the precision of float used 7 decimal places and double uses 15.