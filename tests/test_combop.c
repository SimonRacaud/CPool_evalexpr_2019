/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/

#include  <criterion/criterion.h>

void combine_operators(char *expr);

Test(evalexpr, combineop)
{
    char str[23] = "++(3+-++-5)*(10-+--+5)";
    combine_operators(str);

    cr_assert_str_eq(str, "+.(3+....5)*(10-....5)");
}

Test(evalexpr, combineop2)
{
    char str[23] = "+-+--+-++---+1";
    combine_operators(str);

    cr_assert_str_eq(str, "-............1");
}

Test(evalexpr, combineop3)
{
    char str[23] = "++(3+++5)*(10-----5)";
    combine_operators(str);

    cr_assert_str_eq(str, "+.(3+..5)*(10-....5)");
}
