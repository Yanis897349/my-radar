/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** list_size
*/

#include "my_list.h"
#include <stddef.h>

int get_list_size(linked_list_t **list)
{
    linked_list_t *tmp = *list;
    int size = 0;

    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return size;
}
