#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h> // malloc, free and NULL

// malloc a new linked list and then return a pointer to that linked list
LinkedList_t* CreateLinkedList(){
    LinkedList_t* newList = (LinkedList_t*)malloc(sizeof(LinkedList_t));
    newList->head = NULL;
    return newList;
};

// malloc five new linked list and then return a pointer to that linked list
LinkedList_t* CreateLinkedListOfFiveItems(){
    //Create List
    LinkedList_t* newList = (LinkedList_t*)malloc(sizeof(LinkedList_t));

    Node_t* newNode1 = (Node_t*)malloc(sizeof(Node_t));
    newNode1->data = 1;
    Node_t* newNode2 = (Node_t*)malloc(sizeof(Node_t));
    newNode2->data = 2;
    Node_t* newNode3 = (Node_t*)malloc(sizeof(Node_t));
    newNode3->data = 3;
    Node_t* newNode4 = (Node_t*)malloc(sizeof(Node_t));
    newNode4->data = 4;
    Node_t* newNode5 = (Node_t*)malloc(sizeof(Node_t));
    newNode5->data = 5;

    //Link the nodes
    newList->head = newNode1;
    newNode1->next = newNode2;
    newNode2->next = newNode3;
    newNode3->next = newNode4;
    newNode4->next = newNode5;
    newNode5->next = NULL;
};

//Alternate method to do this is:
// LinkedList_t* CreateLinkedListOfFiveItems(){
//     //Create List
//     LinkedList_t* newList = CreateLinkedList();

//     //Create Nodes and Linke nodes
//     AppendToLinkedList(newList, 1);
//     AppendToLinkedList(newList, 2);
//     AppendToLinkedList(newList, 3);
//     AppendToLinkedList(newList, 4);
//     AppendToLinkedList(newList, 5);
// };

// Print the linked lists
void PrintLinkedList(LinkedList_t* list){
    Node_t* iter = list->head;
    while(iter != NULL){
        printf("data: %d\n", iter->data);
        iter = iter->next;
    }
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