/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/

#include  <criterion/criterion.h>
#include <stdio.h>

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
