/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** set_values2
*/

#include "server.h"

void set_clients_nb(config_t *config, char **args, int *i)
{
    config->clients_nb = get_int_arg(args[++(*i)]);
    if (config->clients_nb < 1) {
        fprintf(stderr, "\n-c option only accepts integer values ");
        fprintf(stderr, "greater or equal to 1\n\n");
        exit(print_server_usage_error());
    }
}

void set_freq(config_t *config, char **args, int *i)
{
    config->freq = get_int_arg(args[++(*i)]);
    if (config->freq < 2 || config->freq > 10000) {
        fprintf(stderr, "\n-f option only accepts integer values ");
        fprintf(stderr, "between 2 and 10000\n\n");
        exit(print_server_usage_error());
    }
}
