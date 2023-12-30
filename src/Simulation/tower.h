/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Tower management
*/

#pragma once
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#define DEFAULT_TOWER_TEXTURE_PATH "src/assets/entity/tower.png"

typedef struct tower_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfCircleShape *circle_area;
    sfVector2f position;
    float control_area;
} tower_t;

void destroy_tower(tower_t *tower);
tower_t *create_tower(sfVector2f position, float control_area);
