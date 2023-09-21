/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** remove
*/

#include "server.h"

void remove_incantation(map_t *map)
{
    if (!map || !map->incantation)
        return;
    free(map->incantation->players_id);
    map->incantation->players_id = NULL;
    map->incantation = map->incantation->next;
}
