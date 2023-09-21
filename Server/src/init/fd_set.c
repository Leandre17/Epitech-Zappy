/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** fd_set
*/

#include "server.h"

void init_fd_set(server_t *server, fd_set *read_fds)
{
    FD_ZERO(read_fds);
    FD_SET(server->sockfd, read_fds);
    for (int i = 0; i < server->nb_clients; i += 1)
        FD_SET(server->clients[i].sockfd, read_fds);
}
