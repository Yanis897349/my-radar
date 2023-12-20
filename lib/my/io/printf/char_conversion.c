/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flag_c
*/

#include "my_printf.h"
#include "io/my_io.h"

int char_conversion(conversion_specifier_t *conv_spec, void **arg_tab)
{
    unsigned char *char_to_print;

    char_to_print = (unsigned char *) &arg_tab[conv_spec->indice_argument];
    my_putchar(*char_to_print);
    return 1;
}
