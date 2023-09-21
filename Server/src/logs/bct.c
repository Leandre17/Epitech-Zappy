/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** bct
*/

#include "server.h"

void send_bct_to_all_graphics(
    server_t *server,
    int x,
    int y
)
{
    char *output = NULL;

    if (!server || !server->map || !server->map->tiles ||
        !server->map->tiles[y] || !server->map->tiles[y][x])
        exit_error("send_bct_to_all_graphics()");
    output = msprintf(
        "bct %d %d %d %d %d %d %d %d %d\n",
        x,
        y,
        server->map->tiles[y][x]->food,
        server->map->tiles[y][x]->linemate,
        server->map->tiles[y][x]->deraumere,
        server->map->tiles[y][x]->sibur,
        server->map->tiles[y][x]->mendiane,
        server->map->tiles[y][x]->phiras,
        server->map->tiles[y][x]->thystame
    );
    send_to_all_graphics(server, output);
    free(output);
}
