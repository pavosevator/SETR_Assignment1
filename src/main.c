#include <stdio.h>
#include <string.h>
#include "mydll.h"

void PrintList(DLL* list) {
    DLLNode* current = list->head;
    printf("Doubly Linked List (size: %lu):\n", list->size);

    while (current) {
        printf("[Key: %d | Data: %s] <-> ", current->key, current->data);
        current = current->next;
    }

    printf("NULL\n\n");
}

int main() {
    DLL myList;
    MyDLLInit(&myList);

    // Insert elements
    unsigned char data1[MAX_DATA_SIZE] = "First Node";
    unsigned char data2[MAX_DATA_SIZE] = "Second Node";
    unsigned char data3[MAX_DATA_SIZE] = "Third Node";

    printf("Inserting elements...\n");
    MyDLLInsert(&myList, 1, data1);
    MyDLLInsert(&myList, 2, data2);
    MyDLLInsert(&myList, 3, data3);

    PrintList(&myList);

    // Find an element
    uint16_t searchKey = 2;
    DLLNode* found = MyDLLFind(&myList, searchKey);
    if (found) {
        printf("Found key %d: %s\n\n", searchKey, found->data);
    } else {
        printf("Key %d not found.\n\n", searchKey);
    }

    // Find next node
    DLLNode* nextNode = MyDLLFindNext(&myList, 2);
    if (nextNode) {
        printf("Next of key 2: [Key: %d | Data: %s]\n\n", nextNode->key, nextNode->data);
    } else {
        printf("Key 2 has no next node.\n\n");
    }

    // Find previous node
    DLLNode* prevNode = MyDLLFindPrevious(&myList, 2);
    if (prevNode) {
        printf("Previous of key 2: [Key: %d | Data: %s]\n\n", prevNode->key, prevNode->data);
    } else {
        printf("Key 2 has no previous node.\n\n");
    }

    // Remove an element
    printf("Removing key 2...\n");
    if (MyDLLRemove(&myList, 2) == 0) {
        if(MyDLLFind(&myList,2) == NULL){
            printf("Key 2 removed successfully and find function can not find it.\n\n");
        }
  
    } else {
        printf("Failed to remove key 2.\n\n");
    }

    // Find next node of key 1 after removing key 2
    DLLNode* nextNodeNew = MyDLLFindNext(&myList, 1);
    if (nextNodeNew) {
        printf("Next of key 1: [Key: %d | Data: %s]\n\n", nextNodeNew->key, nextNodeNew->data);
    } else {
        printf("Key 1 has no next node.\n\n");
    }

    // Find next node of key 3 after removing key 2 - should return NULL
    DLLNode* nextNodeNew1 = MyDLLFindNext(&myList, 3);
    if (nextNodeNew1) {
        printf("Next of key 3: [Key: %d | Data: %s]\n\n", nextNodeNew1->key, nextNodeNew1->data);
    } else {
        printf("Key 3 has no next node.\n\n");
    }

    PrintList(&myList);

    return 0;
}