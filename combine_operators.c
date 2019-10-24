/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Combine a row of +/- symbols in one
*/

static void replace_symbols(char *ptr, int nb_symb, char symb)
{
    for (int i = 1; i < nb_symb; i++)
        *(ptr - i) = '.';
    *(ptr - nb_symb) = symb;
}

static void check_char(char *ptr, int *count_neg, int *count_symb, int *detect)
{
    if (*ptr == '+' || *ptr == '-' || (*ptr == '.' && *detect)) {
        *detect = 1;
        if (*ptr == '-')
            (*count_neg)++;
        (*count_symb)++;
    } else if (*count_symb != 0) {
        *detect = 0;
        if (*count_neg % 2 == 0) {
            replace_symbols(ptr, *count_symb, '+');
        } else {
            replace_symbols(ptr, *count_symb, '-');
        }
        *count_neg = 0;
        *count_symb = 0;
    }
}

void combine_operators(char *expr)
{
    int count_neg = 0;
    int count_symb = 0;
    int i = 0;
    int detected = 0;

    while (expr[i] != '\0') {
        check_char(&expr[i], &count_neg, &count_symb, &detected);
        i++;
    }
}
