/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Seek the parenthesis
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *replace_seg(char *str, char *seg, int open_par, int seg_len)
{
    for (int i = 0; i < seg_len; i++) {
        if (i < my_strlen(seg) && i != 0 && i != seg_len - 1)
            str[open_par + i] = seg[i];
        else
            str[open_par + i] = '.';
    }
    return str;
}

char *operator_seeker(char *seg, int seg_lenght, int operator);

char *add_parenthesis(char *str)
{
    char *temp = malloc(sizeof(char) * my_strlen(str) + 3);

    temp[0] = '(';
    temp[my_strlen(str) + 1] = ')';
    temp[my_strlen(str) + 2] = '\0';
    my_strncpy(&temp[1], str, my_strlen(str));
    return temp;
}

char *parenthesis_seeker(char *str)
{
    int open_par = 0;
    char *seg;
    int seg_lenght = 0;

    printf("FIRST STR : %s\n", str);
    str = add_parenthesis(str);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '(') {
            open_par = i;
        } else if (str[i] == ')') {
            seg_lenght = i + 1 - open_par;
            seg = malloc(seg_lenght + 1);
            seg[seg_lenght] = '\0';
            seg = my_strncpy(seg, &str[open_par], seg_lenght);
            printf("SEG AVANT = %s &&& SEG LEN = %d\n", seg, seg_lenght);
            seg = operator_seeker(seg, seg_lenght, 0);
            printf("SEG APRES = %s\n", seg);
            str = replace_seg(str, seg, open_par, seg_lenght);
            seg = NULL;
            i = -1;
            printf("STR : %s\n", str);
        }
    }
    free(seg);
    return str;
}
