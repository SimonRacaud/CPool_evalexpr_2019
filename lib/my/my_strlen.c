/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Task03
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        //printf("TRO MARAN          =       %c\n", str[len]);
        len++;
        //str++;
    }
    //printf("TRO MARAN LEN          =       [%d]\n", len);
    if (len == 4) {
        printf("TRO MARAN   33       =       [%c]\n", str[len - 2]);
        printf("TRO MARAN   1       =       [%c]\n", str[len - 1]);
        printf("TRO MARAN   2       =       [%d]\n", str[len]);
    }
    return (len);
}
