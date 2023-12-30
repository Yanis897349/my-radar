/*
** EPITECH PROJECT, 2023
** My Radar
** File description:
** Simulation entry point
*/

#include "Simulation/simulation.h"
#include "Simulation/aircraft.h"
#include "Simulation/tower.h"
#include "Simulation/world.h"
#include "Screen/screen.h"
#include "Events/event_handler.h"
#include <SFML/Graphics/RenderWindow.h>
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
    destroy_world(sim->world);
    destroy_screen(sim->screen);
    sfClock_destroy(sim->clock);
}

int run_simulation(tower_t **towers, aircraft_t **aircrafts)
{
    simulation_t simulation;

    simulation.screen = create_sim_screen(DEFAULT_WINDOW_WIDTH,
        DEFAULT_WINDOW_HEIGHT);
    if (simulation.screen == NULL)
        return EXIT_FAILURE;
    simulation.world = create_world(towers, aircrafts);
    if (simulation.world == NULL)
        return EXIT_FAILURE;
    simulation.clock = sfClock_create();
    if (simulation.clock == NULL)
        return EXIT_FAILURE;
    if (run_simulation_loop(&simulation) == EXIT_FAILURE)
        return EXIT_FAILURE;
    destroy_simulation(&simulation);
    return EXIT_SUCCESS;
}
