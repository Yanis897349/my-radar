/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** get_flag_char
*/

#include <stddef.h>
#include "strings/my_strings.h"
#include "my_printf.h"
#include <stdlib.h>

int is_flag_char(char current_char)
{
    char const flags_chars[] = {'#', '0', ' ', '+', '-'};

    for (int i_flag = sizeof(flags_chars); i_flag > 0; i_flag--) {
        if (current_char == flags_chars[i_flag - 1]) {
            return 1;
        }
    }
    return 0;
}

int is_first_flag_char(char current_char)
{
    char const first_flags_chars[] = {'#', '0', ' ', '+', '-'};

    for (int i_flag = sizeof(first_flags_chars); i_flag > 0; i_flag--) {
        if (current_char == first_flags_chars[i_flag - 1]) {
            return 1;
        }
    }
    return 0;
}

int get_flags_size(char const *format, int i_fmt)
{
    int size = 0;

    if (!is_first_flag_char(format[i_fmt])) {
        return 0;
    }
    while (is_flag_char(format[i_fmt])) {
        i_fmt++;
        size++;
    }
    return size;
}

char *create_flag_str(char const *format, int i_fmt, int size)
{
    char *flag_str = malloc(sizeof(char) * (i_fmt - size));

    if (flag_str == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        flag_str[i] = format[i + i_fmt];
    }
    return flag_str;
}

int get_flag_char(conversion_specifier_t *conv_spec, char const *format
    , int i_fmt)
{
    int size = get_flags_size(format, i_fmt);

    if (size == 0) {
        conv_spec->flag_characters = NULL;
        return 0;
    }
    conv_spec->flag_characters = create_flag_str(format, i_fmt, size);
    return size;
}
