/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** padd width
*/

#include "io/my_io.h"
#include "io/printf/my_printf.h"
#include "math/my_math.h"
#include "strings/my_strings.h"

int is_minus_flag(conversion_specifier_t *conv_spec)
{
    if (conv_spec->flag_characters == NULL) {
        return 0;
    }
    for (int i = 0; conv_spec->flag_characters[i] != '\0'; i++) {
        if (conv_spec->flag_characters[i] == '-') {
            return 1;
        }
    }
    return 0;
}

int is_zero_flag(conversion_specifier_t *conv_spec)
{
    if (conv_spec->flag_characters == NULL) {
        return 0;
    }
    for (int i = 0; conv_spec->flag_characters[i] != '\0'; i++) {
        if (conv_spec->flag_characters[i] == '0') {
            return 1;
        }
    }
    return 0;
}

int put_padding_zero(conversion_specifier_t *conv_spec, int len)
{
    for (int space = conv_spec->field_width; space > len; space--) {
        my_putchar('0');
    }
    return conv_spec->field_width - len;
}

int put_padding(conversion_specifier_t *conv_spec, int len)
{
    for (int space = conv_spec->field_width; space > len; space--) {
        my_putchar(' ');
    }
    return conv_spec->field_width - len;
}
