/*
** EPITECH PROJECT, 2023
** my_put_pointer.c
** File description:
** Put pointer
*/

#include "strings/my_strings.h"
#include "io/my_io.h"
#include "math/my_math.h"
#include <stdint.h>

int my_put_pointer(int64_t nb)
{
    char *hexa_base = "0123456789abcdef";
    char *result;

    result = my_putnbr_base_int64(nb, hexa_base);
    my_putstr(result);
    return my_strlen(result);
}
