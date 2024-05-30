#include "linked_list.h"

#include <stdlib.h>

// Return a new node with data
List* ll_new_list() {
    List* ll = malloc(sizeof(List));
    if (ll == NULL) 
        return NULL;
    
    ll->head = NULL;
    ll->size = 0;

    return ll;
}

// Add a node to the list
ssize_t ll_append(List* list, size_t data) {
    Node* n = malloc(sizeof(Node));
    if (n == NULL)
        return -1;

    n->data = data;
    n->next = NULL;

    Node* aux = list->head;
    while (aux->next != NULL)
        aux = aux->next;

    aux->next = n;

    return 1;
}

// Pop first node
ssize_t ll_pop(List* list) {
    if (list->size == 0)
        return -1;

    Node* last;
    ssize_t res;
    if (list->size == 1) {
        last = list->head->next;
        res = last->data;
        list->head->next = NULL;
    } else {
        Node* aux = list->head;
        while (aux->next->next != NULL)
            aux = aux->next;
        last = aux->next;
        res = last->data;
        aux->next = NULL;
    }
    return res;
    free(last);
}

// Get the data at index
ssize_t ll_get(List* list, int index, int *result);

// Remove the node at index
ssize_t ll_remove(List* list, int index);

// Insert data at index
ssize_t ll_insert(List* list, int index, int data);

void ll_clear();
