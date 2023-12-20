/*
** EPITECH PROJECT, 2023
** my_showstr.c
** File description:
** Function that prints a string. If non-printable, prints hexa-value
*/

#include "strings/my_strings.h"
#include "io/my_io.h"
#include "ctype/my_ctype.h"
#include <stddef.h>
#include <sys/types.h>

static void print_char_hex(char c)
{
    char hex_base[] = "0123456789abcdef";
    char a;
    char b;

    a = hex_base[(c / 16) % 16];
    b = hex_base[c % 16];
    my_putstr("\\");
    my_putchar(a);
    my_putchar(b);
}

int my_show_str(char const *str)
{
    size_t len = my_strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (my_isprint(str[i])) {
            my_putchar(str[i]);
        } else {
            print_char_hex(str[i]);
        }
    }
    return 0;
}
