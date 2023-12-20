/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Game entry point
*/

#include "Game/game.h"
#include "Game/entity.h"
#include "Game/world.h"
#include "Screen/screen.h"
#include "Events/event_handler.h"
#include <SFML/System/Clock.h>
#include <SFML/Window/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

static int render_world(game_t *game)
{
    sfRenderWindow_drawSprite(game->screen->window,
        game->world->background_sprite, NULL);
    for (uint i = 0; i < game->world->entities_count; i++) {
        update_entity(game->world->entities[i], game->screen->window);
        sfRenderWindow_drawSprite(game->screen->window,
            game->world->entities[i]->sprite, NULL);
    }
    return EXIT_SUCCESS;
}

static int run_game_loop(game_t *game)
{
    game->game_clock = sfClock_create();
    while (sfRenderWindow_isOpen(game->screen->window)) {
        while (sfRenderWindow_pollEvent(game->screen->window,
            &game->game_event))
            event_handler(game);
        if (sfClock_getElapsedTime(game->game_clock).microseconds >
            MS_TO_SEC / WINDOW_FPS_LIMIT) {
            sfClock_restart(game->game_clock);
            sfRenderWindow_clear(game->screen->window, sfBlack);
            render_world(game);
            sfRenderWindow_display(game->screen->window);
        }
    }
    return EXIT_SUCCESS;
}

static void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->screen->window);
    sfSprite_destroy(game->world->background_sprite);
    sfTexture_destroy(game->world->background_texture);
    for (uint i = 0; i < game->world->entities_count; i++)
        destroy_entity(game->world->entities[i]);
    sfClock_destroy(game->game_clock);
    free(game->world->entities);
    free(game->screen);
}

int run_game(void)
{
    game_t game;

    game.screen = create_game_screen(DEFAULT_WINDOW_WIDTH,
        DEFAULT_WINDOW_HEIGHT);
    if (game.screen == NULL)
        return EXIT_FAILURE;
    game.world = create_world();
    if (game.world == NULL)
        return EXIT_FAILURE;
    if (run_game_loop(&game) == EXIT_FAILURE)
        return EXIT_FAILURE;
    destroy_game(&game);
    return EXIT_SUCCESS;
}
