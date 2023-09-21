/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** output
*/

#include "server.h"

void send_broadcast_output_to_all_ai(
    server_t *server,
    player_t *player,
    char *message
)
{
    char *output = NULL;

    if (!server || !player)
        exit_error("send_broadcast_output_to_all_ai()");
    for (int i = 0; i < server->nb_clients; i += 1) {
        if (server->clients[i].is_graphic || !server->clients[i].player ||
            !server->clients[i].player->team_name)
            continue;
        output = msprintf(
            "message %d, %s\n",
            get_tile_of_destination_message(
                server->map,
                player,
                server->clients[i].player
            ),
            message
        );
        send_to_user(&server->clients[i], output);
        free(output);
    }
}
