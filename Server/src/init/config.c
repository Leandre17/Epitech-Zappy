/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** config
*/

#include "server.h"

static const option_mapping_t OPTION_MAPPING[] = {
    {"-p", set_port},
    {"-x", set_width},
    {"-y", set_height},
    {"-n", set_team_names},
    {"-c", set_clients_nb},
    {"-f", set_freq},
    {NULL, NULL}
};

config_t *init_empty_config(void)
{
    config_t *config = malloc(sizeof(config_t));

    if (!config)
        return NULL;
    config->port = 4242;
    config->width = 10;
    config->height = 10;
    config->team_names = init_default_config_teams();
    config->team_count = 4;
    config->clients_nb = 3;
    config->freq = 100;
    return config;
}

void get_config_from_args(config_t *config, char **args, int *i)
{
    for (int j = 0; OPTION_MAPPING[j].option != NULL; j += 1)
        if (!strcmp(args[*i], OPTION_MAPPING[j].option))
            return OPTION_MAPPING[j].func(config, args, i);
    fprintf(stderr, "\n%s is not a valid option\n\n", args[*i]);
    exit(print_server_usage_error());
}

config_t *init_config(char **args)
{
    config_t *config = NULL;

    if (!args)
        return NULL;
    config = init_empty_config();
    for (int i = 0; args[i] != NULL; i += 1)
        get_config_from_args(config, args, &i);
    return config;
}
