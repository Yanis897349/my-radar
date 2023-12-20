/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** argument tab
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"
#include "strings/my_strings.h"

int count_arguments(char const *format)
{
    int count_arg = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (is_real_flag(format, i)) {
            count_arg++;
        }
        if (format[i] == '*' &&
            (format[i - 1] == '$' || format[i - 1] == '%')) {
            count_arg++;
        }
    }
    return count_arg;
}

char *get_type(char const *format, int tab_size)
{
    int count_arg = 0;
    char *type = malloc(sizeof(tab_size));

    for (int i = 0; format[i] != '\0'; i++) {
        if (is_real_flag(format, i)) {
            type[count_arg] = format[i  + 1];
            count_arg++;
        }
        if (format[i] == '*' &&
            (format[i - 1] == '$' || format[i - 1] == '%')) {
            type[count_arg] = '*';
            count_arg++;
        }
    }
    type[count_arg] = '\0';
    return type;
}

int fill_tab(void **arg_tab, int tab_size, va_list ap, char const *format)
{
    char *type = get_type(format, tab_size);
    int i = 0;
    double tmp = 0;

    for (; i < tab_size; i++) {
        switch (type[i]) {
        case 'f':
            tmp = va_arg(ap, double);
            arg_tab[i] = malloc(sizeof(&tmp));
            arg_tab[i] = my_memcpy(arg_tab[i], &tmp, sizeof(&tmp));
            break;
        default:
            arg_tab[i] = va_arg(ap, void *);
        }
    }
    return i;
}

void **get_arg_tab(va_list ap, char const *format)
{
    int tab_size = count_arguments(format);
    void **arg_tab = malloc(sizeof(void *) * (tab_size + 1));
    int arg_len = 0;

    if (arg_tab == NULL)
        return NULL;
    arg_len = fill_tab(arg_tab, tab_size, ap, format);
    arg_tab[arg_len] = NULL;
    va_end(ap);
    return arg_tab;
}
