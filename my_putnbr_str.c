/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** convert a number in string
*/

#include <stdlib.h>
#include "my.h"

char *my_putnbr_str(int nb)
{
    int i = 0;
    char *nb_str;
    char c;

    if (nb < 0)
        nb *= (-1);
    while (nb / my_compute_power_rec(10, i) >= 10)
        i++;
    if (nb < 0) {
        nb_str = malloc(sizeof(char) * (i + 2));
        nb_str[0] = '-';
    } else
        nb_str = malloc(sizeof(char) * (i + 1));
    nb_str[i] = '\0';
    while (i >= 0) {
        c = ((nb / my_compute_power_rec(10, i)) % 10) + '0';
        my_putchar(c);
        i--;
    }
    return (nb_str);
}
