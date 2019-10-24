/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Compute a operation en return the result as a string
*/

#include <stdlib.h>
#include "my.h"

int add(int a, int b);

int sub(int a, int b);

int mul(int a, int b);

int divi(int a, int b);

int mod(int a, int b);

char *my_putnbr_str(int nb);

void move_minus(char *expr_res);

static int determine_operator(char *operation)
{
    char *operators[5] = {"%", "/", "*", "+", "-"};
    int idx = 0;

    while (*operation != '\0') {
        if (*operation < '0' || *operation > '9')
            operation++;
        else
            break;
    }
    for (int i = 0; i < 5; i++) {
        if (my_strstr(operation, operators[idx]) != NULL) {
            return (idx);
        }
        idx++;
    }
    return (84);
}

static void write_result(char *operation, int result)
{
    char *result_str = my_putnbr_str(result);
    int len_result = my_strlen(result_str);
    int i = len_result;
    int POINT = 0;

    my_strncpy(operation, result_str, len_result);
    while (operation[i] != '\0') {
        operation[i++] = '.';
        POINT++;
    }
    printf("POINT : %d\n", POINT);
    free(result_str);
}

char *compute(char *operation)
{
    char *operators[5] = {"%", "/", "*", "+", "-"};
    int (*OP[5])(int, int) = {&mod, &divi, &mul, &add, &sub};
    int idx_op = determine_operator(operation);
    int a;
    int b;
    int result;

    if (idx_op == 84) {
        return (operation);
    }

    move_minus(operation);
    //printf("OP = %s\n", operation);
    //printf("TEST = %d\n", my_getnbr("0a1"));
    a = my_getnbr(operation);
    //printf("A = %d\n", a);
    b = my_getnbr(my_strstr(operation + 1, operators[idx_op]) + 1);
    //printf("B = %d\n", b);
    result = OP[idx_op](a, b);
    write_result(operation, result);
    return (operation);
}
