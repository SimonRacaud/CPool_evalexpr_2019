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

void combine_operators(char *expr);

char *replace_operation(char *seg, char *operation, int begin, int op_len)
{
    for (int i = 0; i < op_len; i++)
        seg[begin + i] = operation[i];
    return seg;
}

int detect_sign(char *seg)
{
    int sign = 0;
    int i = 0;

    while (seg[i] > '9' || seg[i] < '0') {
        if (seg[i] == '+')
            sign = i;
        if (seg[i] == '-')
            sign = i;
        i++;
    }
    return sign;
}

void determine_next_char(int *nb_point, int *nb_bef_op, char *ops, int op_len)
{
    if (ops[op_len] <= '9' && ops[op_len] >= '0') {
        nb_point[0] = 1;
        nb_point[1] = 0;
        nb_bef_op[0] = 1;
    } else if (ops[op_len] == '.') {
        nb_point[0] = 0;
        nb_point[1] = 1;
    } else {
        if (nb_bef_op[0] == 1) {
            nb_point[0] = 0;
            nb_point[1] = 0;
        } else {
            nb_point[0] = 1;
            nb_point[1] = 1;
        }
    }
}

int operation_lenght(char *ops, char operator)
{
    int op_len = 0;
    int op = 0;
    int	nb_point[2] = {1, 1};
    int nb_before_op[1] = {0};
    int sign = detect_sign(ops);

    if (sign != 0)
        op_len = sign;
    while (nb_point[0] == 1 || nb_point[1] == 1 || op == 0) {
        if (ops[op_len] == operator) {
            op++;
            nb_before_op[0] = 0;
        }
        op_len++;
        determine_next_char(nb_point, nb_before_op, ops, op_len);
    }
    return op_len;
}

char *make_the_operation(char *seg, int operator, int begin)
{
    int op_lenght = 0;
    char operator_list[] = "%/*+-";
    char *operation;

    op_lenght = operation_lenght(&seg[begin], operator_list[operator]);
    operation = malloc(op_lenght + 1);
    operation[op_lenght] = '\0';
    operation = my_strncpy(operation, &seg[begin], op_lenght);
    operation = compute(operation);
    seg = replace_operation(seg, operation, begin, op_lenght);
    free(operation);
    operation = NULL;
    return seg;
}

char *operator_seeker(char *seg, int seg_lenght, int operator)
{
    char operator_list[] = "%/*+-";
    int begin = 1;
    int sig = detect_sign(seg);
    int VAR = 0;

    for (int i = 1; i < seg_lenght - 1; i++) {
        if (seg[i] == operator_list[operator]) {
            VAR = 1;
        } else if (seg[i] == operator_list[operator + 1]) {
            VAR = 2;
        } else if (operator == 0 && seg[i] == operator_list[operator + 2]) {
            VAR = 3;
        }
        if (VAR > 0 && sig != i) {
            seg = make_the_operation(seg, operator + VAR - 1, begin);
            i = 0;
            begin = 1;
            sig = detect_sign(seg);
            combine_operators(seg);
        } else if ((seg[i] > '9' || seg[i] < '0') && seg[i] != '.' && sig != i) {
            begin = i + 1;
        }
        VAR = 0;
    }
    if (operator < 2)
        seg = operator_seeker(seg, seg_lenght, operator + 3);
    return seg;
}
