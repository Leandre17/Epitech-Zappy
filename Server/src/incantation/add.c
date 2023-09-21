/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** add
*/

#include "server.h"

int get_nb_of_players_in_tile_with_level(
    server_t *server,
    player_t *player
)
{
    int nb_players_in_tile = 0;

    if (!server || !server->map || !server->map->tiles || !player)
        return 0;
    for (int i = 0; i < server->nb_clients; i += 1) {
        if (server->clients[i].player->pos_x == player->pos_x &&
            server->clients[i].player->pos_y == player->pos_y &&
            server->clients[i].player->level == player->level)
            nb_players_in_tile += 1;
    }
    return nb_players_in_tile;
}

int *get_players_id_from_tile_with_level(
    server_t *server,
    player_t *player
)
{
    int *players_id = NULL;
    int nb_players_in_tile = 0;
    int j = 0;

    if (!server || !server->map || !server->map->tiles || !player)
        return NULL;
    nb_players_in_tile = get_nb_of_players_in_tile_with_level(server, player);
    if (!(players_id = malloc(sizeof(int) * (nb_players_in_tile + 1))))
        return NULL;
    for (int i = 0; i < server->nb_clients; i += 1) {
        if (server->clients[i].player->pos_x == player->pos_x &&
            server->clients[i].player->pos_y == player->pos_y &&
            server->clients[i].player->level == player->level) {
            players_id[j] = server->clients[i].player->id;
            j += 1;
        }
    }
    players_id[j] = -1;
    return players_id;
}

incantation_t *create_incantation(
    server_t *server,
    player_t *player
)
{
    incantation_t *incantation = NULL;

    if (!server || !player)
        exit_error("create_incantation()");
    if (!(incantation = malloc(sizeof(incantation_t))))
        return NULL;
    incantation->players_id = get_players_id_from_tile_with_level(
        server,
        player
    );
    incantation->pos_x = player->pos_x;
    incantation->pos_y = player->pos_y;
    incantation->level = player->level;
    incantation->start_time = get_current_time_in_ms();
    incantation->next = NULL;
    return incantation;
}

void add_incantation_to_end(
    map_t *map,
    incantation_t *new
)
{
    incantation_t *tmp = NULL;

    if (!map || !new)
        return;
    if (!map->incantation) {
        map->incantation = new;
        return;
    }
    tmp = map->incantation;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void add_incantation(server_t *server, player_t *player)
{
    incantation_t *incantation = NULL;

    if (!server || !server->map)
        exit_error("create_incantation()");
    if (!(incantation = create_incantation(server, player)))
        exit_error("create_incantation()");
    add_incantation_to_end(server->map, incantation);
    set_all_players_in_incantation_unavailable(server, incantation);
    send_to_all_players_in_incantation(server, incantation,
        "Elevation underway\n");
    send_pic_to_all_graphics(server, incantation);
}
