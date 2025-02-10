// Individual node in a chain
typedef struct Node{
    int data;
    struct Node* next;
}Node_t;

// Linkedlist data structure which always holds the first node in our chain
// This is the only thing we need to keep track of to keep track of the entire chain
typedef struct LinkedList{
    Node_t* head;
}LinkedList_t;


// malloc a new linked list and then return a pointer to that linked list
LinkedList_t* CreateLinkedList();

// Print the linked lists
void PrintLinkedList(LinkedList_t* list);

// free the linked list as it is malloc and stored in the heap as previous chapter discussed
void FreeLinkedList(LinkedList_t* list);