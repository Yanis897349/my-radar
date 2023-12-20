/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Air traffic simulation panel
*/

#include "Game/game.h"
#include "include/my_std.h"
#include "include/my_strings.h"
#include "include/my_io.h"
#include <stdlib.h>

static void display_help(void)
{
    my_putstr("Air traffic simulation panel.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_help();
        return EXIT_SUCCESS;
    }
    if (run_game() == EXIT_FAILURE)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
