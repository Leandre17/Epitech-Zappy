/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** teams
*/

#include "server.h"

void destroy_teams(team_t **teams)
{
    if (!teams)
        return;
    for (int i = 0; teams[i]; i++) {
        if (teams[i]->name)
            free(teams[i]->name);
        free(teams[i]);
    }
    free(teams);
}
