/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** tile
*/

#include "server.h"

static double ANGLES[8][2] = {
    { 67.5,   112.5 },
    { 112.5,  157.5 },
    { 157.5,  202.5 },
    { 202.5,  247.5 },
    { 247.5,  292.5 },
    { 292.5,  337.5 },
    { 337.5,  22.5  },
    { 22.5,   67.5  }
};

int get_tile_of_destination_message(
    map_t *map,
    player_t *src,
    player_t *dest
)
{
    double angle = 0.0;

    if (!map || !src || !dest)
        exit_error("get_tile_if_of_destination_message()");
    if (src->pos_x == dest->pos_x && src->pos_y == dest->pos_y)
        return 0;
    angle = get_angle_of_destination_message(map, src, dest);
    angle += dest->orientation * 90;
    for (int i = 0; i < 8; i += 1)
        if (angle >= ANGLES[i][0] && angle < ANGLES[i][1])
            return i + 1;
    return 0;
}
