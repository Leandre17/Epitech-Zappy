/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** forward
*/

#include "server.h"

void move_player_forward(
    server_t *s,
    player_t *player,
    enum orientations orientation
)
{
    if (!s || !s->map || !player)
        exit_error("move_player_forward()");
    if (orientation == NORTH)
        player->pos_y = (player->pos_y - 1) % s->map->height;
    if (orientation == EAST)
        player->pos_x = (player->pos_x + 1) % s->map->width;
    if (orientation == SOUTH)
        player->pos_y = (player->pos_y + 1) % s->map->height;
    if (orientation == WEST)
        player->pos_x = (player->pos_x - 1) % s->map->width;
    player->pos_x = player->pos_x < 0 ? s->map->width - 1 : player->pos_x;
    player->pos_y = player->pos_y < 0 ? s->map->height - 1 : player->pos_y;
    send_ppo_to_all_graphics(s, player);
}

void command_forward(
    server_t *server,
    client_t *client,
    char **args
)
{
    if (!server || !client || !client->player || !args)
        exit_error("command_forward()");
    if (arrlen(args) != 1)
        return send_to_user(client, API_NOT_FOUND);
    move_player_forward(server, client->player,
        client->player->orientation);
    send_to_user(client, API_SUCCESS);
}
