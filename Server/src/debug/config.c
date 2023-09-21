/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** config
*/

#include "server.h"

void debug_config(config_t *config)
{
    if (!config)
        fprintf(stderr, "Config is NULL\n");
    printf("Config:\n");
    printf("\t- port: %d\n", config->port);
    printf("\t- width: %d\n", config->width);
    printf("\t- height: %d\n", config->height);
    printf("\t- team_count: %d\n", config->team_count);
    if (!config->team_names)
        printf("\t- team_names: NULL\n");
    else {
        printf("\t- team_names:\n");
        for (int i = 0; config->team_names[i] != NULL; i += 1)
            printf("\t\t%s\n", config->team_names[i]);
    }
    printf("\t- clients_nb: %d\n", config->clients_nb);
    printf("\t- freq: %f\n", config->freq);
}
