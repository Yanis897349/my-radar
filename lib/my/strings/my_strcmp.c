/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** Compare two strings
*/

#include <stddef.h>
#include <sys/types.h>

int my_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return (u_char)s1[i] - (u_char)s2[i];
}
