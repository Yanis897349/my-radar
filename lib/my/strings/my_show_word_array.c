/*
** EPITECH PROJECT, 2023
** my_show_word_array.c
** File description:
** Displays the content of an array of words
*/

#include "io/my_io.h"
#include <stddef.h>

int my_show_word_array(char *const *tab)
{
    if (!tab)
        return 0;
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
