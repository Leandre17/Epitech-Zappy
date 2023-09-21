/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** players
*/

#include "server.h"

void send_player_dies(server_t *server, client_t *client)
{
    char *output = NULL;

    if (!server || !client)
        exit_error("send_player_dies()");
    output = msprintf("pdi %d\n", client->player->id);
    send_to_all_graphics(server, output);
    free(output);
    send_to_user(client, "dead\n");
    client->is_connected = false;
}

void handle_players(server_t *server)
{
    player_t *player = NULL;
    long long current_time = 0;

    if (!server)
        exit_error("handle_players()");
    if (!server->nb_clients || !server->clients)
        return;
    for (int i = 0; i < server->nb_clients; i += 1) {
        player = server->clients[i].player;
        if (!player->team_name)
            break;
        current_time = get_current_time_in_ms();
        if ((current_time - player->food_time) / 1000 >= 126 / server->freq) {
            player->inventory->food -= 1;
            player->food_time = current_time;
        }
        if (player->inventory->food < 0)
            send_player_dies(server, &server->clients[i]);
    }
}
