/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Compute a operation en return the result as a string
*/

#include "my.h"

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);

const char OPERATORS[5] = {'+', '-', '*', '/', '%'};

static int determine_operator(char const *operation)
{
    int idx = 0;

    for (int i = 0; i < 5; i++) {
        if (my_strstr(operation, OPERATORS[idx++]) != NULL) {
            return (j);
        }
    }
    return (84);
}

char *compute(char *operation)
{
    const int (*OP[5])(int, int) = {&add, &sub, &mul, &div, &mod};
    int idx_op = determine_operator(operation);
    int a;
    int b;
    int result;

    if (idx_op == 84) {
        my_putstr("ERROR: compute/determine_operator() : operator not found\n");
        return (NULL);
    }
    a = my_getnbr(operation);
    b = my_getnbr(my_strstr(operation, OPERATORS[idex_op]));
    result = OP[idx_op](a, b);
}
