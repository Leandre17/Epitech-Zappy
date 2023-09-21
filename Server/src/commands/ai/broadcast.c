/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** broadcast
*/

#include "server.h"

char *get_message_from_args(char **args)
{
    char *message = NULL;
    char *tmp = NULL;

    if (!args || arrlen(args) < 2)
        return NULL;
    for (int i = 1; args[i] != NULL; i++) {
        tmp = strdup(args[i]);
        if (!message)
            message = strdup(tmp);
        else
            message = msprintf("%s %s", message, tmp);
        free(tmp);
    }
    return message;
}

void command_broadcast(
    server_t *server,
    client_t *client,
    char **args
)
{
    char *message = NULL;

    if (!server || !client || !client->player || !args)
        exit_error("command_broadcast()");
    if (arrlen(args) < 2)
        return send_to_user(client, API_NOT_FOUND);
    if (!(message = get_message_from_args(args)))
        return;
    send_to_user(client, API_SUCCESS);
    send_pbc_to_all_graphics(server, client->player, message);
    send_broadcast_output_to_all_ai(server, client->player, message);
    free(message);
}
