/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** pie
*/

#include "server.h"

void send_pie_to_all_graphics(
    server_t *server,
    incantation_t *incantation,
    bool result
)
{
    char *output = NULL;

    if (!server || !incantation)
        exit_error("send_pdi_to_all_graphics()");
    output = msprintf(
        "pie %d %d %b\n",
        incantation->pos_x,
        incantation->pos_y,
        result
    );
    send_to_all_graphics(server, output);
    free(output);
}
