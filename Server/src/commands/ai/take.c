/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** take
*/

#include "server.h"

void send_take_output_to_all_graphics(
    server_t *server,
    client_t *client,
    int pos[2],
    char *resource
)
{
    int resource_id = -1;

    if (!server || !client)
        exit_error("send_set_output_to_all_graphics()");
    if ((resource_id = get_resource_id(resource)) == -1)
        exit_error("send_set_output_to_all_graphics(): invalid_resource");
    send_pgt_to_all_graphics(server, client->player, resource_id);
    send_pin_to_all_graphics(server, client->player);
    send_bct_to_all_graphics(server, pos[0], pos[1]);
}

void command_take(
    server_t *server,
    client_t *client,
    char **args
)
{
    int pos[2] = {};

    if (!server || !server->map || !server->map->tiles ||
        !client || !client->player || !args)
        exit_error("command_take()");
    if (arrlen(args) != 2)
        return send_to_user(client, API_NOT_FOUND);
    pos[0] = client->player->pos_x;
    pos[1] = client->player->pos_y;
    if (!take_resource(server->map->tiles, client->player->inventory,
        pos, args[1]))
        return send_to_user(client, API_NOT_FOUND);
    send_take_output_to_all_graphics(server, client, pos, args[1]);
    send_to_user(client, API_SUCCESS);
}
