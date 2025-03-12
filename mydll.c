#include "mydll.h"

void MyDLLInit(DLL* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->max_size = MAX_SIZE;

    for (size_t i = 0; i < MAX_SIZE; ++i) {
        // Set next pointer
        if (i == MAX_SIZE - 1) {
            list->nodes[i].next = NULL;
        } else {
            list->nodes[i].next = &list->nodes[i + 1];
        }

        // Set prev pointer
        if (i == 0) {
            list->nodes[i].prev = NULL;
        } else {
            list->nodes[i].prev = &list->nodes[i - 1];
        }
    }
}



int MyDLLInsert(DLL* list, uint16_t key, unsigned char* data) {
    if (list->size >= list->max_size) {
        return -1; // List is full
    }

    DLLNode* newNode = &list->nodes[list->size]; // Use next available static node
    newNode->key = key;
    memcpy(newNode->data, data, MAX_DATA_SIZE);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (!list->head) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }

    list->size++;
    return 0;
}



int MyDLLRemove(DLL* list, uint16_t key) {
    DLLNode* current = list->head;

    while (current) {
        if (current->key == key) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }

            list->size--;
            return 0;
        }
        current = current->next;
    }

    return -1; // Key not found
}
