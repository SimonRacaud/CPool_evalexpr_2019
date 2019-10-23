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

int eval_expr(char const *str)
{
    char *expr = my_strdup(str);
    char *expr_res;
    int ret = 0;
    int result;

    combine_operators(expr);
    expr_res = parenthesis_seeker(expr);
    if (ret != 0)
        my_putstr("ERROR : parenthesis_seeker() \n");
    result = my_getnbr(expr_res);
    free(expr);
    free(expr_res);
    return (result);
}
