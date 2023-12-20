/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** Print a character to the stdout
*/

#include <unistd.h>

int my_putchar_error(char c)
{
    write(2, &c, 1);
    return 0;
}
