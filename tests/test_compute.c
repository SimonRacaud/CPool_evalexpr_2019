/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/

#include  <criterion/criterion.h>

char *compute(char *operation);

Test(evalexpr, compute1)
{
    char str[23] = "5+6...";
    compute(str);

    cr_assert_str_eq(str, "11....");
}

Test(evalexpr, compute2)
{
    char str[23] = "5..+6";
    compute(str);

    cr_assert_str_eq(str, "11...");
}

Test(evalexpr, compute3)
{
    char str[23] = "5+6";
    compute(str);

    cr_assert_str_eq(str, "11.");
}

Test(evalexpr, compute4)
{
    char str[23] = "6-5";
    compute(str);

    cr_assert_str_eq(str, "1..");
}

Test(evalexpr, compute5)
{
    char str[23] = "6*5";
    compute(str);

    cr_assert_str_eq(str, "30.");
}

Test(evalexpr, compute6)
{
    char str[23] = "6/2";
    compute(str);

    cr_assert_str_eq(str, "3..");
}

Test(evalexpr, compute7)
{
    char str[23] = "6%2";
    compute(str);

    cr_assert_str_eq(str, "0..");
}
