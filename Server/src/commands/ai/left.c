/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** left
*/

#include "server.h"

void command_left(
    server_t *server,
    client_t *client,
    char **args
)
{
    if (!server || !client || !client->player || !args)
        exit_error("command_left()");
    if (arrlen(args) != 1)
        return send_to_user(client, API_NOT_FOUND);
    client->player->orientation =
        (client->player->orientation - 1) % 4;
    send_to_user(client, API_SUCCESS);
    send_ppo_to_all_graphics(server, client->player);
}
