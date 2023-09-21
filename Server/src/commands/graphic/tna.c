/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** tna
*/

#include "server.h"

char *tna_str(team_t **teams)
{
    char *output = NULL;
    char *tmp = NULL;

    for (int i = 0; teams[i]; i += 1) {
        tmp = msprintf("tna %s\n", teams[i]->name);
        if (!output)
            output = strdup(tmp);
        else
            output = msprintf("%s%s", output, tmp);
        free(tmp);
    }
    return output;
}

void command_tna(
    server_t *server,
    client_t *client,
    char **args
)
{
    char *output = NULL;

    if (!server || !client || !args || !server->map)
        exit_error("command_tna()");
    if (arrlen(args) != 1)
        return send_to_user(client, API_GRAPHIC_INVALID_PARAMETER);
    output = tna_str(server->teams);
    send_to_user(client, output);
    free(output);
}
