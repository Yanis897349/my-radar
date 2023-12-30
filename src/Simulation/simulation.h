/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Simulation entry point
*/

#pragma once
#include "Screen/screen.h"
#include "Simulation/world.h"
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#define MS_TO_SEC 1000000

typedef struct simulation_s {
    screen_t *screen;
    world_t *world;
    sfClock *clock;
    sfEvent event;
} simulation_t;

int run_simulation(tower_t **towers, aircraft_t **aircrafts);
