/*
** EPITECH PROJECT, 2023
** my_strpcpy.c
** File description:
** Copies a string into another
*/

#include "strings/my_strings.h"
#include <stddef.h>

char *my_strcpy(char *dest, char const *src)
{
    size_t src_len = my_strlen(src);

    for (size_t i = 0; i < src_len; i++) {
        dest[i] = src[i];
    }
    dest[src_len] = '\0';
    return dest;
}
