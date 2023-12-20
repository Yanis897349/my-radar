/*
** EPITECH PROJECT, 2023
** FLAG_CHARACTERS
** File description:
** Header file for flag characters handling
*/

#ifndef FLAG_CHARACTERS_H_
    #define FLAG_CHARACTERS_H_
    #include "io/printf/my_printf.h"
    #include <stddef.h>
    #include <stdarg.h>
    #include "stdint.h"

/*Main running functions*/

int alternate_form(conversion_specifier_t *conv_spec, void **arg_tab);

/* Flag characters functions */

int alternate_hexadecimal(conversion_specifier_t *conv_spec);
int put_padding(conversion_specifier_t *, int len);
int put_padding_zero(conversion_specifier_t *, int len);
int is_minus_flag(conversion_specifier_t *conv_spec);
int is_zero_flag(conversion_specifier_t *);
int put_padding_integer(conversion_specifier_t *, int , int (*pf)(), int );
int put_padding_hex(conversion_specifier_t *, long long, int (*pf)(), int );
#endif
