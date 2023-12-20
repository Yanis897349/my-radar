/*
** EPITECH PROJECT, 2023
** my_put_octal.c
** File description:
** Put octal
*/

#include "strings/my_strings.h"
#include "io/my_io.h"
#include "math/my_math.h"

int my_put_octal(unsigned int nb, char *str)
{
    char *octal_base = "01234567";

    my_putnbr_base(nb, octal_base, str);
    my_putstr(str);
    return my_strlen(str);
}
