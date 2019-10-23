/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Seek the parenthesis
*/

#include "my.h"
#include <stdlib.h>

char *replace(char *str, char *seg, int begin, int seg_len)
{
    for (int i = 0; i < seg_len; i++) {
        if (i < my_strlen(seg) && i != 0 && i != seg_len - 1) {
            str[begin + i] = seg[i];
        } else {
            str[begin + i] = '.';
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
        if ((ops[op_len] < '9' && ops[op_len] > '0') || ops[op_len] == '.') {
            nb_or_point == 1;
        } else
            nb_or_point == 0;
    }
    return op_len;
}

char *compute(char *operation);

char *operator_seeker(char *seg, int seg_lenght, int operator)
{
    char operator_list[] = "%/*+-";
    char *operation = malloc(100);
    int begin = 1;
    int op_lenght = 0;

    for (int i = 1; i < seg_lenght - 1; i++) {
        if (seg[i] == operator_list[operator]) {
            op_lenght = operation_lenght(&seg[begin], operator_list[operator]);
            //seg = malloc(op_lenght);
            operation = my_strncpy(operation, &seg[begin], op_lenght);
            operation = compute(operation);
            seg = replace(seg, operation, begin, op_lenght);
            //seg = NULL;
        } else if (seg[i] > '9' || seg[i] < '0') {
            begin = i + 1;
        }
    }
    if (operator < 5)
        operator_seeker(seg, seg_lenght, operator + 1);
    free(operation);
    return seg;
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
            //seg = malloc(seg_lenght);
            seg = my_strncpy(seg, &str[open_par], seg_lenght);
            seg = operator_seeker(seg, seg_lenght, 0);
            str = replace(str, seg, open_par, seg_lenght);
            //seg = NULL;
            i = -1;
        }
    }
    free(seg);
    return 0;
}
