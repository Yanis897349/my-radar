/*
** EPITECH PROJECT, 2023
** my_put_float.c
** File description:
** Print a float number with a defined precision
*/

#include "my_io.h"
#include "strings/my_strings.h"
#include "math/my_math.h"
#include <stdint.h>
#include <sys/types.h>

static int64_t my_round_float(double x, int precision)
{
    int64_t to_parse = x * (my_compute_power_rec(10, precision - 1));
    int64_t to_add = 0;

    if (to_parse % 10 >= 5) {
        to_add = 1;
    }
    to_parse /= 10;
    to_parse += to_add;
    return to_parse;
}

static int print_exponent(double x, int exponent)
{
    int count = 0;

    my_putchar('e');
    count++;
    if (x >= 0) {
        my_putchar('+');
        count++;
    } else {
        my_putchar('-');
        count++;
    }
    if (exponent > 10) {
        my_put_nbr(exponent);
        count += 2;
    } else {
        my_putchar('0');
        my_putchar(exponent + '0');
        count += 2;
    }
    return count;
}

static void print_double(char *display, int str_index)
{
    for (int i = 0; i < str_index; i++) {
        if (i == 1) {
            my_putchar('.');
        }
        if (display[i] == '0' && display[i + 1] == '0') {
            break;
        }
        my_putchar(display[i]);
    }
}

int my_put_exponent(double x, int precision)
{
    int str_index = 0;
    char display[SIZE_TO_HANDLE_DOUBLE];
    int64_t to_parse = my_round_float(x, precision);
    int exponent = my_nbrlen((long long) x) - 1;

    while (to_parse != 0) {
        display[str_index] = (to_parse % 10) + '0';
        to_parse /= 10;
        str_index++;
    }
    display[str_index] = '\0';
    my_revstr(display);
    print_double(display, str_index);
    print_exponent(x, exponent);
    return my_strlen(display);
}
