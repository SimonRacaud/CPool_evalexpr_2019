/*
** EPITECH PROJECT, 2019
** Lib: List
** File description:
** Base struct of the lists
*/

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
} linked_list_t;
