/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Make the operation
*/

#include "my.h"
#include <stdlib.h>

char *compute(char *operation);

int detect_sign(char *seg);

static void is_operator(int *nb_pt, int *nb_bef_op)
{
    if (nb_bef_op[0] == 1) {
        nb_pt[0] = 0;
        nb_pt[1] = 0;
    } else {
        nb_pt[0] = 1;
        nb_pt[1] = 1;
    }
}

static void deter_next_char(int *nb_pt, int *nb_bef_op, char *ops, int op_len)
{
    if (ops[op_len] <= '9' && ops[op_len] >= '0') {
        nb_pt[0] = 1;
        nb_pt[1] = 0;
        nb_bef_op[0] = 1;
    } else if (ops[op_len] == '.') {
        nb_pt[0] = 0;
        nb_pt[1] = 1;
    } else
        is_operator(nb_pt, nb_bef_op);
}

int operation_lenght(char *ops, char operator)
{
    int op_len = 0;
    int op = 0;
    int nb_point[2] = {1, 1};
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
        deter_next_char(nb_point, nb_before_op, ops, op_len);
    }
    return op_len;
}

static char *replace_operation(char *seg, char *op, int begin, int op_len)
{
    for (int i = 0; i < op_len; i++)
        seg[begin + i] = op[i];
    return seg;
}

char *make_the_operation(char *seg, int prio, int operator, int begin)
{
    int op_lenght = 0;
    char *op_by_priority[] = {"%/*", "+-"};
    char *operation;

    op_lenght = operation_lenght(&seg[begin], op_by_priority[prio][operator]);
    operation = malloc(op_lenght + 1);
    operation[op_lenght] = '\0';
    operation = my_strncpy(operation, &seg[begin], op_lenght);
    operation = compute(operation);
    seg = replace_operation(seg, operation, begin, op_lenght);
    free(operation);
    operation = NULL;
    return seg;
}
