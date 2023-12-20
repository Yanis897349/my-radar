/*
** EPITECH PROJECT, 2023
** my_put_hexadecimal.c
** File description:
** Put hexadecimal
*/

#include "strings/my_strings.h"
#include "io/my_io.h"
#include "math/my_math.h"

int my_put_hexadecimal(int nb, int is_upper, char *str)
{
    char *hexa_base;

    if (is_upper) {
        hexa_base = "0123456789ABCDEF";
    } else {
        hexa_base = "0123456789abcdef";
    }
    my_putnbr_base(nb, hexa_base, str);
    my_putstr(str);
    return my_strlen(str);
}
