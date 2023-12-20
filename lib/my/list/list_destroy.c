/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** list_destroy
*/

#include "my_list.h"
#include <stdlib.h>

void destroy_list(linked_list_t *list, void (*free_func)())
{
    linked_list_t *tmp = list;
    linked_list_t *next_node;

    while (tmp != NULL) {
        free_func(tmp->data);
        next_node = tmp->next;
        free(tmp);
        tmp = next_node;
    }
}
