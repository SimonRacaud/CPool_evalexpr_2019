/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Seek the operator
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *compute(char *operation);

char *replace_operation(char *seg, char *operation, int begin, int op_len)
{
    for (int i = 0; i < op_len; i++)
        seg[begin + i] = operation[i];
    return seg;
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
        if ((ops[op_len] <= '9' && ops[op_len] >= '0') || ops[op_len] == '.')
            nb_or_point = 1;
        else
            nb_or_point = 0;
    }
    return op_len;
}

char *make_the_operation(char *seg, int operator, int begin)
{
    int op_lenght = 0;
    char operator_list[] = "%/*+-";
    char *operation;

    op_lenght = operation_lenght(&seg[begin], operator_list[operator]);
    operation = malloc(op_lenght);
    operation = my_strncpy(operation, &seg[begin], op_lenght);
    operation = compute(operation);
    seg = replace_operation(seg, operation, begin, op_lenght);
    free(operation);
    operation = NULL;
    return seg;
}

int detect_sign(char *seg)
{
    int sign = 0;

    if (seg[1] == '+')
        sign = 1;
    if (seg[1] == '-')
        sign = 1;
    return sign;
}

char *operator_seeker(char *seg, int seg_lenght, int operator)
{
    char operator_list[] = "%/*+-";
    int begin = 1;
    int sig = detect_sign(seg);

    for (int i = 1; i < seg_lenght - 1; i++) {
        if (seg[i] == operator_list[operator] && sig != 1) {
            seg = make_the_operation(seg, operator, begin);
            i = 0;
            begin = 0;
        } else if ((seg[i] > '9' || seg[i] < '0') && seg[i] != '.' && sig != 1)
            begin = i + 1;
        sig = 0;
    }
    if (operator < 5)
        seg = operator_seeker(seg, seg_lenght, operator + 1);
    return seg;
}