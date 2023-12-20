/*
** EPITECH PROJECT, 2023
** stdlib
** File description:
** Implementatiof of stdlib
*/

#pragma once
#include <stddef.h>
#define EXIT_ERROR 84

void *my_realloc(void *ptr, size_t old_size, size_t new_size);
void my_freearray(char **array);
