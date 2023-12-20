/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Tower management
*/

#pragma once
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>
#define DEFAULT_TOWER_TEXTURE_PATH "src/assets/entity/tower.png"

typedef struct tower_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    float control_area;
} tower_t;

void destroy_tower(tower_t *tower);
tower_t *create_tower(sfRenderWindow *window, sfVector2f position);
