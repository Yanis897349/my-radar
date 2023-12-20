/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** main loop of my_printf
*/

#include <stdarg.h>
#include <stddef.h>
#include "my_printf.h"
#include "io/my_io.h"

int format_handling(char const *format, int indice, void ***arg_tab
    , conversion_specifier_t *conv_spec)
{
    int fmt_tab_size = sizeof(FORMAT_TAB) / sizeof(FORMAT_TAB[0]);
    int size_read = 0;

    indice = get_specifier(conv_spec, format, indice, arg_tab);
    for (int i = 0; i < fmt_tab_size; i++) {
        if (FORMAT_TAB[i].format_char == conv_spec->conversion_specifier) {
            size_read += FORMAT_TAB[i].pf(conv_spec, *arg_tab);
        }
    }
    return size_read;
}

static int init_conversion_spec(char const *format, int index, void ***arg_tab
    , int i_arg)
{
    int size_print = 0;
    conversion_specifier_t conv_spec;

    conv_spec.conversion_specifier = '\0';
    conv_spec.field_width = 0;
    conv_spec.flag_characters = NULL;
    conv_spec.indice_argument = i_arg;
    conv_spec.length_modifier = 0;
    conv_spec.precision = 0;
    size_print = format_handling(format, index, arg_tab, &conv_spec);
    return size_print;
}

static int handle_percent(char const *format, int i_fmt)
{
    if (format[i_fmt] == '%' && format[i_fmt + 1] == '%') {
        return 1;
    }
    return 0;
}

int call_format_handling(char const *format, void **argtab)
{
    int size_read = 0;
    int i_a = 0;

    for (int i_fmt = 0; format[i_fmt] != '\0'; i_fmt++) {
        if (is_real_flag(format, i_fmt)) {
            size_read += init_conversion_spec(format, i_fmt + 1, &argtab, i_a);
            i_fmt += jump_flags(format, i_fmt + 1);
            i_a++;
            continue;
        }
        if (format[i_fmt] == '%') {
            my_putchar('%');
            i_fmt += 1;
            continue;
        }
        i_fmt += handle_percent(format, i_fmt);
        my_putchar(format[i_fmt]);
        size_read += 1;
    }
    return size_read;
}

int my_printf(char const *format, ...)
{
    va_list ap;
    void **arg_tab = NULL;
    int size_read = 0;

    va_start(ap, format);
    arg_tab = get_arg_tab(ap, format);
    if (arg_tab == NULL) {
        return 84;
    }
    size_read = call_format_handling(format, arg_tab);
    return size_read;
}
