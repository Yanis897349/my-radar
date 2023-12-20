/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Parser
*/

#include "include/my_strings.h"
#include <stdio.h>

char **parse_script(const char *script_path)
{
    char **script_lines = NULL;
    char *script_content = file_to_buffer(script_path);

    if (script_content == NULL)
        return NULL;
    script_lines = buffer_to_array(script_content, '\n');
    return script_lines;
}
