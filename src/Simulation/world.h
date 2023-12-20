/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** World management
*/

#pragma once
#include "Simulation/tower.h"
#include <SFML/Graphics/Types.h>
#define WORLD_BACKGROUND_PATH "src/assets/world/background.jpg"

typedef struct world_s {
    sfTexture *background_texture;
    sfSprite *background_sprite;
    tower_t **towers;
    unsigned int towers_count;
} world_t;

int add_tower_to_world(world_t *world, tower_t *tower);
world_t *create_world(void);
