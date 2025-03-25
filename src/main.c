#include <string.h>
#include "mydll.h"

void PrintList(DLL* list) {
    DLLNode* current = list->head;
    printf("Doubly Linked List (size: %zu):\n", list->size); 
    printf("NULL (head) <-> ");

    while (current) {
        printf("[Key: %d | Data: %s] <-> ", current->key, current->data);
        current = current->next;
    }

    printf("NULL (tail)\n\n");
}

int main() {
    DLL myList;
    MyDLLInit(&myList);

    // Insert elements
    unsigned char data1[MAX_DATA_SIZE] = "First Node";
    unsigned char data2[MAX_DATA_SIZE] = "Second Node";
    unsigned char data3[MAX_DATA_SIZE] = "Third Node";

    printf("Initializing a doubly linked list (maximum size = %d)...\n", MAX_SIZE);
    printf("Inserting elements...\n\n");
    MyDLLInsert(&myList, 1, data1);
    MyDLLInsert(&myList, 2, data2);
    MyDLLInsert(&myList, 3, data3);

    PrintList(&myList);

    // Find an element
    printf("Searching for node with key 2...\n");
    uint16_t searchKey = 2;
    DLLNode* found = MyDLLFind(&myList, searchKey);
    if (found) {
        printf("Found key %d: %s\n\n", searchKey, found->data);
    } else {
        printf("Key %d not found.\n\n", searchKey);
    }

    // Find next node
    printf("Searching for next element of key 2...\n");
    DLLNode* nextNode = MyDLLFindNext(&myList, 2);
    if (nextNode) {
        printf("Next node of key 2: [Key: %d | Data: %s]\n\n", nextNode->key, nextNode->data);
    } else {
        printf("Key 2 has no next node.\n\n");
    }

    // Find previous node
    printf("Search for previous element of key 2...\n");
    DLLNode* prevNode = MyDLLFindPrevious(&myList, 2);
    if (prevNode) {
        printf("Previous node of key 2: [Key: %d | Data: %s]\n\n", prevNode->key, prevNode->data);
    } else {
        printf("Key 2 has no previous node.\n\n");
    }

    // Try to go out of max size of DLL
    printf("Adding new node with key 4...\n");
    unsigned char data4[MAX_DATA_SIZE] = "Fourth node";
    if(MyDLLInsert(&myList, 4, data4) == 0){
        printf("Node successfully added.\n");
    } else {
        printf("List is full, failed to add new node.\n\n");
    }

    // Remove an element
    printf("Removing node with key 2...\n");
    if (MyDLLRemove(&myList, 2) == 0) {
        if(MyDLLFind(&myList,2) == NULL){
            printf("Node with key 2 removed successfully and find function can not find it.\n\n");
        }
  
    } else {
        printf("Failed to remove node with key 2.\n\n");
    }

    // Find next node of key 1 after removing key 2
    printf("Finding next node of key 1 after removing key 2...\n");
    DLLNode* nextNodeNew = MyDLLFindNext(&myList, 1);
    if (nextNodeNew) {
        printf("Next node of key 1: [Key: %d | Data: %s]\n\n", nextNodeNew->key, nextNodeNew->data);
    } else {
        printf("Key 1 has no next node.\n\n");
    }

    // Find next node of key 3 after removing key 2 - should return NULL
    DLLNode* nextNodeNew1 = MyDLLFindNext(&myList, 3);
    if (nextNodeNew1) {
        printf("Next node of key 3: [Key: %d | Data: %s]\n\n", nextNodeNew1->key, nextNodeNew1->data);
    } else {
        printf("Key 3 has no next node.\n\n");
    }

    PrintList(&myList);

    return 0;
}