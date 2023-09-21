/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** update_players
*/

#include "server.h"

void set_all_players_in_incantation_unavailable(
    server_t *server,
    incantation_t *incantation
)
{
    if (!server || !incantation)
        exit_error("set_all_players_in_incantation_unavailable()");
    for (int i = 0; incantation->players_id[i] != -1; i += 1) {
        if (!server->clients[incantation->players_id[i]].player)
            continue;
        server->clients[
            incantation->players_id[i]
        ].player->is_available = false;
    }
}
