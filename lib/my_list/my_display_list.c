/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Display the values of each nodes of a list (script perso)
*/

#include "my.h"
#include "mylist.h"

int display_list(linked_list_t *list)
{
    linked_list_t *ptr = list;

    my_putstr("[----\n");
    while (ptr != 0) {
        my_putstr(ptr->data);
        my_putstr("\n");
        ptr = ptr->next;
    }
    my_putstr("----]\n");
    return (0);
}
