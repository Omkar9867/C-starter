#include <iostream>
using namespace std;

struct array{
    int* data;
    size_t size;

    //Constructor
    array(int capacity){
        data = new int[capacity];
        size = capacity;
    }

    //Destructor
    ~array(){
        delete[] data;
    }

    //Set data
    void Set(size_t index, int value){
        data[index] = value;
    }

    //Get data
    int Get(size_t index){
        return data[index];
    }

};

int main(){
    array* arr = new array(10);
    for(int i = 0; i < arr->size; i++){
        arr->Set(i, i);
    }
    for(int i = 0; i < arr->size; i++){
        cout << arr->Get(i) << endl;
    }
    delete arr;
    return 0;
}