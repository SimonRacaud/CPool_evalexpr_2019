/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Seek the parenthesis
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *compute(char *operation);

char *replace_operation(char *seg, char *operation, int begin, int op_len)
{
    for (int i = 0; i < op_len; i++) {
        seg[begin + i] = operation[i];
    }
    return seg;
}

char *replace_seg(char *str, char *seg, int open_par, int seg_len)
{
    for (int i = 0; i < seg_len; i++) {
        if (i < my_strlen(seg) && i != 0 && i != seg_len - 1) {
            str[open_par + i] = seg[i];
        } else {
            str[open_par + i] = '.';
        }
    }
    return str;
}

int operation_lenght(char *ops, char operator)
{
    int op_len = 0;
    int op = 0;
    int nb_or_point = 1;

    while (nb_or_point == 1 || op == 0) {
        if (ops[op_len] == operator)
            op++;
        op_len++;
        if ((ops[op_len] <= '9' && ops[op_len] >= '0') || ops[op_len] == '.') {
            nb_or_point = 1;
        } else
            nb_or_point = 0;
    }
    return op_len;
}

char *operator_seeker(char *seg, int seg_lenght, int operator)
{
    char operator_list[] = "%/*+-";
    char *operation;
    int begin = 1;
    int op_lenght = 0;
    int var = 0;

    if (seg[1] == '+')
        var = 1;
    if (seg[1] == '-')
        var = 1;
    for (int i = 1; i < seg_lenght - 1; i++) {
        if (seg[i] == operator_list[operator] && var != 1) {
            op_lenght = operation_lenght(&seg[begin], operator_list[operator]);
            operation = malloc(op_lenght);
            operation = my_strncpy(operation, &seg[begin], op_lenght);
            operation = compute(operation);
            seg = replace_operation(seg, operation, begin, op_lenght);
            free(operation);
            operation = NULL;
            i = 0;
            begin = 0;
        } else if ((seg[i] > '9' || seg[i] < '0') && seg[i] != '.' && var != 1)
            begin = i + 1;
        var = 0;
    }
    if (operator < 5)
        seg = operator_seeker(seg, seg_lenght, operator + 1);
    return seg;
}

char *add_parenthesis(char *str)
{
    char *temp = malloc(sizeof(char) * my_strlen(str) + 2);

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

    str = add_parenthesis(str);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '(') {
            open_par = i;
        } else if (str[i] == ')') {
            seg_lenght = i + 1 - open_par;
            seg = malloc(seg_lenght);
            seg = my_strncpy(seg, &str[open_par], seg_lenght);
            seg = operator_seeker(seg, seg_lenght, 0);
            str = replace_seg(str, seg, open_par, seg_lenght);
            seg = NULL;
            i = -1;
        }
    }
    free(seg);
    return str;
}
