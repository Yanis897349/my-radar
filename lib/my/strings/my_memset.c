/*
** EPITECH PROJECT, 2023
** my_memset
** File description:
** Implementation of my_memset
*/

#include <stddef.h>

void *my_memset(void *pointer, int value, size_t count)
{
    for (size_t i = 0; i < count; i++)
        ((char *)pointer)[i] = value;
    return pointer;
}
