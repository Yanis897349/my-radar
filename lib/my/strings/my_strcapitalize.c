/*
** EPITECH PROJECT, 2023
** my_strcapitalize.c
** File description:
** Capitalizes first letter of each word
*/

#include "ctype/my_ctype.h"
#include "strings/my_strings.h"
#include <stddef.h>

static void handle_character(char *str, int index)
{
    if (!my_isalpha(str[index]))
        return;
    if (!my_isdigit(str[index - 1]) && !my_isalpha(str[index - 1])) {
        str[index] = my_toupper(str[index]);
    } else {
        str[index] = my_tolower(str[index]);
    }
}

char *my_strcapitalize(char *str)
{
    size_t len = my_strlen(str);

    str = my_strupcase(str);
    for (size_t i = 1; i < len; i++) {
        handle_character(str, i);
    }
    return str;
}
