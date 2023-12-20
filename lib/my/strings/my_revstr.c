/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** Reverse a string
*/

#include "strings/my_strings.h"
#include <stddef.h>

char *my_revstr(char *str)
{
    char temp;
    size_t str_len = my_strlen(str);

    for (size_t i = 0; i < str_len / 2; i++) {
        temp = str[i];
        str[i] = str[str_len - 1 - i];
        str[str_len - 1 - i] = temp;
    }
    return str;
}
