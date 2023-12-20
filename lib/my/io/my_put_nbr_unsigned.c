/*
** EPITECH PROJECT, 2023
** my_put_nbr_unsigned.c
** File description:
** Put unsigned number
*/

#include "strings/my_strings.h"
#include "io/my_io.h"
#include "math/my_math.h"

int my_put_nbr_unsigned(unsigned int nb)
{
    char *dec_base = "0123456789";
    char *result = my_putnbr_base_unsigned(nb, dec_base);

    my_putstr(result);
    return my_strlen(result);
}
