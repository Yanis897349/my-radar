/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** Return the string length
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    size_t len;

    for (len = 0; str[len] != '\0'; len++);
    return len;
}
