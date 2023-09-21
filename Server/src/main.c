/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** main
*/

#include "server.h"

int main(int argc, char **argv)
{
    config_t *config = NULL;

    if (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")))
        return print_server_usage();
    argv++;
    config = init_config(argv);
    return zappy_server(config);
}
