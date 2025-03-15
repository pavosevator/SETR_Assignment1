/** @file mydll.h
 * @brief mydll.h the ".h" file for the C module that implements a Doubly Linked List 
 *
 * 
 * 
 * @author Enzo DOS SANTOS
 * @date 16 Mar 2025
 * @bug No known bugs.
 */

#ifndef MYDLL_H
#define MYDLL_H

#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE 100  // Maximum number of elements
#define MAX_DATA_SIZE 256 // Maximum size of each element's data array

/**
 * @brief Structure representing a node in the doubly linked list.
 */
typedef struct DLLNode {
    uint16_t key;
    unsigned char data[MAX_DATA_SIZE];
    struct DLLNode* next;
    struct DLLNode* prev;
} DLLNode;

/**
 * @brief Structure representing the doubly linked list.
 */
typedef struct {
    DLLNode nodes[MAX_SIZE];
    DLLNode* head;
    DLLNode* tail;
    size_t size;
    size_t max_size;
} DLL;

/**
 * @brief Initializes the doubly linked list.
 * @param list Pointer to the DLL structure.
 */
void MyDLLInit(DLL* list);

/**
 * @brief Adds an element to the DLL.
 * @param list Pointer to the DLL structure.
 * @param key Key of the element.
 * @param data Data of the element.
 * @return 0 on success, -1 on failure.
 */
int MyDLLInsert(DLL* list, uint16_t key, unsigned char* data);

/**
 * @brief Removes an element from the DLL by key.
 * @param list Pointer to the DLL structure.
 * @param key Key of the element to remove.
 * @return 0 on success, -1 on failure.
 */
int MyDLLRemove(DLL* list, uint16_t key);

/**
 * @brief Finds an element in the DLL by key.
 * @param list Pointer to the DLL structure.
 * @param key Key of the element to find.
 * @return Pointer to the data of the found element, or NULL if not found.
 */
DLLNode* MyDLLFind(DLL* list, uint16_t key);

/**
 * @brief Finds the next element in the DLL.
 * @param list Pointer to the DLL structure.
 * @param current_key Key to the current node.
 * @return Pointer to the data of the next element, or NULL if not found.
 */
DLLNode* MyDLLFindNext(DLL* list, uint16_t key);

/**
 * @brief Finds the previous element in the DLL.
 * @param list Pointer to the DLL structure.
 * @param current_key Key to the current node.
 * @return Pointer to the data of the previous element, or NULL if not found.
 */
DLLNode* MyDLLFindPrevious(DLL* list, uint16_t key);

#endif