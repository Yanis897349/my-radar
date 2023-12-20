/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** get_precision
*/
#include "my_printf.h"
#include "math/my_math.h"
#include "io/my_io.h"
#include "strings/my_strings.h"

int apply_str_precision(conversion_specifier_t *conv_spec, char *str)
{
    int size_str = my_strlen(str);

    if (conv_spec->precision == -1) {
        return size_str;
    }
    if (size_str < conv_spec->precision) {
        return size_str;
    }
    return conv_spec->precision;
}

int apply_nb_precision(conversion_specifier_t *conv_spec, long long nb)
{
    int size = my_nbrlen(nb);
    int tmp = size;

    while (tmp < conv_spec->precision) {
        my_putchar('0');
        tmp++;
    }
    return size - tmp;
}

int get_precision(conversion_specifier_t *conv_spec, char const *format
    , int i_fmt)
{
    if (format[i_fmt] != '.') {
        conv_spec->precision = -1;
        return 0;
    }
    i_fmt += 1;
    conv_spec->precision = my_getnbr(&format[i_fmt]);
    return my_nbrlen(conv_spec->precision) + 1;
}
