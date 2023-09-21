/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** data
*/

#include "server.h"

void destroy_data(server_t *server, config_t *config)
{
    destroy_server(server);
    destroy_config(config);
}
