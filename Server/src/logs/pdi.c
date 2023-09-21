/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** pdi
*/

#include "server.h"

void send_pdi_to_all_graphics(
    server_t *server,
    player_t *player
)
{
    char *output = NULL;

    if (!server || !player)
        exit_error("send_pdi_to_all_graphics()");
    output = msprintf(
        "pdi %d\n",
        player->id
    );
    send_to_all_graphics(server, output);
    free(output);
}
