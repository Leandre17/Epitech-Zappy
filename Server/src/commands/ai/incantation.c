/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** incantation
*/

#include "server.h"

void command_incantation(
    server_t *server,
    client_t *client,
    char **args
)
{
    if (!server || !client || !client->player || !args)
        exit_error("command_incantation()");
    if (arrlen(args) != 1)
        return send_to_user(client, API_NOT_FOUND);
    if (!are_incantation_requirements_met(server, client->player))
        return send_to_user(client, API_NOT_FOUND);
    add_incantation(server, client->player);
}
