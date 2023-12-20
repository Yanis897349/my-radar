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
    sfVector2u texture_size;
    int window_height = DEFAULT_WINDOW_HEIGHT;

    tower->texture =
        sfTexture_createFromFile(DEFAULT_TOWER_TEXTURE_PATH, NULL);
    if (tower->texture == NULL)
        return EXIT_FAILURE;
    texture_size = sfTexture_getSize(tower->texture);
    tower->sprite = sfSprite_create();
    if (tower->sprite == NULL)
        return EXIT_FAILURE;
    sfSprite_setTexture(tower->sprite, tower->texture, sfTrue);
    tower_set_position(tower, position);
    return EXIT_SUCCESS;
}

void destroy_tower(tower_t *tower)
{
    sfSprite_destroy(tower->sprite);
    sfTexture_destroy(tower->texture);
    free(tower);
}

tower_t *create_tower(sfRenderWindow *window, sfVector2f position)
{
    tower_t *tower = malloc(sizeof(tower_t));

    if (tower == NULL)
        return NULL;
    if (set_tower_sprite(tower, position) == EXIT_FAILURE)
        return NULL;
    return tower;
}
