/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Screen management
*/

#include "Screen/screen.h"
#include <SFML/Config.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Types.h>
#include <stdlib.h>

static int create_window(screen_t *screen)
{
    screen->window = sfRenderWindow_create(
        screen->window_mode, WINDOW_NAME, sfResize | sfClose, NULL);
    if (screen->window == NULL)
        return EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(screen->window, WINDOW_FPS_LIMIT);
    return EXIT_SUCCESS;
}

screen_t *create_game_screen(int window_width, int window_height)
{
    screen_t *screen = malloc(sizeof(screen_t));

    if (screen == NULL)
        return NULL;
    screen->window_mode.width = window_width;
    screen->window_mode.height = window_height;
    screen->window_mode.bitsPerPixel = DEFAULT_WINDOW_PIXELS;
    if (create_window(screen) == EXIT_FAILURE)
        return NULL;
    return screen;
}
