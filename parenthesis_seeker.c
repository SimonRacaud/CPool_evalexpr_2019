/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Seek the parenthesis
*/

#include "my.h"
#include <stdlib.h>

char *replace(char *str, char *seg, int open_par, int seg_lenght)
{
    //my_put_nbr(open_par);
    //my_putstr("\n");
    //my_put_nbr(seg_lenght);
    //my_putstr("\n");
    for (int i = 0; i < seg_lenght; i++) {
        if (i < my_strlen(seg) && i != 0 && i != seg_lenght - 1) {
            str[open_par + i] = seg[i];
        } else {
            str[open_par + i] = '.';
        }
    }
    my_putstr(str);
    my_putstr("\n");
    return str;
}

int parenthesis_seeker(char *str)
{
    int open_par = 0;
    char *seg = malloc(100);
    int seg_lenght = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '(') {
            open_par = i;
        } else if (str[i] == ')') {
            seg_lenght = i + 1 - open_par;
            //my_put_nbr(seg_lenght);
            seg = my_strncpy(seg, &str[open_par], seg_lenght);
            //my_compute(seg);
            //my_putstr(seg);
            //my_putstr("\n");
            my_putstr(str);
            my_putstr("\n");
            str = replace(str, seg, open_par, seg_lenght);
            i = -1;
        }
    }
    return 111;
}
