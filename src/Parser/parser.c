/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Parser
*/

#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "Simulation/aircraft.h"
#include "Simulation/tower.h"
#include "include/my_std.h"
#include "include/my_strings.h"
#include "include/my_math.h"

static int get_aircrafts_count(char **script_content)
{
    unsigned int aircrafts_count = 0;

    for (size_t i = 0; script_content[i] != NULL; i++) {
        if (script_content[i][0] == 'A')
            aircrafts_count++;
    }
    return aircrafts_count;
}

static int get_towers_count(char **script_content)
{
    unsigned int towers_count = 0;

    for (size_t i = 0; script_content[i] != NULL; i++) {
        if (script_content[i][0] == 'T')
            towers_count++;
    }
    return towers_count;
}

static aircraft_t *parse_aircraft(char *line)
{
    aircraft_t *aircraft = NULL;
    char **aircraft_info = buffer_to_array(line, ' ');
    sfVector2f departure = {0, 0};
    sfVector2f arrival = {0, 0};
    int speed = 0;
    int delay = 0;

    if (aircraft_info == NULL)
        return NULL;
    departure.x = my_getnbr(aircraft_info[1]);
    departure.y = my_getnbr(aircraft_info[2]);
    arrival.x = my_getnbr(aircraft_info[3]);
    arrival.y = my_getnbr(aircraft_info[4]);
    speed = my_getnbr(aircraft_info[5]);
    delay = my_getnbr(aircraft_info[6]);
    aircraft = create_aircraft(departure, arrival, speed, delay);
    my_freearray(aircraft_info);
    return aircraft;
}

static tower_t *parse_tower(char *line)
{
    tower_t *tower = NULL;
    char **tower_info = buffer_to_array(line, ' ');
    sfVector2f position = {0, 0};
    int radius = 0;

    if (tower_info == NULL)
        return NULL;
    position.x = my_getnbr(tower_info[1]);
    position.y = my_getnbr(tower_info[2]);
    radius = my_getnbr(tower_info[3]);
    tower = create_tower(position, radius);
    my_freearray(tower_info);
    return tower;
}

aircraft_t **parse_aircraft_from_script(char **script_content)
{
    aircraft_t **aircrafts = NULL;
    unsigned int aircrafts_count = get_aircrafts_count(script_content);
    int aircraft_idx = 0;

    aircrafts = malloc(sizeof(aircraft_t *) * (aircrafts_count + 1));
    if (aircrafts == NULL)
        return NULL;
    for (int i = 0; script_content[i] != NULL; i++) {
        if (script_content[i][0] == 'A') {
            aircrafts[aircraft_idx] = parse_aircraft(script_content[i]);
            aircraft_idx++;
        }
    }
    aircrafts[aircrafts_count] = NULL;
    return aircrafts;
}

tower_t **parse_tower_from_script(char **script_content)
{
    tower_t **towers = NULL;
    unsigned int towers_count = get_towers_count(script_content);
    int tower_idx = 0;

    towers = malloc(sizeof(tower_t *) * (towers_count + 1));
    if (towers == NULL)
        return NULL;
    for (int i = 0; script_content[i] != NULL; i++) {
        if (script_content[i][0] == 'T') {
            towers[tower_idx] = parse_tower(script_content[i]);
            tower_idx++;
        }
    }
    towers[towers_count] = NULL;
    return towers;
}
