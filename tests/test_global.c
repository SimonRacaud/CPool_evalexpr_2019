/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/

#include  <criterion/criterion.h>

int eval_expr(char const *str);

Test(evalexpr, evalexp1)
{
    char str[23] = "((2*3+5)*(10*(20-2)/5))";
    int ret = eval_expr(str);

    cr_assert(ret == 396);
}

Test(evalexpr, evalexp2)
{
    char str[23] = "((3+-2)*5)";
    int ret = eval_expr(str);

    cr_assert(ret == 5);
}

Test(evalexpr, evalexp3)
{
    char str[23] = "+++---+-+2";
    int ret = eval_expr(str);

    cr_assert(ret == 2);
}

Test(evalexpr, evalexp4)
{
    char str[23] = "2%2";
    int ret = eval_expr(str);

    cr_assert(ret == 0);
}

Test(evalexpr, evalexp5)
{
    char str[23] = "-2";
    int ret = eval_expr(str);

    cr_assert(ret == -2);
}

Test(evalexpr, evalexp6)
{
    char str[23] = "-2+2";
    int ret = eval_expr(str);

    cr_assert(ret == 0);
}


Test(evalexpr, evalexp7)
{
    char str[23] = "0%0";
    int ret = eval_expr(str);

    cr_assert(ret == 0);
}

Test(evalexpr, evalexp8)
{
    char str[23] = "0/0";
    int ret = eval_expr(str);

    cr_assert(ret == 0);
}

Test(evalexpr, evalexp9)
{
    char *str = "-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))";
    int ret = eval_expr(str);

    cr_assert(ret == -744629760);
}

Test(evalexpr, evalexp10)
{
    char str[23] = "(-(((2))))";
    int ret = eval_expr(str);

    cr_assert(ret == -2);
}

Test(evalexpr, evalexp11)
{
    char str[8] = "(2*(-2))";
    int ret = eval_expr(str);

    cr_assert(ret == -4);
}

Test(evalexpr, evalexp12)
{
    char str[8] = "1+1";
    int ret = eval_expr(str);

    cr_assert(ret == 2);
}
