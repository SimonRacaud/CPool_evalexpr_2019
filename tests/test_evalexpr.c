/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/

#include <stdio.h>
#include  <criterion/criterion.h>

int parenthesis_seeker(char *str);

Test(evalexpr, parentesis_seeker)
{
    char str[23] = "((2*3+5)*(10*(20-2)/5))";
    int ret = parenthesis_seeker(str);

    printf("Res: %s \n", str);
    cr_assert_str_eq(str, ".330...................");
    cr_assert(ret == 1);
}


Test(evalexpr, parentesis_seeker2)
{
    char str[23] = "((3+2)*5)";
    int ret = parenthesis_seeker(str);

    printf("Res: %s \n", str);
    cr_assert_str_eq(str, ".25......");
    cr_assert(ret == 1);
}

Test(evalexpr, parentesis_seeker3)
{
    char str[23] = "(2*3+5)*(10*(20-2)/5)";
    int ret = parenthesis_seeker(str);

    printf("Res: %s \n", str);
    cr_assert_str_eq(str, "330..................");
    cr_assert(ret == 1);
}


Test(evalexpr, parentesis_seeker4)
{
    char str[23] = "(3+2)*5";
    int ret = parenthesis_seeker(str);

    printf("Res: %s \n", str);
    cr_assert_str_eq(str, "25.....");
    cr_assert(ret == 1);
}
