/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** edi
*/

#include "server.h"

void send_edi_to_all_graphics(
    server_t *server,
    int id
)
{
    char *output = NULL;

    if (!server)
        exit_error("send_edi_to_all_graphics()");
    output = msprintf(
        "edi %d\n",
        id
    );
    send_to_all_graphics(server, output);
    free(output);
}
