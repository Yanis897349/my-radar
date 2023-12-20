/*
** EPITECH PROJECT, 2023
** my_str_is_printable.c
** File description:
** Returns if a string contains only printable characters
*/

#include "strings/my_strings.h"
#include "ctype/my_ctype.h"
#include <stddef.h>

int my_str_isprintable(char const *str)
{
    size_t len = my_strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (!my_isprint(str[i]))
            return 0;
    }
    return 1;
}
