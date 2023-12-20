/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Simulation entry point
*/

#include "Simulation/simulation.h"
#include "Simulation/tower.h"
#include "Simulation/world.h"
#include "Screen/screen.h"
#include "Events/event_handler.h"
#include <SFML/System/Clock.h>
#include <SFML/Window/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

static int render_world(simulation_t *sim)
{
    sfRenderWindow_drawSprite(sim->screen->window,
        sim->world->background_sprite, NULL);
    for (uint i = 0; i < sim->world->towers_count; i++) {
        sfRenderWindow_drawSprite(sim->screen->window,
            sim->world->towers[i]->sprite, NULL);
    }
    return EXIT_SUCCESS;
}

static int run_simulation_loop(simulation_t *sim)
{
    sim->clock = sfClock_create();
    while (sfRenderWindow_isOpen(sim->screen->window)) {
        while (sfRenderWindow_pollEvent(sim->screen->window,
            &sim->event))
            event_handler(sim);
        if (sfClock_getElapsedTime(sim->clock).microseconds >
            MS_TO_SEC / WINDOW_FPS_LIMIT) {
            sfClock_restart(sim->clock);
            sfRenderWindow_clear(sim->screen->window, sfBlack);
            render_world(sim);
            sfRenderWindow_display(sim->screen->window);
        }
    }
    return EXIT_SUCCESS;
}

static void destroy_simulation(simulation_t *sim)
{
    sfRenderWindow_destroy(sim->screen->window);
    sfSprite_destroy(sim->world->background_sprite);
    sfTexture_destroy(sim->world->background_texture);
    for (uint i = 0; i < sim->world->towers_count; i++)
        destroy_tower(sim->world->towers[i]);
    sfClock_destroy(sim->clock);
    free(sim->world->towers);
    free(sim->screen);
}

int run_simulation(void)
{
    simulation_t simulation;

    simulation.screen = create_sim_screen(DEFAULT_WINDOW_WIDTH,
        DEFAULT_WINDOW_HEIGHT);
    if (simulation.screen == NULL)
        return EXIT_FAILURE;
    simulation.world = create_world();
    if (simulation.world == NULL)
        return EXIT_FAILURE;
    if (run_simulation_loop(&simulation) == EXIT_FAILURE)
        return EXIT_FAILURE;
    destroy_simulation(&simulation);
    return EXIT_SUCCESS;
}
