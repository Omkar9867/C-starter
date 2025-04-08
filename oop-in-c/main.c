#include <stdio.h>
#include <stdlib.h>

typedef struct array{
    //Pointer to self---:
    //Other languages we call 'this'
    struct array* self;
    //Actual member variables
    int* data;
    size_t size;

    //"Member functions" or "methods" that we implement from scratch.
    //Could embed these in another struct to change behaviour of the different functions
    void (*pfnSet)(struct array*, size_t, int);
    int (*pfnGet)(struct array*, size_t);
}array_t;

//Retrieve Data
int Get_array_t(array_t* self, size_t index){
    return self->data[index];
}

void Set_array_t(array_t* self, size_t index, int value){
    if(NULL == self){
        return;
    }
    if(index >=0 && index < self->size){
        self->data[index] = value;
    }
}

//Array Constructor
array_t* makeArray(size_t capacity){
    array_t* newArray = (array_t*)malloc(sizeof(array_t));
    //Store the pointer back to memory which holds to its actua; object like class 
    newArray->self = newArray; //similar as this.arr = arr
    newArray->data = (int*)malloc(sizeof(int)*capacity);
    newArray->size = capacity;
    // Set up function pointers
    newArray->pfnSet = Set_array_t;
    newArray->pfnGet = Get_array_t;

    return newArray;
}

//Array Destructor
void destroyArray(array_t* self){
    free(self->data);
    free(self);
    //!Note: It is important the order in which we free the , attention to free (array_t) last
}


int main(){
    array_t* arr = makeArray(10);

    //Set up the array
    for(int i = 0; i < arr->size; i++){
        arr->pfnSet(arr->self, i, i); // Can be written as '(arr, i, i)' to demonstrate how oop may have implemented these things from scratch
    }

    //Get the array
    for(int i=0; i<arr->size; i++){
        printf("%d\n", arr->pfnGet(arr->self, i));
    }

    //Destroy the array
    destroyArray(arr);

    return 0;
}