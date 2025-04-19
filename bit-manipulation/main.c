#include <stdio.h>

int main(){

    int x = 1;
    x <<= 1; // x = x << 1
    // result: 2
    printf("x = %d\n", x);

    int y = 4;
    y >>= 1; // y = y >> 1
    // result:2
    printf("y = %d\n", y);

    // Pixel Example
    
    //Hex number
    //            R G B A
    int Pixel = 0xFFAACC11;
    // Here we know that a pixel stores 8 bits of data for each component, whereas a int stores 32 bites
    // So to make the value have 1 byte we will use datatype : 'unsigned char' and will be using shifting right by 24 bits
    unsigned char red = Pixel >> 24;
    unsigned char green = (Pixel >> 16);
    unsigned char blue = (Pixel >> 8);
    unsigned char alpha = (Pixel >> 0);
    printf("Value for red = %d\n", red);
    printf("Value for green = %d\n", green);
    printf("Value for blue = %d\n", blue);
    printf("Value for alpha = %d\n", alpha);


    return 0;
}


// Bit Shifting 
// Bit shifting operations are performed on all of the bits
// << left-shift operation
// >> right-shift operation

// << Shifting techniqally multiplies the number by 2
// >> Shifting techniqally divides the number by 2

// USECASE ------------> 
// Generally shifting is very efficient operation to perform on machine, much cheaper rather than doing multiplication / division.
// A Domain level example:
// Lets say if we have a picture which are generally of pixels.
// A pixel typically have 4 components : rgb and alpha. 
// Most common pixel format uses 1 byte (8 bits) to store value between 0-255, which represents the intesity of the component.