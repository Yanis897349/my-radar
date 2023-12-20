/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flag_u
*/

#include "my_printf.h"
#include "io/my_io.h"

int unsigned_conversion(conversion_specifier_t *conv_spec, void **arg_tab)
{
    int *unsigned_to_print = (int *) &arg_tab[conv_spec->indice_argument];
    int size_print = apply_nb_precision(conv_spec, *unsigned_to_print);

    return my_put_nbr_unsigned((unsigned int) *unsigned_to_print) + size_print;
}
