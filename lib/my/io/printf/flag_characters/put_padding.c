/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** put_padding
*/

#include "io/printf/my_printf.h"
#include "flag_characters.h"
#include "ctype/my_ctype.h"
#include "math/my_math.h"
#include "strings/my_strings.h"
#include "stdint.h"

int put_padding_integer(conversion_specifier_t *conv_spec, int integer,
    int (*put_func)(), int size_precision)
{
    int size_print = 0;

    if (is_minus_flag(conv_spec)) {
        size_print = put_func(integer);
        size_print += put_padding(conv_spec, size_print);
    } else if (is_zero_flag(conv_spec)) {
        size_print = put_padding_zero(conv_spec
        , my_nbrlen(integer) + size_precision);
        size_print += put_func(integer);
    } else {
        size_print = put_padding(conv_spec
        , my_nbrlen(integer) + size_precision);
        size_print += put_func(integer);
    }
    return size_print;
}

int put_padding_hex(conversion_specifier_t *conv_spec, long long integer
    , int (*put_func)(), int size_precision)
{
    int size_print = 0;
    int is_upper = my_isupper((char) conv_spec->conversion_specifier);

    if (is_minus_flag(conv_spec)) {
        size_print = put_func(integer, is_upper);
        size_print += put_padding(conv_spec, size_print);
    } else if (is_zero_flag(conv_spec)) {
        size_print = put_padding_zero(conv_spec
        , my_nbrlen(integer) + size_precision);
        size_print += put_func(integer, is_upper);
    } else {
        size_print = put_padding(conv_spec
        , my_nbrlen(integer) + size_precision);
        size_print += put_func(integer, is_upper);
    }
    return size_print;
}
