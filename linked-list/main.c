#include <stdio.h>
#include "linkedlist.h"

void unitTest(){
    LinkedList_t* newList = CreateLinkedListOfFiveItems();

    // LinkedList_t* newList = CreateLinkedList();
    AppendToLinkedList(newList, 6);
    AppendToLinkedList(newList, 7);
    AppendToLinkedList(newList, 8);

    PrintLinkedList(newList);

    FreeLinkedList(newList);
};

void unitTest2(){
    LinkedList_t* newList = CreateLinkedList();

    FreeLinkedList(newList);
}

int main(){
    unitTest();
    unitTest2();
    
    return 0;
}