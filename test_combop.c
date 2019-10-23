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
    int ret = combine_operators(str);

    cr_assert_str_eq(str, "+.(3+....5)*(10-....5)");
}
