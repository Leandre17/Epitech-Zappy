/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** init
*/

#include "server.h"

int find_available_port(void)
{
    int port = 65535;
    int sock = 0;
    struct sockaddr_in sin = {0};
    socklen_t len = sizeof(sin);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    while (port > 0) {
        sin.sin_port = htons(port);
        if (bind(sock, (struct sockaddr *)&sin, len) == 0)
            break;
        port -= 1;
    }
    close(sock);
    return port;
}

client_t *init_clients(void)
{
    client_t *clients = malloc(sizeof(client_t) * MAX_CLIENTS);

    return clients;
}

server_t *init_server(config_t *config)
{
    int sockfd = -1;
    server_t *server = NULL;

    if (!config)
        exit_error("init_server()");
    if (listen((sockfd = init_socket(config->port)), BACKLOG_SIZE) < 0)
        exit_error("listen()");
    if (!(server = malloc(sizeof(server_t)))) {
        close_socket(sockfd);
        exit_error("malloc()");
    }
    server->sockfd = sockfd;
    server->port = config->port;
    server->freq = config->freq;
    server->nb_clients = 0;
    server->global_egg_id = 0;
    server->clients = init_clients();
    server->teams = init_teams(config);
    server->map = init_map(config);
    return server;
}
