/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** connect_nbr
*/

#include "server.h"

void command_connect_nbr(
    server_t *server,
    client_t *client,
    char **args
)
{
    char *output = NULL;

    if (!server || !client || !args)
        exit_error("command_connect_nbr()");
    if (arrlen(args) != 1)
        return send_to_user(client, API_NOT_FOUND);
    for (int i = 0; server->teams[i] != NULL; i++) {
        if (!strcmp(server->teams[i]->name, client->player->team_name)) {
            output = msprintf("%d\n", server->teams[i]->free_slots);
            send_to_user(client, output);
            free(output);
            return;
        }
    }
}
