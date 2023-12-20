/*
** EPITECH PROJECT, 2023
** my_put_float.c
** File description:
** Print a float number with a defined precision
*/

#include "my_io.h"
#include "strings/my_strings.h"
#include "math/my_math.h"
#include <stdlib.h>

static void int_to_str(char *str, long long n, int precision)
{
    int i = 0;

    while (n > 0) {
        str[i] = (n % 10) + '0';
        n = n / 10;
        i++;
    }
    while (i < precision) {
        str[i] = '0';
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
}

static void float_to_int_str(char *str, long long int_part, int is_negative)
{
    if (is_negative) {
        *str = '-';
        *str = *str + 1;
        int_to_str(str, -int_part, 0);
    } else {
        int_to_str(str, int_part, 0);
    }
}

static void float_to_frac_str(char *str, double frac_part, int precision)
{
    long long int_frac_part = my_round(frac_part * my_pow10(precision));

    int_to_str(str, int_frac_part, precision);
}

static void assemble_str(char *display, double x, int precision)
{
    int is_negative = x < 0;
    int int_part_len = 0;
    double exp_factor = 0;
    double frac_part = 0;
    long long int_part = 0;

    x = my_fabs(x);
    exp_factor = my_round(x * my_pow10(precision));
    int_part = (long long) (exp_factor / my_pow10(precision));
    frac_part = (exp_factor - int_part * my_pow10(precision))
        / my_pow10(precision);
    float_to_int_str(display, int_part, is_negative);
    int_part_len = my_strlen(display);
    if (precision > 0) {
        display[int_part_len] = '.';
        float_to_frac_str(display + int_part_len + 1, frac_part, precision);
    }
}

int my_put_float(double x, int precision)
{
    int display_size = 1;
    int is_negative = x < 0;
    int char_printed = 0;
    char *display;

    if (is_negative) {
        display_size++;
    }
    if (precision > 0) {
        display_size += precision + 1;
    }
    display = (char *) malloc(display_size);
    if (display == NULL) {
        return 0;
    }
    assemble_str(display, x, precision);
    char_printed = my_putstr(display);
    free(display);
    return char_printed;
}
