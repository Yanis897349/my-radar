/*
** EPITECH PROJECT, 2023
** my_str_isnum.c
** File description:
** Returns if the string only contains digit
*/

#include "strings/my_strings.h"
#include "ctype/my_ctype.h"
#include <stddef.h>

int my_str_isupper(char const *str)
{
    size_t len = my_strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (!my_isupper(str[i]) && my_isalpha(str[i]))
            return 0;
    }
    return 1;
}
