/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** pgt
*/

#include "server.h"

void send_pgt_to_all_graphics(
    server_t *server,
    player_t *player,
    int resource_id
)
{
    char *output = NULL;

    if (!server || !player)
        exit_error("send_pgt_to_all_graphics()");
    output = msprintf(
        "pgt %d %d\n",
        player->id,
        resource_id
    );
    send_to_all_graphics(server, output);
    free(output);
}
