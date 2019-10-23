/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** convert a number in string
*/

#include <stdlib.h>
#include "my.h"

static void create_res_str(int size, char **nb_str, int is_neg, int *j)
{
    if (is_neg) {
        *nb_str = malloc(sizeof(char) * (size + 2));
        (*nb_str)[0] = '-';
        *j = 1;
    } else
        *nb_str = malloc(sizeof(char) * (size + 1));
    (*nb_str)[size] = '\0';
}

char *my_putnbr_str(int nb)
{
    int i = 0;
    int j = 0;
    char *nb_str;
    char c;
    int is_neg = 0;

    if (nb < 0) {
        nb *= (-1);
        is_neg = 1;
    }
    while (nb / my_compute_power_rec(10, i) >= 10)
        i++;
    create_res_str(i + 1, &nb_str, is_neg, &j);
    while (i >= 0) {
        c = ((nb / my_compute_power_rec(10, i)) % 10) + '0';
        nb_str[j++] = c;
        i--;
    }
    return (nb_str);
}
