/*
** EPITECH PROJECT, 2023
** my_putnbr_base_unsigned.c
** File description:
** Converts and displays an unsigned decimal number into a given base
*/

#include "strings/my_strings.h"
#include "io/my_io.h"
#include <stddef.h>
#include <sys/types.h>

static void convert_to_str(char *str, const char *base, size_t len, uint n)
{
    int i = 0;

    for (; n > 0; i++) {
        str[i] = base[n % len];
        n /= len;
    }
    str[i] = '\0';
    my_revstr(str);
}

char *my_putnbr_base_unsigned(uint nbr, const char *base)
{
    char str[33];
    size_t base_len = my_strlen(base);

    convert_to_str(str, base, base_len, nbr);
    return my_strdup(str);
}
