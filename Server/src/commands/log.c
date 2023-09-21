/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** log
*/

#include "server.h"

void log_received_command(client_t *client, char **params)
{
    char *message = NULL;

    if (!client || !params)
        exit_error("log_received_command()");
    if (client->is_graphic)
        printf("%sGraphic client %d send command \"%s\".\n",
            SEPARATOR, client->sockfd, params[0]);
    else
        printf("%sAI %d send command \"%s\".\n",
            SEPARATOR, client->sockfd, params[0]);
    if (arrlen(params) > 1) {
        message = msprintf("\t-with params: ");
        for (int i = 1; params[i]; i++)
            message = msprintf("%s%s ", message, params[i]);
        printf("%s\n", message);
        free(message);
    }
}
