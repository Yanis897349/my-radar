/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Event handler
*/

#include "Game/entity.h"
#include "Game/game.h"
#include "Game/world.h"
#include "Screen/screen.h"
#include <SFML/Audio/Sound.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Mouse.h>
#include <stdio.h>
#include <stdlib.h>

static void handle_resize(sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);

    if (size.x != DEFAULT_WINDOW_WIDTH || size.y != DEFAULT_WINDOW_HEIGHT)
        sfRenderWindow_setSize(window,
            (sfVector2u){DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT});
}

void event_handler(game_t *game)
{
    sfEvent event = game->game_event;

    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(game->screen->window);
        break;
    case sfEvtResized:
        handle_resize(game->screen->window);
        break;
    default:
        break;
    }
}
