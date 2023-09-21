/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** msz
*/

#include "server.h"

char *msz_str(map_t *map)
{
    char *output = "";

    if (!map)
        return output;
    output = msprintf("msz %d %d\n", map->width, map->height);
    return output;
}

void command_msz(
    server_t *server,
    client_t *client,
    char **args
)
{
    char *output = NULL;

    if (!server || !client || !args || !server->map)
        exit_error("command_msz()");
    if (arrlen(args) != 1)
        return send_to_user(client, API_GRAPHIC_INVALID_PARAMETER);
    output = msz_str(server->map);
    send_to_user(client, output);
    free(output);
}
