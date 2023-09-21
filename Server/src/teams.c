/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** teams
*/

#include "server.h"

void add_a_free_slot_to_team(server_t *server, char *team_name)
{
    if (!server || !team_name)
        return;
    for (int i = 0; server->teams[i] != NULL; i += 1) {
        if (!strcmp(server->teams[i]->name, team_name)) {
            server->teams[i]->free_slots += 1;
            break;
        }
    }
}

void remove_a_free_slot_to_team(server_t *server, char *team_name)
{
    if (!server || !team_name)
        return;
    for (int i = 0; server->teams[i] != NULL; i += 1) {
        if (!strcmp(server->teams[i]->name, team_name)) {
            server->teams[i]->free_slots -= 1;
            break;
        }
    }
}
