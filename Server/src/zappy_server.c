/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** zappy_server
*/

#include "server.h"

int zappy_server(config_t *config)
{
    server_t *server = NULL;

    if (!config)
        return ERROR;
    debug_config(config);
    if (!(server = init_server(config)))
        return ERROR;
    server->is_ended = false;
    debug_map(server->map);
    connection_loop(server);
    destroy_data(server, config);
    close_socket(server->sockfd);
    return SUCCESS;
}
