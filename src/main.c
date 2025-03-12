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
        printf("Key 2 removed successfully.\n\n");
    } else {
        printf("Failed to remove key 2.\n\n");
    }

    PrintList(&myList);

    return 0;
}