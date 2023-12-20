/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** World management
*/

#pragma once
#include "Simulation/aircraft.h"
#include "Simulation/tower.h"
#include <SFML/Graphics/Types.h>
#define WORLD_BACKGROUND_PATH "src/assets/world/background.jpg"

typedef struct world_s {
    sfTexture *background_texture;
    sfSprite *background_sprite;
    tower_t **towers;
    aircraft_t **aircrafts;
    unsigned int towers_count;
    unsigned int aircrafts_count;
} world_t;

void destroy_world(world_t *world);
int add_aircraft_to_world(world_t *world, aircraft_t *aircraft);
int add_tower_to_world(world_t *world, tower_t *tower);
world_t *create_world(void);
