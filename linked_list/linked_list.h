#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct node {
    size_t data;
    struct node* next;
} Node ;

typedef struct List {
    size_t size;
    Node* head;
} List;

// Return a new node with data
List* ll_new_list();

// Add a node to the list
ssize_t ll_append(List* list, size_t data);

// Pop first node
ssize_t ll_pop(List* list);

// Get the data at index
ssize_t ll_get(List* list, int index, int *result);

// Remove the node at index
ssize_t ll_remove(List* list, int index);

// Insert data at index
ssize_t ll_insert(List* list, int index, int data);

void ll_clear();

#endif