/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Seek the operator
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void combine_operators(char *expr);

char *make_the_operation(char *seg, int prio, int operator, int begin);

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

static int is_operator(char *seg, int i, char **op_by_priority, int prio)
{
    if (seg[i] == op_by_priority[prio][0])
        return 1;
    if (seg[i] == op_by_priority[prio][1])
        return 2;
    if (prio == 0 && seg[i] == op_by_priority[prio][2])
        return 3;
    return 0;
}

char *operator_seeker(char *seg, int seg_lenght, int prio)
{
    char *op_by_priority[] = {"%/*", "+-"};
    int begin = 1;
    int sig = detect_sign(seg);
    int operator = 0;

    for (int i = 1; i < seg_lenght - 1; i++) {
        operator = is_operator(seg, i, op_by_priority, prio);
        if (operator > 0 && sig != i) {
            seg = make_the_operation(seg, prio, operator - 1, begin);
            i = 0;
            begin = 1;
            sig = detect_sign(seg);
            combine_operators(seg);
        } else if ((seg[i] > '9' || seg[i] < '0') && seg[i] != '.' && sig != i)
            begin = i + 1;
        operator = 0;
    }
    if (prio < 1)
        seg = operator_seeker(seg, seg_lenght, prio + 1);
    return seg;
}
