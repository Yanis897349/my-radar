/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_memcpy
*/
#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t size)
{
    char *dest_char = dest;
    const char *src_char = src;

    for (size_t i = 0; i < size; i++)
        dest_char[i] = src_char[i];
    return dest;
}
