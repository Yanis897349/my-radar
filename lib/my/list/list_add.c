/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** list_add
*/

#include "my_list.h"
#include <stdlib.h>

void add_to_list(linked_list_t **list, void *data)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    linked_list_t *tmp = *list;

    if (new_node == NULL)
        return;
    new_node->data = data;
    new_node->next = tmp;
    *list = new_node;
}
