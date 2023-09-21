/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** resources2
*/

#include "server.h"

int get_resource_id(char *resource)
{
    char *resources[] = {
        "food",
        "linemate",
        "deraumere",
        "sibur",
        "mendiane",
        "phiras",
        "thystame",
        NULL
    };

    for (int i = 0; resources[i] != NULL; i++)
        if (!strcmp(resources[i], resource))
            return i;
    return -1;
}

void handle_resources(server_t *server)
{
    long long current_time = get_current_time_in_ms();
    long long resources_offset = 0;

    if (!server)
        exit_error("handle_players()");
    if (!server->map || !server->map->tiles)
        return;
    resources_offset = (current_time - server->map->resources_time) / 1000;
    if (resources_offset >= 20 / server->freq) {
        server->map->resources_time = current_time;
        fill_tiles(
            server->map->width,
            server->map->height,
            server->map->tiles
        );
    }
}
