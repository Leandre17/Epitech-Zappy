/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** add
*/

#include "server.h"

egg_t *create_egg(
    server_t *server,
    player_t *player
)
{
    egg_t *egg = NULL;

    if (!server || !player)
        exit_error("create_egg()");
    if (!(egg = malloc(sizeof(egg_t))))
        return NULL;
    egg->id = server->global_egg_id;
    server->global_egg_id += 1;
    egg->player_id = player->id;
    egg->team_name = strdup(player->team_name);
    egg->pos_x = player->pos_x;
    egg->pos_y = player->pos_y;
    egg->is_layed = false;
    egg->lay_start_time = get_current_time_in_ms();
    egg->next = NULL;
    return egg;
}

void add_egg_to_end(
    map_t *map,
    egg_t *new
)
{
    egg_t *tmp = NULL;

    if (!map || !new)
        return;
    if (!map->egg) {
        map->egg = new;
        return;
    }
    tmp = map->egg;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void add_egg(server_t *server, player_t *player)
{
    egg_t *egg = NULL;

    if (!server || !server->map)
        exit_error("create_egg()");
    if (!(egg = create_egg(server, player)))
        exit_error("create_egg()");
    add_egg_to_end(server->map, egg);
    send_pfk_to_all_graphics(server, player);
}
