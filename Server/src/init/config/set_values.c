/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** set_values
*/

#include "server.h"

void set_port(config_t *config, char **args, int *i)
{
    config->port = get_server_port(args[++(*i)]);
}

void set_width(config_t *config, char **args, int *i)
{
    config->width = get_int_arg(args[++(*i)]);
    if (config->width < 10 || config->width > 30) {
        fprintf(stderr,
            "\n-x option only accepts integer values between 10 and 30\n\n");
        exit(print_server_usage_error());
    }
}

void set_height(config_t *config, char **args, int *i)
{
    config->height = get_int_arg(args[++(*i)]);
    if (config->height < 10 || config->height > 30) {
        fprintf(stderr,
            "\n-y option only accepts integer values between 10 and 30\n\n");
        exit(print_server_usage_error());
    }
}

void set_team_names(config_t *config, char **args, int *i)
{
    config->team_count = get_team_count_from_args(args, *i);
    free_arr(config->team_names);
    config->team_names = get_teams_names_from_args(
        args,
        *i,
        config->team_count
    );
    (*i) += config->team_count;
}
