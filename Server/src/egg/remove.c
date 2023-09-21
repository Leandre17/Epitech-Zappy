/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** remove
*/

#include "server.h"

void free_egg(egg_t *egg)
{
    free(egg->team_name);
    egg->team_name = NULL;
    free(egg);
}

void remove_egg(map_t *map)
{
    if (!map || !map->egg)
        return;
    free_egg(map->egg);
}

void remove_egg_by_id(server_t *server, int id)
{
    egg_t *egg = NULL;
    egg_t *tmp = NULL;

    if (!server || !server->map || !server->map->egg)
        return;
    egg = server->map->egg;
    if (egg->id == id) {
        send_edi_to_all_graphics(server, id);
        remove_egg(server->map);
        return;
    }
    while (egg->next) {
        if (egg->next->id == id) {
            send_edi_to_all_graphics(server, id);
            tmp = egg->next;
            egg->next = egg->next->next;
            return free_egg(tmp);
        }
        egg = egg->next;
    }
}
