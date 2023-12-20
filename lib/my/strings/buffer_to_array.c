/*
** EPITECH PROJECT, 2023
** my_string
** File description:
** buffer_to_array
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_strings.h"

static char *my_strtok(char *str, char delimiter)
{
    static char *next_token = NULL;
    char *token_start = next_token;

    if (str != NULL) {
        next_token = str;
    }
    if (next_token == NULL || *next_token == '\0') {
        return NULL;
    }
    token_start = next_token;
    while (*next_token != '\0' && *next_token != delimiter) {
        next_token++;
    }
    if (*next_token == '\0') {
        next_token = NULL;
    } else {
        *next_token = '\0';
        next_token++;
    }
    return token_start;
}

char **buffer_to_array(char *buffer, char delimiter)
{
    char **board = NULL;
    int line_count = 0;
    char *token;
    int line = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == delimiter)
            line_count++;
    board = malloc(sizeof(char *) * (line_count + 1));
    if (board == NULL)
        return NULL;
    token = my_strtok(buffer, delimiter);
    while (token != NULL) {
        board[line] = malloc(my_strlen(token) + 1);
        my_strcpy(board[line], token);
        line++;
        token = my_strtok(NULL, delimiter);
    }
    board[line_count] = NULL;
    return board;
}
