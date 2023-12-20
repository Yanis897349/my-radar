/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** list_remove
*/

#include "my_list.h"
#include <stdio.h>
#include <stdlib.h>

static void destroy_matching_node(linked_list_t *prev, linked_list_t *tmp,
    linked_list_t **list, void (*free_func)())
{
    if (prev == NULL) {
        *list = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    free_func(tmp->data);
    free(tmp);
}

int delete_from_list(linked_list_t **list, void *ref, int (*cmp)(),
    void (*free_func)())
{
    linked_list_t *tmp = *list;
    linked_list_t *prev = NULL;

    while (tmp != NULL) {
        if (cmp(tmp->data, ref) == 0) {
            destroy_matching_node(prev, tmp, list, free_func);
            return 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return 0;
}
