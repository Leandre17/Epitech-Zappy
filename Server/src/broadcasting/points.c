/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** points
*/

#include "server.h"

point_t get_point_in_front_of_player_2(player_t *player)
{
    if (!player)
        exit_error("get_point_in_front_of_player_2()");
    if (player->orientation == SOUTH)
        return (point_t){
            player->pos_x, player->pos_y + 1
        };
    if (player->orientation == WEST)
        return (point_t){
            player->pos_x - 1, player->pos_y
        };
    return (point_t){
        0, 0
    };
}

point_t get_point_in_front_of_player(player_t *player)
{
    if (!player)
        exit_error("get_point_in_front_of_player()");
    if (player->orientation == NORTH)
        return (point_t){
            player->pos_x, player->pos_y - 1
        };
    if (player->orientation == EAST)
        return (point_t){
            player->pos_x + 1, player->pos_y
        };
    return get_point_in_front_of_player_2(player);
}

point_t *get_all_theorical_player_points(
    map_t *map,
    player_t *src,
    player_t *dest
)
{
    point_t *points = NULL;
    int width = 0;
    int height = 0;

    if (!map || !src || !dest)
        exit_error("closest_theorical_player_point()");
    if (!(points = malloc(sizeof(point_t) * 9)))
        exit_error("malloc()");
    width = map->width;
    height = map->height;
    points[0] = (point_t){dest->pos_x - width, dest->pos_y - height};
    points[1] = (point_t){dest->pos_x, dest->pos_y - height};
    points[2] = (point_t){dest->pos_x + width, dest->pos_y - height};
    points[3] = (point_t){dest->pos_x - width, dest->pos_y};
    points[4] = (point_t){dest->pos_x, dest->pos_y};
    points[5] = (point_t){dest->pos_x + width, dest->pos_y};
    points[6] = (point_t){dest->pos_x - width, dest->pos_y + height};
    points[7] = (point_t){dest->pos_x, dest->pos_y + height};
    points[8] = (point_t){dest->pos_x + width, dest->pos_y + height};
    return points;
}

double get_distance_between_points(point_t p1, point_t p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

point_t get_closest_theorical_player_point(
    map_t *map,
    player_t *src,
    player_t *dest
)
{
    point_t *points = NULL;
    int distance = 10000000;
    int closest_distance = 10000000;
    point_t closest = {.x = 1000000, .y = 1000000};
    point_t player_point = {.x = 0, .y = 0};

    if (!map || !src || !dest)
        exit_error("closest_theorical_player_point()");
    points = get_all_theorical_player_points(map, src, dest);
    player_point.x = src->pos_x;
    player_point.y = src->pos_y;
    for (int i = 0; i < 9; i += 1) {
        distance = get_distance_between_points(points[i], player_point);
        if (distance < closest_distance) {
            closest_distance = distance;
            closest = points[i];
        }
    }
    free(points);
    return closest;
}
