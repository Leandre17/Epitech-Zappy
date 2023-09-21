/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** angles
*/

#include "server.h"

double get_angle_of_destination_message(
    map_t *map,
    player_t *src,
    player_t *dest
)
{
    point_t src_point = {0, 0};
    point_t src_front_point = {0, 0};
    point_t dest_point = {0, 0};

    if (!map || !src || !dest)
        exit_error("get_angle_of_destination_message()");
    src_point = (point_t){src->pos_x, src->pos_y};
    src_front_point = get_point_in_front_of_player(src);
    dest_point = get_closest_theorical_player_point(map, src, dest);
    return calculate_angle(src_front_point, src_point, dest_point);
}
