#include <stdio.h>
#include "linkedlist.h"

int main(){
    LinkedList_t* newList = CreateLinkedList();
    AppendToLinkedList(newList, 3);
    AppendToLinkedList(newList, 5);
    AppendToLinkedList(newList, 7);

    PrintLinkedList(newList);

    return 0;
}