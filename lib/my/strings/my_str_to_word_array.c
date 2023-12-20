/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** Splits a string into words and returns an array of these words.
*/

#include "ctype/my_ctype.h"
#include "strings/my_strings.h"
#include <stdlib.h>
#include <stddef.h>

static int count_words(char const *str)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isdigit(str[i]) || my_isalpha(str[i])) {
            in_word = 1;
            continue;
        }
        if (in_word) {
            count++;
            in_word = 0;
        }
    }
    if (in_word)
        count++;
    return count;
}

static void find_word(const char *str, int *i, const char **word_start,
    int *word_len)
{
    for (; str[*i] != '\0'; (*i)++) {
        if (my_isdigit(str[*i]) || my_isalpha(str[*i])) {
            *word_start = (*word_len == 0) ? &str[*i] : *word_start;
            (*word_len)++;
            continue;
        }
        if (*word_len > 0) {
            break;
        }
    }
}

static void add_word_to_array(const char *word_start, int word_len,
    char **array, int *index)
{
    array[*index] = my_strndup(word_start, word_len);
    (*index)++;
}

static char **fill_array(const char *str, char **array)
{
    int word_len = 0;
    int index = 0;
    const char *word_start = 0;

    for (int i = 0; str[i] != '\0';) {
        find_word(str, &i, &word_start, &word_len);
        if (word_len > 0) {
            add_word_to_array(word_start, word_len, array, &index);
            word_len = 0;
        }
    }
    if (word_len > 0) {
        add_word_to_array(word_start, word_len, array, &index);
    }
    array[index] = NULL;
    return array;
}

char **my_str_to_word_array(const char *str)
{
    int words_count = 0;
    char **array;

    if (!str)
        return NULL;
    words_count = count_words(str);
    array = (char **)malloc(sizeof(char *) * (words_count + 1));
    if (array == NULL)
        return NULL;
    return fill_array(str, array);
}
