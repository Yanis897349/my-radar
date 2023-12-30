/*
** EPITECH PROJECT, 2023
** my-radar [WSL: Ubuntu]
** File description:
** quadtree
*/

#include "Simulation/quadtree.h"
#include "Simulation/aircraft.h"
#include "Simulation/world.h"
#include "include/my_std.h"
#include <stdlib.h>
#include <sys/types.h>

static void subdivide_corner(corner_t *corner)
{
    int sub_width = corner->bounds.width / 2;
    int sub_height = corner->bounds.height / 2;
    int_rect_t bounds;

    for (uint i = 0; i < 4; i++) {
        bounds.left = corner->bounds.left + (i % 2) * sub_width;
        bounds.top = corner->bounds.top + (i / 2) * sub_height;
        bounds.width = sub_width;
        bounds.height = sub_height;
        corner->corners[i] = create_corner(bounds);
    }
}

static int is_aircraft_in_bounds(aircraft_t *aircraft, int_rect_t bounds)
{
    sfVector2f aircraft_pos = aircraft->position;

    if (aircraft_pos.x >= bounds.left && aircraft_pos.x <= bounds.left +
        bounds.width && aircraft_pos.y >= bounds.top && aircraft_pos.y <=
        bounds.top + bounds.height)
        return 1;
    return 0;
}

static void add_aircraft_to_corner(corner_t *corner, aircraft_t *aircraft)
{
    int old_aircrafts_size = corner->aircrafts_count * sizeof(aircraft_t *);
    int new_aircrafts_size = old_aircrafts_size + sizeof(aircraft_t *);

    corner->aircrafts = my_realloc(corner->aircrafts, old_aircrafts_size,
        new_aircrafts_size);
    if (corner->aircrafts == NULL)
        return;
    corner->aircrafts[corner->aircrafts_count] = aircraft;
    corner->aircrafts_count++;
}

static int dispatch_aircraft_to_sub_corners_if_in_bounds(aircraft_t *aircraft,
    corner_t *corner)
{
    for (uint i = 0; i < 4; i++) {
        if (is_aircraft_in_bounds(aircraft, corner->corners[i]->bounds)) {
            dispatch_aircraft_to_corner(corner->corners[i], aircraft);
            return 1;
        }
    }
    return 0;
}

void dispatch_aircraft_to_corner(corner_t *corner, aircraft_t *aircraft)
{
    aircraft_t *aircraft_in_corner = NULL;

    if (corner->corners[0] != NULL) {
        if (dispatch_aircraft_to_sub_corners_if_in_bounds(aircraft, corner))
            return;
    }
    add_aircraft_to_corner(corner, aircraft);
    if (corner->aircrafts_count > CORNER_DIVISION_THRESHOLD) {
        subdivide_corner(corner);
        for (uint i = 0; i < corner->aircrafts_count; i++) {
            aircraft_in_corner = corner->aircrafts[i];
            dispatch_aircraft_to_sub_corners_if_in_bounds(aircraft_in_corner,
                corner);
        }
        free(corner->aircrafts);
        corner->aircrafts = NULL;
        corner->aircrafts_count = 0;
    }
}

static void dispatch_aircraft_to_corner_if_in_bounds(aircraft_t *aircraft,
    world_t *world)
{
    for (uint j = 0; j < 4; j++) {
        if (is_aircraft_in_bounds(aircraft, world->corners[j]->bounds)) {
            dispatch_aircraft_to_corner(world->corners[j], aircraft);
            break;
        }
    }
}

corner_t *create_corner(int_rect_t bounds)
{
    corner_t *corner = malloc(sizeof(corner_t));

    if (corner == NULL)
        return NULL;
    corner->bounds = bounds;
    corner->aircrafts = NULL;
    corner->aircrafts_count = 0;
    for (uint i = 0; i < 4; i++)
        corner->corners[i] = NULL;
    return corner;
}

void destroy_corner(corner_t *corner)
{
    for (uint i = 0; i < corner->aircrafts_count; i++)
        destroy_aircraft(corner->aircrafts[i]);
    free(corner->aircrafts);
    for (uint i = 0; corner->corners[i] != NULL; i++)
        destroy_corner(corner->corners[i]);
    free(corner->corners);
    free(corner);
}

void dispatch_aircrafts(world_t *world, aircraft_t **aircrafts,
    unsigned int aircrafts_count)
{
    aircraft_t *aircraft = NULL;

    for (unsigned int i = 0; i < aircrafts_count; i++) {
        aircraft = aircrafts[i];
        dispatch_aircraft_to_corner_if_in_bounds(aircraft, world);
    }
}
