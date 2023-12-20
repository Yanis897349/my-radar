/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** my_list
*/

#pragma once

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;

void null_function(void *data);
void destroy_list(linked_list_t *list, void (*free_func)());

void *get_from_list(linked_list_t **list, void *ref, int (*cmp)());
int get_list_size(linked_list_t **list);

linked_list_t *create_list(void *data);
void add_to_list(linked_list_t **list, void *data);
int delete_from_list(linked_list_t **list, void *ref, int (*cmp)(),
    void (*free_func)());
