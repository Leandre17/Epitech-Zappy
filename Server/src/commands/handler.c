/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** handler
*/

#include "server.h"

bool is_waiting_commands(client_t *clients, int nb_clients)
{
    if (!clients || !nb_clients)
        return false;
    for (int i = 0; i < nb_clients; i += 1)
        if (clients[i].player != NULL && clients[i].player->command != NULL)
            return true;
    return false;
}

void handle_command(server_t *server, client_t *client)
{
    command_t *cmd = NULL;
    float time_elapsed = 0;

    if (!server || !client || !client->player || !client->player->command)
        exit_error("handle_commands()");
    if (!client->player->is_available)
        return;
    cmd = client->player->command;
    time_elapsed = get_current_time_in_ms() - cmd->start_time;
    if (time_elapsed / 1000 > cmd->time_limit / server->freq) {
        cmd->function(server, client, cmd->args);
        destroy_player_command(client->player);
    }
}

void handle_commands(server_t *server)
{
    if (!server || !server->clients || !server->nb_clients)
        return;
    for (int i = 0; i < server->nb_clients; i += 1)
        if (server->clients[i].player != NULL &&
            server->clients[i].player->command != NULL)
            handle_command(server, &server->clients[i]);
}
