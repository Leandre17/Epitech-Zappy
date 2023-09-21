/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** connection
*/

#include "server.h"

int accept_connection(int sockfd)
{
    int fd = 0;
    struct sockaddr_in adr = {0};
    socklen_t adr_len = sizeof(adr);
    char *ip = NULL;
    int port = 0;

    if ((fd = accept(sockfd, (struct sockaddr *)&adr, &adr_len)) < 0)
        exit_error("accept()");
    if (!(ip = inet_ntoa(adr.sin_addr)))
        exit_error("inet_ntoa()");
    port = ntohs(adr.sin_port);
    printf("Client connected from %s:%d\n", ip, port);
    return fd;
}

void accept_new_connection(server_t *server, int *max_fd)
{
    int client_sockfd = 0;

    if (!server)
        return;
    client_sockfd = accept_connection(server->sockfd);
    if (server->nb_clients == MAX_CLIENTS) {
        close_socket(client_sockfd);
        printf("Client refused: too many clients\n");
        return;
    }
    server->clients[server->nb_clients].sockfd = client_sockfd;
    server->clients[server->nb_clients].is_connected = true;
    server->clients[server->nb_clients].is_graphic = false;
    server->clients[server->nb_clients].player = init_player(server);
    server->nb_clients += 1;
    if (client_sockfd > *max_fd)
        *max_fd = client_sockfd;
    send_to_user(&server->clients[server->nb_clients - 1], API_WELCOME);
}
