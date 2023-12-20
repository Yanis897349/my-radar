/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** get_specifier
*/

#include "my_printf.h"

int get_specifier(conversion_specifier_t *conv_spec, char const *format
    , int i_fmt, void ***arg_tab)
{
    i_fmt += get_flag_char(conv_spec, format, i_fmt);
    i_fmt += get_field_width(conv_spec, format, i_fmt, arg_tab);
    i_fmt += get_precision(conv_spec, format, i_fmt);
    conv_spec->conversion_specifier = format[i_fmt];
    return i_fmt;
}
