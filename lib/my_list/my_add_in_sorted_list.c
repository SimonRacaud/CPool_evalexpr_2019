/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Task10 - add element in a sorted list.
*/

#include "mylist.h"
#include <stdlib.h>

void my_sort_list(linked_list_t **begin, int (*cmp)());

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    linked_list_t *el = malloc(sizeof(*el));
    linked_list_t *ptr = *begin;

    el->data = data;
    el->next = NULL;
    while (ptr != NULL) {
        if (ptr->next == NULL) {
            ptr->next = el;
            break;
        }
        ptr = ptr->next;
    }
    my_sort_list(begin, cmp);
}
