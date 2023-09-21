/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** sst
*/

#include "server.h"

void command_sst(
    server_t *server,
    client_t *client,
    char **args
)
{
    int freq = 0;
    char *output = NULL;

    if (!server || !client || !args || !server->map || !server->map->tiles)
        exit_error("command_sst()");
    if (arrlen(args) != 2)
        return send_to_user(client, API_GRAPHIC_INVALID_PARAMETER);
    freq = getnbr(args[1]);
    if (freq < 2 || freq > 10000)
        return send_to_user(client, API_GRAPHIC_INVALID_PARAMETER);
    server->freq = (float)freq;
    output = msprintf("sgt %d\n", freq);
    send_to_all_graphics(server, output);
    free(output);
}
