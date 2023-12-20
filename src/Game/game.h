/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Game entry point
*/

#pragma once
#include "Screen/screen.h"
#include "Game/world.h"
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct game_s {
    screen_t *screen;
    world_t *world;
    sfEvent game_event;
    sfClock *game_clock;
} game_t;

int run_game(void);
