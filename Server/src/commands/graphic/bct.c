/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** bct
*/

#include "server.h"

void command_bct(
    server_t *server,
    client_t *client,
    char **args
)
{
    tile_t *t = NULL;

    if (!server || !client || !args || !server->map || !server->map->tiles)
        exit_error("command_bct()");
    if (arrlen(args) != 3 || check_invalid_pos(server, args[1], args[2]))
        return send_to_user(client, API_GRAPHIC_INVALID_PARAMETER);
    t = server->map->tiles[atoi(args[1])][atoi(args[2])];
    send_tile_content_to_user(client, t, atoi(args[1]), atoi(args[2]));
}
