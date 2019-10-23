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
    int result;
    int ret;

    do {
        ret = parenthesis_seeker(expr);
    } while (ret != 0);

    free(expr);
    return 0;
}
