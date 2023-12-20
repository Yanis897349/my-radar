/*
** EPITECH PROJECT, 2023
** my_string
** File description:
** my_array_len
*/

#include <stddef.h>

int my_array_len(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}
