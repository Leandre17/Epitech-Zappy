/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** teams
*/

#include "server.h"

char **init_default_config_teams(void)
{
    char **teams = NULL;

    if (!(teams = malloc(sizeof(char *) * 5)))
        exit_error("malloc()");
    teams[0] = strdup("Team1");
    teams[1] = strdup("Team2");
    teams[2] = strdup("Team3");
    teams[3] = strdup("Team4");
    teams[4] = NULL;
    return teams;
}

team_t **init_teams(config_t *config)
{
    team_t **teams = NULL;

    if (!config)
        exit_error("init_teams()");
    if (!(teams = malloc(sizeof(team_t *) * (config->team_count + 1))))
        exit_error("malloc()");
    for (int i = 0; i < config->team_count; i += 1) {
        if (!(teams[i] = malloc(sizeof(team_t))))
            exit_error("malloc()");
        teams[i]->name = strdup(config->team_names[i]);
        teams[i]->free_slots = config->clients_nb;
    }
    teams[config->team_count] = NULL;
    return teams;
}
