/*
** EPITECH PROJECT, 2023
** my_str_islower.c
** File description:
** Returns if the string only contains lowercase alpha char
*/

#include "strings/my_strings.h"
#include "ctype/my_ctype.h"
#include <stddef.h>

int my_str_islower(char const *str)
{
    size_t len = my_strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (!my_islower(str[i]) && my_isalpha(str[i]))
            return 0;
    }
    return 1;
}
