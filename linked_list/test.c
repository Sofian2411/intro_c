#include <criterion/criterion.h>

#include "linked_list.h"

Test(Basics, newList)
{
    List* linked = ll_new_list();
    cr_expect_neq(linked, NULL, "Expected list to be not null");
    cr_expect_eq(linked->head, NULL, "Expected head to be null");
    cr_expect_eq(linked->size, 0, "Expected sze to be 0 but was %lu",
            linked->size);
}

Test(Basic, append_to_empty_list)
{
    List* linked = ll_new_list();
    cr_expect_neq(linked, NULL, "Expected list to be not null");
    ssize_t i = ll_append(linked, 10);
    cr_expect_eq(i, 1, "Expected return value of append to be 1");
    Node* head = linked->head;
    cr_expect_neq(head, NULL, "Expected head to be not null");
    cr_expect_eq(head->next, NULL, "Expected head->next to be null");
    cr_expect_eq(head->data, 10, "Expected head->data to be 10 but was %lu",
            head->data);
    cr_expect_eq(linked->size, 1, "Expected list->size to be 1 but was %lu",
            linked->size);
}

Test(Basic, append_to_list)
{
    List* linked = ll_new_list();
    cr_expect_neq(linked, NULL, "Expected list to be not null");
    ll_append(linked, 10);
    Node* head = linked->head;
    cr_expect_neq(head, NULL, "Expected list to be not null");
    ssize_t i = ll_append(linked, 15);
    cr_expect_eq(i, 1, "Expected return value of append to be 1");
    head = head->next;
    cr_expect_neq(head, NULL, "Expected head to be not null");
    cr_expect_eq(head->next, NULL, "Expected head->next to be null");
    cr_expect_eq(head->data, 15, "Expected head->data to be 10 but was %lu",
            head->data);
    cr_expect_eq(linked->size, 2, "Expected list->size to be 1 but was %lu",
            linked->size);
}

Test(Basics, pop_list)
{
    List* linked = ll_new_list();
    ll_append(linked, 10);
    ll_append(linked, 11);
    ll_append(linked, 12);
    Node* indice0 = linked->head;
    Node* indice1 = indice0->next;
    Node* indice2 = indice1->next;
    ssize_t r = ll_pop(linked);
    cr_expect_eq(r, 12, 
            "Expected return value to be %d", 12);
    cr_expect_eq(linked->head, indice0, 
            "Expected head to be the same");
    cr_expect_eq(linked->head->next, indice1, 
            "Expected indice1 to be the same");
    cr_expect_eq(linked->head->next->next, NULL, 
            "Expected indice2 to be the NULL");
    cr_expect_eq(linked->size, 2, 
            "Expected list->size to be %d but was %lu",
            2, linked->size);
}

Test(Basics, pop_empty_list)
{
    List* linked = ll_new_list();
    ssize_t r = ll_pop(linked);
    cr_expect_eq(r, -1, 
            "Expected return value to be %d", -1);
    cr_expect_eq(linked->head, NULL, 
            "Expected head to stay NULL");
    cr_expect_eq(linked->size, 0, 
            "Expected size to stay %d", 0);
}

Test(Basics, pop_list_multiple_times)
{
    List* linked = ll_new_list();
    ll_append(linked, 10);
    ll_append(linked, 11);
    ll_append(linked, 12);
    Node* indice0 = linked->head;
    Node* indice1 = indice0->next;
    Node* indice2 = indice1->next;
    ll_pop(linked);
    ssize_t r = ll_pop(linked);
    cr_expect_eq(r, 11, 
            "Expected return value to be %d", 11);
    cr_expect_eq(linked->head, indice0, 
            "Expected head to be the same");
    cr_expect_eq(linked->head->next, NULL, 
            "Expected indice1 to be NULL");
    cr_expect_eq(linked->size, 1, 
            "Expected list->size to be %d but was %lu",
            1, linked->size);
}
