/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** config
*/

#include "server.h"

void destroy_config(config_t *config)
{
    if (!config)
        return;
    free_arr(config->team_names);
    free(config);
}
