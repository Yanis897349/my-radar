/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Tower management
*/

#include "Simulation/tower.h"
#include "Screen/screen.h"
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Types.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>

static void tower_set_position(tower_t *tower, sfVector2f position)
{
    double window_width = DEFAULT_WINDOW_WIDTH;

    if (position.x > window_width)
        position = (sfVector2f) {0, position.y};
    tower->position = position;
    sfSprite_setPosition(tower->sprite, position);
}

static int set_tower_sprite(tower_t *tower, sfVector2f position)
{
    tower->texture =
        sfTexture_createFromFile(DEFAULT_TOWER_TEXTURE_PATH, NULL);
    if (tower->texture == NULL)
        return EXIT_FAILURE;
    tower->sprite = sfSprite_create();
    if (tower->sprite == NULL)
        return EXIT_FAILURE;
    sfSprite_setTexture(tower->sprite, tower->texture, sfTrue);
    sfSprite_setScale(tower->sprite, (sfVector2f) {0.08, 0.08});
    tower_set_position(tower, position);
    return EXIT_SUCCESS;
}

static void set_tower_info(tower_t *tower, float radius_control_area)
{
    float scaled_tower_size = 512 * 0.08f;
    sfVector2f tower_center = {0, 0};
    sfVector2f circle_pos = {0, 0};

    radius_control_area = 1920 * radius_control_area / 100.0f;
    tower_center.x = tower->position.x + scaled_tower_size / 2.0f;
    tower_center.y = tower->position.y + scaled_tower_size / 2.0f;
    circle_pos.x = tower_center.x - radius_control_area;
    circle_pos.y = tower_center.y - radius_control_area;
    tower->circle_area = sfCircleShape_create();
    sfCircleShape_setPosition(tower->circle_area, circle_pos);
    sfCircleShape_setRadius(tower->circle_area, radius_control_area);
    sfCircleShape_setFillColor(tower->circle_area, sfTransparent);
    sfCircleShape_setOutlineColor(tower->circle_area, sfRed);
    sfCircleShape_setOutlineThickness(tower->circle_area, 2);
    tower->control_area = radius_control_area;
}

void destroy_tower(tower_t *tower)
{
    sfSprite_destroy(tower->sprite);
    sfTexture_destroy(tower->texture);
    sfCircleShape_destroy(tower->circle_area);
    free(tower);
}

tower_t *create_tower(sfVector2f position, float control_area)
{
    tower_t *tower = malloc(sizeof(tower_t));

    if (tower == NULL)
        return NULL;
    if (set_tower_sprite(tower, position) == EXIT_FAILURE)
        return NULL;
    set_tower_info(tower, control_area);
    return tower;
}
