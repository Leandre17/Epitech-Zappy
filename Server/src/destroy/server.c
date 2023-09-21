/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** server
*/

#include "server.h"

void destroy_server(server_t *server)
{
    if (!server)
        return;
    destroy_map(server->map);
    destroy_teams(server->teams);
    if (server->sockfd != -1)
        close_socket(server->sockfd);
    free(server);
}
