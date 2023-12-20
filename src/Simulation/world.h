/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** World management
*/

#pragma once
#include "Simulation/entity.h"
#include <SFML/Graphics/Types.h>
#define WORLD_BACKGROUND_PATH "src/assets/world/background.jpg"

typedef struct world_s {
    sfTexture *background_texture;
    sfSprite *background_sprite;
    entity_t **entities;
    unsigned int entities_count;
} world_t;

int add_entity_to_world(world_t *world, entity_t *entity);
world_t *create_world(void);
