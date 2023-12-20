/*
** EPITECH PROJECT, 2023
** my_libc
** File description:
** put n char of str
*/

#include <unistd.h>

int my_putnstr(char *str, int n)
{
    write(1, str, n);
    return n;
}
