/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flag_x_X
*/

#include "my_printf.h"
#include "io/my_io.h"
#include "ctype/my_ctype.h"
#include "flag_characters/flag_characters.h"

int hexadecimal_conversion(conversion_specifier_t *conv_spec, void **arg_tab)
{
    int *hex_to_print = (int *) &arg_tab[conv_spec->indice_argument];
    int size_precision = apply_nb_precision(conv_spec, *hex_to_print);
    int size_print = 0;

    size_print = put_padding_hex(conv_spec, (long long)*hex_to_print
    , &my_put_hexadecimal, size_precision);
    return size_precision + size_print;
}
