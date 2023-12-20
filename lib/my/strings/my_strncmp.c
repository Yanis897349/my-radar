/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** Compare the first n char of two strings
*/

#include <stddef.h>
#include <sys/types.h>

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        if (i == n) {
            return 0;
        }
        i++;
    }
    return (u_char)s1[i] - (u_char)s2[i];
}
