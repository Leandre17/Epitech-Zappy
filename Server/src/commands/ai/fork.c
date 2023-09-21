/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** fork
*/

#include "server.h"

void command_fork(
    server_t *server,
    client_t *client,
    char **args
)
{
    if (!server || !client || !client->player || !args)
        exit_error("command_fork()");
    if (arrlen(args) != 1)
        return send_to_user(client, API_NOT_FOUND);
    add_egg(server, client->player);
}
