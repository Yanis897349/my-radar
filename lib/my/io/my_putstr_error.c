/*
** EPITECH PROJECT, 2023
** my_putstr_error.c
** File description:
** Displays each char of a str on the STDERR
*/

#include "io/my_io.h"
#include <stddef.h>

int my_putstr_error(char const *str)
{
    for (size_t i = 0; str[i] != '\0'; i++) {
        my_putchar_error(str[i]);
    }
    return 0;
}
