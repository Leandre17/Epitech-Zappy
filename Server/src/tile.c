/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** tile
*/

#include "server.h"

char *get_players_in_tile(server_t *server, int x, int y)
{
    char *content = NULL;
    char *tmp = NULL;

    if (!server || !server->nb_clients || !server->clients)
        exit_error("get_players_in_tile()");
    for (int i = 0; i < server->nb_clients; i += 1) {
        if (server->clients[i].player->pos_x != x ||
            server->clients[i].player->pos_y != y)
            continue;
        tmp = msprintf("player");
        if (!content)
            content = strdup(tmp);
        else
            content = msprintf("%s %s", content, tmp);
        free(tmp);
    }
    return content;
}

char *get_eggs_in_tile(server_t *server, int x, int y)
{
    egg_t *cur = NULL;
    char *content = NULL;
    char *tmp = NULL;

    if (!server || !server->map)
        exit_error("get_eggs_in_tile()");
    if (!(cur = server->map->egg))
        return NULL;
    for (; cur; cur = cur->next) {
        if (cur->pos_x != x || cur->pos_y != y)
            continue;
        tmp = msprintf("egg");
        if (!content)
            content = strdup(tmp);
        else
            content = msprintf("%s %s", content, tmp);
        free(tmp);
    }
    return content;
}

void append_resource_content(char **content, int nb, char *name)
{
    char *tmp = NULL;

    if (!content || !name)
        exit_error("append_resource_content()");
    for (int i = 0; i < nb; i += 1) {
        tmp = msprintf(name);
        if (!(*content))
            *content = strdup(tmp);
        else
            *content = msprintf("%s %s", *content, tmp);
        free(tmp);
    }
}

char *get_resources_in_tile(server_t *server, int x, int y)
{
    char *content = NULL;
    tile_t *tile = NULL;

    if (!server || !(tile = server->map->tiles[y][x]))
        exit_error("get_resources_in_tile()");
    append_resource_content(&content, tile->food, "food");
    append_resource_content(&content, tile->linemate, "linemate");
    append_resource_content(&content, tile->deraumere, "deraumere");
    append_resource_content(&content, tile->sibur, "sibur");
    append_resource_content(&content, tile->mendiane, "mendiane");
    append_resource_content(&content, tile->phiras, "phiras");
    append_resource_content(&content, tile->thystame, "thystame");
    return content;
}

char *get_tile_content(server_t *server, int x, int y)
{
    char *content = NULL;
    char *player_content = NULL;
    char *egg_content = NULL;
    char *resource_content = NULL;

    if (!server)
        exit_error("get_tile_content()");
    if (x < 0 || x >= server->map->width || y < 0 || y >= server->map->height)
        return "";
    player_content = get_players_in_tile(server, x, y);
    egg_content = get_eggs_in_tile(server, x, y);
    resource_content = get_resources_in_tile(server, x, y);
    content = combine_content(player_content, egg_content, resource_content);
    free_content(player_content, egg_content, resource_content);
    return content;
}
