/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** requirements
*/

#include "server.h"

bool are_players_requirements_met(
    server_t *server,
    int pos_x,
    int pos_y,
    int level
)
{
    int required_players = 1;

    if (!server)
        exit_error("are_players_requirements_met()");
    if (level == 2 || level == 3)
        required_players = 2;
    if (level == 4 || level == 5)
        required_players = 4;
    if (level == 6 || level == 7)
        required_players = 6;
    for (int i = 0; i < server->nb_clients; i += 1) {
        if (server->clients[i].player->pos_x == pos_x &&
            server->clients[i].player->pos_y == pos_y &&
            server->clients[i].player->level == level)
            required_players--;
    }
    return required_players <= 0;
}

bool are_resources_requirements_met(tile_t *tile, int level)
{
    int linemate[7] = {1, 1, 2, 1, 1, 2, 2};
    int deraumere[7] = {0, 1, 0, 1, 2, 2, 2};
    int sibur[7] = {0, 1, 1, 2, 1, 3, 2};
    int mendiane[7] = {0, 0, 0, 0, 3, 0, 2};
    int phiras[7] = {0, 0, 2, 1, 0, 1, 2};
    int thystame[7] = {0, 0, 0, 0, 0, 0, 1};

    if (!tile)
        exit_error("are_requirements_requirements_met()");
    return !(
        tile->linemate < linemate[level - 1] ||
        tile->deraumere < deraumere[level - 1] ||
        tile->sibur < sibur[level - 1] ||
        tile->mendiane < mendiane[level - 1] ||
        tile->phiras < phiras[level - 1] ||
        tile->thystame < thystame[level - 1]
    );
}

bool are_incantation_requirements_met(server_t *server, player_t *player)
{
    tile_t *tile = NULL;

    if (!server || !player || !server->map || !server->map->tiles)
        exit_error("are_incantation_requirements_met()");
    if (!are_players_requirements_met(server, player->pos_x, player->pos_y,
        player->level))
        return false;
    tile = server->map->tiles[player->pos_y][player->pos_x];
    if (!are_resources_requirements_met(tile, player->level))
        return false;
    return true;
}
