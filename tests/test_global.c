/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/

#include <stdio.h>
#include  <criterion/criterion.h>

int eval_expr(char const *str);
/*
Test(evalexpr, evalexp1)
{
    char str[23] = "((2*3+5)*(10*(20-2)/5))";
    int ret = eval_expr(str);

    printf("#1: %d \n", ret);
    cr_assert(ret == 330);
}

Test(evalexpr, evalexp2)
{
    char str[23] = "((3+-2)*5)";
    int ret = eval_expr(str);

    printf("#2: %d \n", ret);
    cr_assert(ret == 5);
}

Test(evalexpr, evalexp3)
{
    char str[23] = "+++---+-+2";
    int ret = eval_expr(str);

    printf("#3: %d \n", ret);
    cr_assert(ret == 2);
}

Test(evalexpr, evalexp4)
{
    char str[23] = "2%2";
    int ret = eval_expr(str);

    printf("#4: %d \n", ret);
    cr_assert(ret == 0);
}

Test(evalexpr, evalexp5)
{
    char str[23] = "-2";
    int ret = eval_expr(str);

    printf("#5: %d \n", ret);
    cr_assert(ret == -2);
}

Test(evalexpr, evalexp6)
{
    char str[23] = "-2+2";
    int ret = eval_expr(str);

    printf("#6: %d \n", ret);
    cr_assert(ret == 0);
}

Test(evalexpr, evalexp7)
{
    char str[23] = "0%0";
    int ret = eval_expr(str);

    printf("#7: %d \n", ret);
    cr_assert(ret == 0);
}

Test(evalexpr, evalexp8)
{
    char str[23] = "0/0";
    int ret = eval_expr(str);

    printf("#8: %d \n", ret);
    cr_assert(ret == 0);
}

Test(evalexpr, evalexp9)
{
    char str[23] = "(-2)";
    int ret = eval_expr(str);

    printf("#9: %d \n", ret);
    cr_assert(ret == -2);
}
*/
Test(evalexpr, evalexp10)
{
    char str[23] = "(2*(1-2))";
    int ret = eval_expr(str);

    printf("#10: %d \n", ret);
    cr_assert(ret == -2);
}
