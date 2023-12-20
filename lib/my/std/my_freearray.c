/*
** EPITECH PROJECT, 2023
** stdlib
** File description:
** Free-ing 2d array
*/

#include <stdlib.h>

void my_freearray(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
