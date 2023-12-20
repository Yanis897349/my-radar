/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** list_create
*/

#include "my_list.h"
#include <stdlib.h>

linked_list_t *create_list(void *data)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    if (list == NULL)
        return (NULL);
    list->data = data;
    list->next = NULL;
    return list;
}
