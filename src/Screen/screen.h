/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Window management
*/

#pragma once
#include <SFML/Graphics.h>
#define WINDOW_NAME "My Hunter"
#define DEFAULT_WINDOW_WIDTH 1920
#define DEFAULT_WINDOW_HEIGHT 1080
#define DEFAULT_WINDOW_PIXELS 32
#define WINDOW_FPS_LIMIT 120

typedef struct screen_s {
    sfRenderWindow *window;
    sfVideoMode window_mode;
} screen_t;

void destroy_screen(screen_t *screen);
screen_t *create_sim_screen(int window_width, int window_height);
