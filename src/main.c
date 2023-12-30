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
    char **script_content = NULL;
    aircraft_t **aircrafts = NULL;
    tower_t **towers = NULL;

    if (ac != 2) {
        return EXIT_ERROR;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        display_help();
        return EXIT_SUCCESS;
    }
    script_content = parse_script(av[1]);
    aircrafts = parse_aircraft_from_script(script_content);
    towers = parse_tower_from_script(script_content);
    if (run_simulation(towers, aircrafts) == EXIT_FAILURE)
        return EXIT_ERROR;
    my_freearray(script_content);
    return EXIT_SUCCESS;
}
