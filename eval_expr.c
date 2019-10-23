/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** File that contain the main function of the project
*/

#include "my.h"

int parenthesis_seeker(char *str);

int eval_expr(char const *str)
{
    char *expr = my_strdup(str);
    int ret;
    int result;

    ret = parenthesis_seeker(expr);
    if (ret != 0)
        my_putstr("ERROR : parenthesis_seeker() \n");
    result = my_getnbr(expr);
    free(expr);
    return (result);
}
