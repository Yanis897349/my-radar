/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flag_o
*/

#include "my_printf.h"
#include "io/my_io.h"
#include "flag_characters/flag_characters.h"

int octal_conversion(conversion_specifier_t *conv_spec, void **arg_tab)
{
    int *octal_to_print = (int *) &arg_tab[conv_spec->indice_argument];
    int size_precision = apply_nb_precision(conv_spec, *octal_to_print);
    int size_print = 0;

    size_print = put_padding_integer(conv_spec, *octal_to_print
    , &my_put_octal, size_precision);
    return size_precision + size_print;
}
