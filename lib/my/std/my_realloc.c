/*
** EPITECH PROJECT, 2023
** stdlib
** File description:
** Implementation of realloc
*/

#include "strings/my_strings.h"
#include <stdlib.h>

void *my_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr = NULL;

    if (ptr == NULL)
        return malloc(new_size);
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return NULL;
    my_memcpy(new_ptr, ptr, old_size);
    free(ptr);
    return new_ptr;
}
