/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Basic mathematical functions
*/

int add(int a, int b)
{
    return (a + b);
}

int sub(int a, int b)
{
    return (a - b);
}

int mul(int a, int b)
{
    return (a * b);
}

int div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

int mod(int a, int b)
{
    if (b == 0)
        return (0);
    return (a % b);
}
