/*
** EPITECH PROJECT, 2023
** MY_IO_H_
** File description:
** Header for my io lib
*/

#ifndef MY_IO_H_
    #define MY_IO_H_
    #define SIZE_TO_HANDLE_DOUBLE 2000
    #include <stdint.h>
    #include <sys/types.h>
int my_putchar(char c);
int my_putchar_error(char c);
int my_put_nbr(int n);
int my_put_nbr_unsigned(uint n);
int my_putstr(char const *str);
int my_putnstr(char const *str, int n);
int my_putstr_error(char const *str);
int my_put_float(double x, int precision);
int my_put_exponent(double x, int precision);
int my_put_hexadecimal(int nb, int is_upper, char *str);
int my_put_pointer(long int n);
int my_put_octal(unsigned int n, char *str);
#endif /* MY_IO_H_ */
