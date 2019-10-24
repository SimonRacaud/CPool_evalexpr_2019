/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** File that contain the main function of the project
*/

#include <stdlib.h>
#include "my.h"

char *parenthesis_seeker(char *str);

void combine_operators(char *expr);

void move_minus(char *expr_res)
{
    int i = 0;

    while (expr_res[i] != '\0') {
        if (expr_res[i] == '-' && expr_res[i + 1] == '.') {
            expr_res[i] = '.';
            expr_res[i + 1] = '-';
        }
        i++;
    }
}

int eval_expr(char const *str)
{
    char *expr = my_strdup(str);
    char *expr_res;
    int result;

    combine_operators(expr);
    expr_res = parenthesis_seeker(expr);
    move_minus(expr_res);
    result = my_getnbr(expr_res);
    free(expr);
    free(expr_res);
    return (result);
}
