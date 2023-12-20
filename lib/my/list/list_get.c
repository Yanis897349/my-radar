/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** list_get
*/

#include "my_list.h"
#include <stdlib.h>

void *get_from_list(linked_list_t **list, void *ref, int (*cmp)())
{
    linked_list_t *tmp = *list;

    while (tmp != NULL) {
        if (cmp(tmp->data, ref) == 0) {
            return tmp->data;
        }
        tmp = tmp->next;
    }
    return NULL;
}
