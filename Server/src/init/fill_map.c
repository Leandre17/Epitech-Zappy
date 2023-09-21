/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** fill_map
*/

#include "server.h"

void append_element_2(tile_t *tile, enum elements type)
{
    switch (type) {
        case MENDIANE:
            tile->mendiane += 1;
            break;
        case PHIRAS:
            tile->phiras += 1;
            break;
        case THYSTAME:
            tile->thystame += 1;
            break;
        default:
            break;
    }
}

void append_element(tile_t *tile, enum elements type)
{
    switch (type) {
        case FOOD:
            tile->food += 1;
            break;
        case LINEMATE:
            tile->linemate += 1;
            break;
        case DERAUMERE:
            tile->deraumere += 1;
            break;
        case SIBUR:
            tile->sibur += 1;
            break;
        default:
            append_element_2(tile, type);
            break;
    }
}

void distribute_element(
    tile_t ***tiles,
    int size[2],
    int nb_elements,
    enum elements type
)
{
    int x = 0;
    int y = 0;

    if (!size)
        exit_error("distribute_element()");
    for (int i = 0; i < nb_elements; i += 1) {
        x = rand() % size[0];
        y = rand() % size[1];
        append_element(tiles[y][x], type);
    }
}

void fill_tiles(int width, int height, tile_t ***tiles)
{
    int size[2] = {width, height};
    int nb_tiles = width * height;
    int nb_food = nb_tiles * 0.5;
    int nb_linemate = nb_tiles * 0.3;
    int nb_deraumere = nb_tiles * 0.15;
    int nb_sibur = nb_tiles * 0.1;
    int nb_mendiane = nb_tiles * 0.1;
    int nb_phiras = nb_tiles * 0.08;
    int nb_thystame = nb_tiles * 0.05;

    distribute_element(tiles, size, nb_food, FOOD);
    distribute_element(tiles, size, nb_linemate, LINEMATE);
    distribute_element(tiles, size, nb_deraumere, DERAUMERE);
    distribute_element(tiles, size, nb_sibur, SIBUR);
    distribute_element(tiles, size, nb_mendiane, MENDIANE);
    distribute_element(tiles, size, nb_phiras, PHIRAS);
    distribute_element(tiles, size, nb_thystame, THYSTAME);
}
