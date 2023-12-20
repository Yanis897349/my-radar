/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** Displays each char of a str
*/

#include "io/my_io.h"
#include <stddef.h>

int my_putstr(char const *str)
{
    for (size_t i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
