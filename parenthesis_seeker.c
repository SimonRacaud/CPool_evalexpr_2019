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

char *replace(char *str, char *seg, int begin, int seg_len)
{
    for (int i = 0; i < seg_len; i++) {
        if (i < my_strlen(seg)) {
            str[begin + i] = seg[i];
        } else {
            str[begin + i] = '.';
        }
    }
    return str;
}

char *replace2(char *str, char *seg, int begin, int seg_len)
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

    for (int i = 1; i < seg_lenght - 1; i++) {
        if (seg[i] == operator_list[operator]) {
            op_lenght = operation_lenght(&seg[begin], operator_list[operator]);
            operation = malloc(op_lenght);
            operation = my_strncpy(operation, &seg[begin], op_lenght);
            operation = compute(operation);
            seg = replace(seg, operation, begin, op_lenght);
            free(operation);
            operation = NULL;
            i = 0;
            begin = 0;
        } else if ((seg[i] > '9' || seg[i] < '0') && seg[i] != '.')
            begin = i + 1;
    }
    if (operator < 5)
        seg = operator_seeker(seg, seg_lenght, operator + 1);
    return seg;
}

void add_parenthesis(char *str)
{
    char *temp = malloc(sizeof(char) * my_strlen(str) + 2);

    temp[0] = '(';
    temp[my_strlen(str) + 1] = ')';
    temp[my_strlen(str) + 2] = '\0';
    my_strncpy(&temp[1], str, my_strlen(str));
    printf("STR BEFORE : %s\n", str);
    printf("TEMP BEFORE : %s\n", temp);
    str = temp;
    printf("TEMP AFTER : %s\n", temp);
    printf("STR AFTER : %s\n", str);
    //free(temp);
    printf("STR : %s\n", str);
}

int parenthesis_seeker(char *str)
{
    //printf("STR BEFORE : %s\n", str);
    int open_par = 0;
    char *seg;
    int seg_lenght = 0;

    add_parenthesis(str);
    //printf("STR MIDDLE : %s\n", str);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '(') {
            open_par = i;
        } else if (str[i] == ')') {
            seg_lenght = i + 1 - open_par;
            seg = malloc(seg_lenght);
            seg = my_strncpy(seg, &str[open_par], seg_lenght);
            seg = operator_seeker(seg, seg_lenght, 0);
            str = replace2(str, seg, open_par, seg_lenght);
            seg = NULL;
            i = -1;
        }
    }
    free(seg);
    //printf("STR AFTER : %s\n", str);
    return 1;
}
