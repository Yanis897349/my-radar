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
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static float get_direction_angle(sfVector2f departure, sfVector2f arrival)
{
    sfVector2f direction = {arrival.x - departure.x, arrival.y - departure.y};
    float length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    sfVector2f direction_normalized = {direction.x / length,
        direction.y / length};
    float angle = atan2(direction_normalized.y, direction_normalized.x) * 180 /
        M_PI;

    return angle;
}

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
    sfSprite_setScale(aircraft->sprite, (sfVector2f) {0.08, 0.08});
    sfSprite_setRotation(aircraft->sprite,
        get_direction_angle(position, aircraft->arrival));
    aircraft_set_position(aircraft, position);
    return EXIT_SUCCESS;
}

static void set_aircraft_info(aircraft_t *aircraft, int speed, int delay)
{
    aircraft->is_crashed = 0;
    aircraft->is_landed = 0;
    aircraft->speed = speed;
    aircraft->delay_before_takeoff = delay;
}

void aircraft_set_position(aircraft_t *aircraft, sfVector2f position)
{
    aircraft->position = position;
    sfSprite_setPosition(aircraft->sprite, position);
    sfRectangleShape_setPosition(aircraft->hitbox, position);
    if (aircraft->position.x == aircraft->arrival.x &&
        aircraft->position.y == aircraft->arrival.y)
        aircraft->is_landed = 1;
}

void aircraft_move(aircraft_t *aircraft)
{
    int window_width = DEFAULT_WINDOW_WIDTH;
    int window_height = DEFAULT_WINDOW_HEIGHT;
    int speed = aircraft->speed;
    sfVector2f final_position = aircraft->arrival;
    sfVector2f position = aircraft->position;
    float distance_x = final_position.x - position.x;
    float distance_y = final_position.y - position.y;

    if (aircraft->is_landed || aircraft->is_crashed)
        return;
    if (fabs(distance_x) <= speed)
        position.x = final_position.x;
    else
        position.x += speed * (distance_x > 0 ? 1 : -1);
    if (fabs(distance_y) <= speed)
        position.y = final_position.y;
    else
        position.y += speed * (distance_y > 0 ? 1 : -1);
    aircraft_set_position(aircraft, position);
}

void destroy_aircraft(aircraft_t *aircraft)
{
    sfSprite_destroy(aircraft->sprite);
    sfTexture_destroy(aircraft->texture);
    sfRectangleShape_destroy(aircraft->hitbox);
    free(aircraft);
}

aircraft_t *create_aircraft(sfVector2f departure, sfVector2f arrival,
    int speed, int delay)
{
    aircraft_t *aircraft = malloc(sizeof(aircraft_t));

    if (aircraft == NULL)
        return NULL;
    aircraft->hitbox = sfRectangleShape_create();
    if (aircraft->hitbox == NULL)
        return NULL;
    sfRectangleShape_setPosition(aircraft->hitbox, departure);
    sfRectangleShape_setFillColor(aircraft->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(aircraft->hitbox, sfBlue);
    sfRectangleShape_setOutlineThickness(aircraft->hitbox, 2);
    sfRectangleShape_setSize(aircraft->hitbox, (sfVector2f) {20, 20});
    sfRectangleShape_setRotation(aircraft->hitbox,
        get_direction_angle(departure, arrival));
    aircraft->arrival = arrival;
    aircraft->departure = departure;
    set_aircraft_info(aircraft, speed, delay);
    if (set_aircraft_sprite(aircraft, departure) == EXIT_FAILURE)
        return NULL;
    return aircraft;
}
