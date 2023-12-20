/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** World management
*/

#include "Simulation/world.h"
#include "Simulation/tower.h"
#include "Simulation/simulation.h"
#include "include/my_std.h"
#include "include/my_strings.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <stdio.h>
#include <stdlib.h>

static int world_set_background(world_t *world, char *texture_path)
{
    if (world->background_sprite != NULL)
        sfSprite_destroy(world->background_sprite);
    if (world->background_texture != NULL)
        sfTexture_destroy(world->background_texture);
    world->background_sprite = sfSprite_create();
    if (world->background_sprite == NULL)
        return EXIT_FAILURE;
    world->background_texture = sfTexture_createFromFile(texture_path, NULL);
    if (world->background_texture == NULL)
        return EXIT_FAILURE;
    sfSprite_setTexture(world->background_sprite,
        world->background_texture, sfTrue);
    return EXIT_SUCCESS;
}

int add_tower_to_world(world_t *world, tower_t *tower)
{
    int old_towers_size = world->towers_count * sizeof(tower_t);
    int new_towers_size = old_towers_size + sizeof(tower_t);

    world->towers = my_realloc(world->towers, old_towers_size,
        new_towers_size);
    if (world->towers == NULL)
        return EXIT_FAILURE;
    world->towers[world->towers_count] = tower;
    world->towers_count++;
    return EXIT_SUCCESS;
}

world_t *create_world(void)
{
    world_t *world = malloc(sizeof(world_t));

    if (world == NULL)
        return NULL;
    world->background_sprite = NULL;
    world->background_texture = NULL;
    world->towers = NULL;
    world->towers_count = 0;
    if (world_set_background(world, WORLD_BACKGROUND_PATH) == EXIT_FAILURE)
        return NULL;
    return world;
}
