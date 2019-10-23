/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/


#include  <criterion/criterion.h>

Test(evalexpr, parentesis_seeker)
{
    char str[23] = "(2*3+5)*(10*(20-2)/5)";
    int ret = parenthesis_seeker(str);

    cr_assert_str_eq(str, "11.....*(10*(20-2)/5)");
    cr_assert(ret == 1);
}


Test(evalexpr, parentesis_seeker)
{
    char str[23] = "11.....*(10*(20-2)/5)";
    int ret = parenthesis_seeker(str);

    cr_assert_str_eq(str, "11.....*(10*18..../5)");
    cr_assert(ret == 1);
}
