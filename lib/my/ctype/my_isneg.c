/*
** EPITECH PROJECT, 2023
** my_isneg.c
** File description:
** Displays if n is negative
*/

#include "io/my_io.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
