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

int operation_lenght(char *ops, char operator)
{
    int op_len = 0;
    int op = 0;
    int nb = 1;
    int point = 1;
    int nb2 = 0;
    int sign = detect_sign(ops);

    if (sign != 0) {
        op_len = sign;
    }
    while (nb == 1 || point == 1 || op == 0) {
        if (ops[op_len] == operator) {
            op++;
            nb2 = 0;
        }
        op_len++;
        if (ops[op_len] <= '9' && ops[op_len] >= '0') {
            nb = 1;
            point = 0;
            nb2 = 1;
        } else if (ops[op_len] == '.') {
            nb = 0;
            point = 1;
        } else {
            if (nb2 == 1) {
                nb = 0;
                point = 0;
            } else {
                nb = 1;
                point = 1;
                op = 1;
            }
        }
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
    //printf("OP AVANT : %s | begin = %d\n", operation, begin);
    operation = compute(operation);
    //printf("OP APRES : %s\n", operation);
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

    for (int i = 1; i < seg_lenght - 1; i++) {
        if (seg[i] == operator_list[operator] && sig != i) {
            //printf("SEG AVANT : %s\n", seg);
            seg = make_the_operation(seg, operator, begin);
            //printf("SEG APRES : %s\n", seg);
            //printf("I = %d\n", i);
            i = 0;
            begin = 0;
            sig = detect_sign(seg);
            combine_operators(seg);
        } else if ((seg[i] > '9' || seg[i] < '0') && seg[i] != '.' && sig != i && seg[i] != '-') {
            printf("SEG = %s\n", seg);
            printf("I = %d\n", i);
            printf("SEG LEN = %d\n", my_strlen(seg));
            printf("SEG 13 = %d\n", seg[13]);
            printf("SEG I = [%c]\n", seg[i]);
            begin = i + 1;
        }
    }
    if (operator < 5)
        seg = operator_seeker(seg, seg_lenght, operator + 1);
    return seg;
}
