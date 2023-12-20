/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Simulation entry point
*/

#pragma once
#include "Screen/screen.h"
#include "Simulation/world.h"
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct simulation_s {
    screen_t *screen;
    world_t *world;
    sfEvent event;
    sfClock *clock;
} simulation_t;

int run_simulation(void);
