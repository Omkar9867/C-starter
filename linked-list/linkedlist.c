#include "linkedlist.h"
#include <stdlib.h> // malloc, free and NULL

// malloc a new linked list and then return a pointer to that linked list
LinkedList_t* CreateLinkedList(){
    LinkedList_t* newList = (LinkedList_t*)malloc(sizeof(LinkedList_t));
    newList->head = NULL;
    return newList;
};

// malloc five new linked list and then return a pointer to that linked list
LinkedList_t* CreateLinkedListOfFiveItems(){

};

// Print the linked lists
void PrintLinkedList(LinkedList_t* list){
    
};

// free the linked list as it is malloc and stored in the heap as previous chapter discussed
void FreeLinkedList(LinkedList_t* list){

};

// Append a new node to the end of the linked list
void AppendToLinkedList(LinkedList_t* list, int data){
    //Case 1
    if(list->head == NULL){
        Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
        newNode->data = data;
        newNode->next = NULL;
        // set the head to newly allocated node
        list->head = newNode;
    }else{
        Node_t* iter = list->head; //iterator
        //Case 2 while the head is not null update the iterator till it found null and then appenc
        while(iter->next != NULL){
            iter = iter->next;
        };
        Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
        newNode->data = data;
        newNode->next = NULL;

        //append the new node to the end of the linked list
        iter->next = newNode;
    }
};