/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** pbc
*/

#include "server.h"

void send_pbc_to_all_graphics(
    server_t *server,
    player_t *player,
    char *message
)
{
    char *output = NULL;

    if (!server || !player)
        exit_error("send_pbc_to_all_graphics()");
    output = msprintf(
        "pbc %d %s\n",
        player->id,
        message
    );
    send_to_all_graphics(server, output);
    free(output);
}
