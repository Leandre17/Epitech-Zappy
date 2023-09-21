/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** data
*/

#include "server.h"

void destroy_eggs(map_t *map)
{
    if (!map || !map->egg)
        return;
    while (map->egg)
        remove_egg(map);
}

void destroy_incantations(map_t *map)
{
    if (!map || !map->incantation)
        return;
    while (map->incantation)
        remove_incantation(map);
}

void destroy_tiles(tile_t ***tiles)
{
    if (!tiles)
        return;
    for (int y = 0; tiles[y]; y++) {
        for (int x = 0; tiles[y][x]; x++)
            free(tiles[y][x]);
        free(tiles[y]);
    }
    free(tiles);
}

void destroy_map(map_t *map)
{
    if (!map)
        return;
    destroy_eggs(map);
    destroy_incantations(map);
    destroy_tiles(map->tiles);
    free(map);
}
