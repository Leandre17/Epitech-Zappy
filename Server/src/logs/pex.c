/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** pex
*/

#include "server.h"

void send_pex_to_all_graphics(
    server_t *server,
    int player_id
)
{
    char *output = NULL;

    if (!server)
        exit_error("send_pex_to_all_graphics()");
    output = msprintf(
        "pex %d\n",
        player_id
    );
    send_to_all_graphics(server, output);
    free(output);
}
