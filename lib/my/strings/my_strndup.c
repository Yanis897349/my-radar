/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** ALlocates memory and copies the string given as an argument in it.
*/

#include "strings/my_strings.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strndup(char const *src, int n)
{
    char *my_str;
    int src_len;
    int len;

    if (src == NULL)
        return NULL;
    src_len = my_strlen(src);
    len = (n < src_len) ? n : src_len;
    my_str = (char *)malloc(len + 1);
    if (my_str == NULL)
        return NULL;
    my_str[len] = '\0';
    return my_strncpy(my_str, src, len);
}
