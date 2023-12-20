/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** Find the occurences of a sub-string in a string
*/

#include "strings/my_strings.h"
#include <stddef.h>
#include "io/my_io.h"
#include <strings.h>

static int find_next_occurence(char *str, char const *to_find, int *index_occ)
{
    for (; str[*index_occ] != to_find[0]; (*index_occ)++) {
        if (str[*index_occ] == '\0')
            return -1;
    }
    return -2;
}

static int check_occurence(char *str, char const *to_find, int *index_occur)
{
    size_t to_find_len = my_strlen(to_find);
    int j = 0;

    for (size_t i = *index_occur; i < *index_occur + to_find_len; i++) {
        if (str[i] != to_find[j]) {
            (*index_occur)++;
            return -1;
        }
        j++;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int index_first_char = 0;

    while (find_next_occurence(str, to_find, &index_first_char) != -1) {
        if (check_occurence(str, to_find, &index_first_char) == 1)
            return str + index_first_char;
    }
    return NULL;
}
