/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** enw
*/

#include "server.h"

void send_enw_to_all_graphics(
    server_t *server,
    egg_t *egg
)
{
    char *output = NULL;

    if (!server || !egg)
        exit_error("send_enw_to_all_graphics()");
    output = msprintf(
        "enw %d %d %d %d\n",
        egg->id,
        egg->player_id,
        egg->pos_x,
        egg->pos_y
    );
    send_to_all_graphics(server, output);
    free(output);
}
