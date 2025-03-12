#ifndef MYDLL_H
#define MYDLL_H

#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE 100  // Maximum number of elements
#define MAX_DATA_SIZE 256 // Maximum size of each element's data array


typedef struct DLLNode {
    uint16_t key;
    unsigned char data[MAX_DATA_SIZE];
    struct DLLNode* next;
    struct DLLNode* prev;
} DLLNode;

typedef struct {
    DLLNode nodes[MAX_SIZE];
    DLLNode* head;
    DLLNode* tail;
    size_t size;
    size_t max_size;
} DLL;

void MyDLLInit(DLL* list);

int MyDLLInsert(DLL* list, uint16_t key, unsigned char* data);

int MyDLLRemove(DLL* list, uint16_t key);

DLLNode* MyDLLFind(DLL* list, uint16_t key);

DLLNode* MyDLLFindNext(DLL* list, uint16_t key);

DLLNode* MyDLLFindPrevious(DLL* list, uint16_t key);

#endif