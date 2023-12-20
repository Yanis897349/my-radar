/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Parser
*/

#pragma once
#include "Simulation/aircraft.h"
#include "Simulation/tower.h"

aircraft_t **parse_aircraft_from_script(char **script_content);
tower_t **parse_tower_from_script(char **script_content);
