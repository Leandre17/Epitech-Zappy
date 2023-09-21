/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** ppo
*/

#include "server.h"

void send_ppo_to_all_graphics(
    server_t *server,
    player_t *player
)
{
    char *output = NULL;

    if (!server || !player)
        exit_error("send_ppo_to_all_graphics()");
    output = msprintf(
        "ppo %d %d %d %d\n",
        player->id,
        player->pos_x,
        player->pos_y,
        player->orientation
    );
    send_to_all_graphics(server, output);
    free(output);
}
