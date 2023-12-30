/*
** EPITECH PROJECT, 2023
** my-radar [WSL: Ubuntu]
** File description:
** quadtreeD
*/

#pragma once
#include "Simulation/aircraft.h"
#define CORNER_DIVISION_THRESHOLD 10

typedef struct world_s world_t;
typedef struct simulation_s simulation_t;

typedef struct int_rect_s {
    int top;
    int left;
    int width;
    int height;
} int_rect_t;

typedef struct corner_s {
    int_rect_t bounds;
    aircraft_t **aircrafts;
    unsigned int aircrafts_count;
    struct corner_s *corners[4];
} corner_t;

void render_aircrafts(simulation_t *sim, corner_t *corner);
void dispatch_aircraft_to_corner(corner_t *corner, aircraft_t *aircraft);
corner_t *create_corner(int_rect_t bounds);
void destroy_corner(corner_t *corner);
void dispatch_aircrafts(world_t *world, aircraft_t **aircrafts,
    unsigned int aircrafts_count);
