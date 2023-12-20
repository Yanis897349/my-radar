/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Air traffic simulation panel
*/

#include <stdlib.h>
#include <stdio.h>
#include "Simulation/simulation.h"
#include "Simulation/tower.h"
#include "Simulation/aircraft.h"
#include "Parser/parser.h"
#include "Parser/reader.h"
#include "Simulation/tower.h"
#include "include/my_std.h"
#include "include/my_strings.h"
#include "include/my_io.h"

static void display_help(void)
{
    my_putstr("Air traffic simulation panel.\n");
}

int main(int ac, char **av)
{
    if (ac != 2) {
        return EXIT_ERROR;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        display_help();
        return EXIT_SUCCESS;
    }
    if (run_simulation() == EXIT_FAILURE)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
