/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** Parse string to int
*/

#include "ctype/my_ctype.h"
#include <limits.h>

static int get_start(char const *str)
{
    int start = 0;

    while (!my_isdigit(str[start]) && str[start] != '\0') {
        start++;
    }
    return start;
}

static int is_negative(char const *str)
{
    int start = 0;
    int is_neg = 0;

    while (!my_isdigit(str[start]) && str[start] != '\0') {
        if (str[start] == '-') {
            is_neg = !is_neg;
        }
        start++;
    }
    return is_neg;
}

static int is_valid(const char *str)
{
    int is_valid = 0;

    if (str[0] == '-' || str[0] == '+') {
        is_valid = 1;
    }
    if (my_isdigit(str[0])) {
        is_valid = 1;
    }
    return is_valid;
}

static int parse_to_int(char *str, int size, int is_neg)
{
    long parsed = 0;
    int next_to_add = 0;

    if (size > 10) {
        return 0;
    }
    for (int i = 0; i < size; i++) {
        next_to_add = my_char_to_int(str[i]);
        if ((is_neg && -parsed) < (INT_MIN + next_to_add) / 10 ||
                (!is_neg && parsed) > (INT_MAX - next_to_add) / 10) {
            return 0;
        }
        parsed = parsed * 10 + next_to_add;
    }
    if (is_neg) {
        parsed = -parsed;
    }
    return (int)parsed;
}

int my_getnbr(char const *str)
{
    int start = 0;
    int end = 0;
    int is_neg = 0;
    int patched_size = 0;
    char patched_str[11];

    start = get_start(str);
    is_neg = is_negative(str);
    if (str[start] == '\0' || !is_valid(str)) {
        return 0;
    }
    end = start;
    while (my_isdigit(str[end])) {
        end++;
    }
    for (; start < end; patched_size++) {
        patched_str[patched_size] = str[start];
        start++;
    }
    return parse_to_int(patched_str, patched_size, is_neg);
}
