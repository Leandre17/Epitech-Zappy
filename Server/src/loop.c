/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** loop
*/

#include "server.h"
#include <fcntl.h>
#include <assert.h>
#include <time.h>

void connection_loop(server_t *server)
{
    int max_fd = server->sockfd;
    fd_set read_fds;
    fd_set write_fds;
    struct timeval tv = {.tv_sec = 0, .tv_usec = 10000};

    while (!server->is_ended) {
        init_fd_set(server, &read_fds);
        if (select(max_fd + 1, &read_fds, &write_fds, NULL, &tv) < 0)
            exit_error("select()");
        if (FD_ISSET(server->sockfd, &read_fds))
            accept_new_connection(server, &max_fd);
        handle_clients(server, read_fds);
        handle_commands(server);
        handle_players(server);
        handle_resources(server);
        handle_incantations(server);
        handle_eggs(server);
        handle_win(server);
        remove_disconnected_clients(server);
    }
}
