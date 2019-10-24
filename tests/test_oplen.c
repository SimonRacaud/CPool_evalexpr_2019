/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Test for operation_lenght
*/

#include <stdio.h>
#include  <criterion/criterion.h>

int operation_lenght(char *ops, char operator);

Test(op_len, op_len1)
{
    char str[8] = "(2*(-2))";
    int ret = operation_lenght(str, '*');

    //printf("#11: %d \n", ret);
    cr_assert(ret == 6);
}

Test(op_len, op_len3)
{
    char str[8] = "(-2*(2))";
    int ret = operation_lenght(str, '*');

    //printf("#11: %d \n", ret);
    cr_assert(ret == 6);
}

/*
Test(op_len, op_len2)
{
    //char str[90] = "-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(1\
6+63-50/3))";
    char str[90] = "(((-12*20)/43)*20)";
    //char str[90] = "(-(12-98*42)*(16+63-50/3))"; // ok
    //char str[90] = "(-(3)*(4))";
    //char str[90] = "(4*(-1))";
    //char str[90] = "((-2))"; // OK
    int ret = eval_expr(str);

    printf("RESULTAT: %d \n", ret);
    //cr_assert(ret == -744629760);
    cr_assert(ret == -100);
}
*/
