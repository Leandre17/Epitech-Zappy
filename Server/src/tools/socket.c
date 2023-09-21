/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** socket
*/

#include "server.h"

int init_socket(int port)
{
    int sockfd = 0;
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        exit_error("soket()");
    }
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        close_socket(sockfd);
        exit_error("bind()");
    }
    printf("Server listening on port %d\n", port);
    return sockfd;
}

void close_socket(int sockfd)
{
    if (close(sockfd) < 0)
        exit_error("close()");
}
