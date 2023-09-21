/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** player
*/

#include "server.h"

void destroy_player_command(player_t *player)
{
    if (!player || !player->command)
        return;
    free_arr(player->command->args);
    player->command = player->command->next;
}

void destroy_player(player_t *player)
{
    if (!player)
        return;
    destroy_player_command(player);
    free(player->command);
    if (player->team_name)
        free(player->team_name);
    free(player);
}
