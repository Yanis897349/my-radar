/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** Copies n char from a string into another
*/

#include "strings/my_strings.h"
#include <stddef.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int src_len = my_strlen(src);

    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    if (n > src_len)
        dest[n] = '\0';
    return dest;
}
