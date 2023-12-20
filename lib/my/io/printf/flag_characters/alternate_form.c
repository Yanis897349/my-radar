/*
** EPITECH PROJECT, 2023
** alternate_form.c
** File description:
** Handling the # flag character
*/

#include "io/printf/my_printf.h"
#include "io/my_io.h"
#include "ctype/my_ctype.h"
#include "flag_characters.h"

int alternate_hexadecimal(conversion_specifier_t *conv_spec)
{
    int char_printed = 0;
    char conv_specifier = conv_spec->conversion_specifier;

    if (my_islower(conv_specifier)) {
        my_putstr("0x");
        char_printed += 2;
    } else {
        my_putstr("0X");
        char_printed += 2;
    }
    return char_printed;
}

int alternate_form(conversion_specifier_t *conv_spec, void **arg_tab)
{
    int char_printed = 0;
    char conv_specifier = conv_spec->conversion_specifier;

    switch (my_tolower(conv_specifier)) {
        case 'x':
        case 'p':
            char_printed += alternate_hexadecimal(conv_spec);
            break;
        default:
            alternate_form(conv_spec, arg_tab);
            break;
    }
    return char_printed;
}
