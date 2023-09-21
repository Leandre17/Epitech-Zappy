/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** pin
*/

#include "server.h"

void send_pin_to_all_graphics(
    server_t *server,
    player_t *player
)
{
    char *output = NULL;

    if (!server || !player || !player->inventory)
        exit_error("send_pin_to_all_graphics()");
    output = msprintf(
        "pin %d %d %d %d %d %d %d %d %d %d\n",
        player->id,
        player->pos_x,
        player->pos_y,
        player->inventory->food,
        player->inventory->linemate,
        player->inventory->deraumere,
        player->inventory->sibur,
        player->inventory->mendiane,
        player->inventory->phiras,
        player->inventory->thystame
    );
    send_to_all_graphics(server, output);
    free(output);
}
