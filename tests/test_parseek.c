/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/

#include <stdio.h>
#include  <criterion/criterion.h>

char *parenthesis_seeker(char *str);

Test(parseek, parentesis_seeker)
{
    char str[23] = "((2*3+5)*(10*(20-2)/5))";
    char *res = parenthesis_seeker(str);

    cr_assert_str_eq(res, "..396....................");
}

Test(parseek, parentesis_seeker2)
{
    char str[23] = "((3+2)*5)";
    char *res = parenthesis_seeker(str);

    cr_assert_str_eq(res, "..25.......");
}

Test(parseek, parentesis_seeker3)
{
    char str[23] = "(2*3+5)*(10*(20-2)/5)";
    char *res = parenthesis_seeker(str);

    cr_assert_str_eq(res, ".396...................");
}

Test(parseek, parentesis_seeker4)
{
    char str[23] = "(3+2)*5";
    char *res = parenthesis_seeker(str);

    cr_assert_str_eq(res, ".25......");
}
