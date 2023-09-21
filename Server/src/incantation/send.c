/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** send
*/

#include "server.h"

client_t *get_client_from_player_id(server_t *server, int player_id)
{
    if (!server || !server->clients)
        return NULL;
    for (int i = 0; i < server->nb_clients; i += 1) {
        if (server->clients[i].player->id == player_id)
            return &server->clients[i];
    }
    return NULL;
}

void send_to_all_players_in_incantation(
    server_t *server,
    incantation_t *incantation,
    char *buffer
)
{
    if (!server || !incantation || !buffer)
        return;
    for (int i = 0; incantation->players_id[i] != -1; i += 1) {
        send_to_user(get_client_from_player_id(server,
            incantation->players_id[i]), buffer);
    }
}
