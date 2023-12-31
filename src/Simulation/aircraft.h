/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Aircraft management
*/

#pragma once
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#define DEFAULT_AIRCRAFT_TEXTURE_PATH "src/assets/entity/plane.png"
#define LANDING_THRESHOLD 2.0f

typedef struct aircraft_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *hitbox;
    sfVector2f departure;
    sfVector2f arrival;
    sfVector2f position;
    int speed;
    int delay_before_takeoff;
    int is_landed;
    int is_crashed;
} aircraft_t;

void aircraft_set_position(aircraft_t *aircraft, sfVector2f position);
void aircraft_move(aircraft_t *aircraft);
void destroy_aircraft(aircraft_t *aircraft);
aircraft_t *create_aircraft(sfVector2f departure, sfVector2f arrival,
    int speed, int delay);
