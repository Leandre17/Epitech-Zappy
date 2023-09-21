/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** player
*/

#include "server.h"

void set_player_position(player_t *player, int *pos)
{
    if (!player)
        return;
    player->pos_x = pos[0];
    player->pos_y = pos[1];
    free(pos);
}

inventory_t *init_player_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (!inventory)
        return (NULL);
    inventory->food = 10;
    inventory->linemate = 0;
    inventory->deraumere = 0;
    inventory->sibur = 0;
    inventory->mendiane = 0;
    inventory->phiras = 0;
    inventory->thystame = 0;
    return inventory;
}

player_t *init_player(server_t *server)
{
    player_t *player = malloc(sizeof(player_t));

    if (!server || !server->map)
        exit_error("init_player()");
    if (!player)
        return (NULL);
    player->id = server->nb_clients;
    player->team_name = NULL;
    player->pos_x = rand() % server->map->width;
    player->pos_y = rand() % server->map->height;
    player->level = 1;
    player->orientation = rand() % 4;
    player->is_available = true;
    player->food_time = get_current_time_in_ms();
    player->inventory = init_player_inventory();
    player->command = NULL;
    return player;
}
