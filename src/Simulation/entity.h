/*
** EPITECH PROJECT, 2023
** My Hunter
** File description:
** Entity management
*/

#pragma once
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Time.h>
#define DEFAULT_ENTITY_X_POS 0
#define DEFAULT_ENTITY_Y_POS 0
#define DEFAULT_ENTITY_SPRITES_WIDTH 31
#define DEFAULT_ENTITY_TEXTURE_PATH "src/assets/entity/plane.png"
#define ANIMATION_SPEED 0.03
#define MOVE_SPEED 0.003
#define MOVE_OFFSET 8
#define MS_TO_SEC 1000000.0
#define SCALE_FACTOR 4
#define MAX_SCALE_FACTOR 0.8

typedef struct entity_s {
    sfClock *anim_clock;
    sfClock *move_clock;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    sfFloatRect hitbox;
} entity_t;

void entity_set_position(entity_t *entity, sfVector2f position,
    sfRenderWindow *window);
void update_entity(entity_t *entity, sfRenderWindow *window);
void destroy_entity(entity_t *entity);
entity_t *create_entity(char *texture_path, sfRenderWindow *window);
