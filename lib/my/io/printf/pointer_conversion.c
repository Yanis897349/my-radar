/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flag_p
*/

#include "my_printf.h"
#include "io/my_io.h"
#include "ctype/my_ctype.h"
#include "flag_characters/flag_characters.h"
#include <stdint.h>

int pointer_conversion(conversion_specifier_t *conv_spec, void **arg_tab)
{
    int char_printed = 0;
    int64_t *ptr_to_print = (void *) &arg_tab[conv_spec->indice_argument];

    char_printed += alternate_form(conv_spec, arg_tab);
    char_printed += my_put_pointer(*ptr_to_print);
    return char_printed;
}
