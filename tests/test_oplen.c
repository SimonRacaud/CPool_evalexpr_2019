/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Test for operation_lenght
*/

#include  <criterion/criterion.h>

int operation_lenght(char *ops, char operator);

Test(op_len, op_len1)
{
    char str[8] = "(2*(-2))";
    int ret = operation_lenght(str, '*');

    cr_assert(ret == 6);
}

Test(op_len, op_len2)
{
    char str[8] = "(-2*(2))";
    int ret = operation_lenght(str, '*');

    cr_assert(ret == 6);
}
