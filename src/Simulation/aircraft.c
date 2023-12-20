/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Aircraft management
*/

#include "Simulation/aircraft.h"
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

static int set_aircraft_sprite(aircraft_t *aircraft, sfVector2f position)
{
    aircraft->texture =
        sfTexture_createFromFile(DEFAULT_AIRCRAFT_TEXTURE_PATH, NULL);
    if (aircraft->texture == NULL)
        return EXIT_FAILURE;
    aircraft->sprite = sfSprite_create();
    if (aircraft->sprite == NULL)
        return EXIT_FAILURE;
    sfSprite_setTexture(aircraft->sprite, aircraft->texture, sfTrue);
    aircraft_set_position(aircraft, position);
    return EXIT_SUCCESS;
}

void aircraft_set_position(aircraft_t *aircraft, sfVector2f position)
{
    double window_width = DEFAULT_WINDOW_WIDTH;

    if (position.x > window_width)
        position = (sfVector2f) {0, position.y};
    aircraft->position = position;
    sfSprite_setPosition(aircraft->sprite, position);
}

void destroy_aircraft(aircraft_t *aircraft)
{
    sfSprite_destroy(aircraft->sprite);
    sfTexture_destroy(aircraft->texture);
    free(aircraft);
}

aircraft_t *create_aircraft(sfVector2f departure, sfVector2f arrival,
    int speed, int delay)
{
    aircraft_t *aircraft = malloc(sizeof(aircraft_t));

    if (aircraft == NULL)
        return NULL;
    aircraft->arrival = arrival;
    aircraft->departure = departure;
    aircraft->speed = speed;
    aircraft->delay_before_takeoff = delay;
    if (set_aircraft_sprite(aircraft, departure) == EXIT_FAILURE)
        return NULL;
    return aircraft;
}
