/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** World management
*/

#include "Simulation/world.h"
#include "Simulation/aircraft.h"
#include "Simulation/quadtree.h"
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

static int get_tower_count(tower_t **towers)
{
    int count = 0;

    for (int i = 0; towers[i] != NULL; i++)
        count++;
    return count;
}

static int get_aircraft_count(aircraft_t **aircrafts)
{
    int count = 0;

    for (int i = 0; aircrafts[i] != NULL; i++)
        count++;
    return count;
}

void destroy_world(world_t *world)
{
    sfSprite_destroy(world->background_sprite);
    sfTexture_destroy(world->background_texture);
    free(world->towers);
    for (uint i = 0; world->corners[i] != NULL; i++)
        destroy_corner(world->corners[i]);
    free(world);
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

world_t *create_world(tower_t **towers, aircraft_t **aircrafts)
{
    world_t *world = malloc(sizeof(world_t));
    int_rect_t bounds;

    if (world == NULL)
        return NULL;
    world->background_sprite = NULL;
    world->background_texture = NULL;
    world->towers = towers;
    world->towers_count = get_tower_count(towers);
    for (uint i = 0; i < 4; i++) {
        bounds.left = (i % 2) * 960;
        bounds.top = (i / 2) * 540;
        bounds.width = 960;
        bounds.height = 540;
        world->corners[i] = create_corner(bounds);
    }
    dispatch_aircrafts(world, aircrafts, get_aircraft_count(aircrafts));
    if (world_set_background(world, WORLD_BACKGROUND_PATH) == EXIT_FAILURE)
        return NULL;
    return world;
}
