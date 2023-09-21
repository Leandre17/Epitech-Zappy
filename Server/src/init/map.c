/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** map
*/

#include "server.h"

tile_t *init_tile(config_t *config)
{
    tile_t *tile = NULL;

    if (!config)
        exit_error("init_tile()");
    if (!(tile = malloc(sizeof(tile_t))))
        exit_error("malloc()");
    tile->food = 0;
    tile->linemate = 0;
    tile->deraumere = 0;
    tile->sibur = 0;
    tile->mendiane = 0;
    tile->phiras = 0;
    tile->thystame = 0;
    return tile;
}

tile_t ***init_tiles(config_t *config)
{
    tile_t ***tiles = NULL;

    if (!config)
        exit_error("init_tiles()");
    if (!(tiles = malloc(sizeof(tile_t **) * (config->height + 1))))
        exit_error("malloc()");
    for (int y = 0; y < config->height; y += 1) {
        if (!(tiles[y] = malloc(sizeof(tile_t *) * (config->width + 1))))
            exit_error("malloc()");
        for (int x = 0; x < config->width; x += 1)
            tiles[y][x] = init_tile(config);
        tiles[y][config->width] = NULL;
    }
    tiles[config->height] = NULL;
    return tiles;
}

map_t *init_map(config_t *config)
{
    map_t *map = NULL;

    if (!config)
        exit_error("init_map()");
    if (!(map = malloc(sizeof(map_t))))
        exit_error("malloc()");
    map->width = config->width;
    map->height = config->height;
    map->resources_time = get_current_time_in_ms();
    map->tiles = init_tiles(config);
    fill_tiles(map->width, map->height, map->tiles);
    map->egg = NULL;
    map->incantation = NULL;
    return map;
}
