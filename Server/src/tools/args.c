/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** args
*/

#include "server.h"

int get_int_arg(char *str)
{
    int nb = 0;

    if (!str)
        return -1;
    if (strlen(str) > 10)
        return 2147483647;
    nb = atoi(str);
    if (nb < 0)
        return -1;
    return nb;
}

float get_float_arg(char *str)
{
    float nb = 0;

    if (!str)
        return -1;
    nb = atof(str);
    if (nb < 0) {
        fprintf(stderr, "Invalid param: %s\n", str);
        return -1;
    }
    return nb;
}

int get_team_count_from_args(char **args, int i)
{
    int count = 0;

    for (int j = i + 1; args[j] && args[j][0] != '-'; j += 1)
        count += 1;
    return count;
}

char **get_teams_names_from_args(char **args, int i, int team_count)
{
    char **team_names = malloc(sizeof(char *) * (team_count + 1));

    if (!team_names)
        return NULL;
    for (int j = 0; j < team_count; j += 1) {
        team_names[j] = strdup(args[i + 1 + j]);
        if (!team_names[j])
            return NULL;
    }
    team_names[team_count] = NULL;
    return team_names;
}

int get_server_port(char *port_str)
{
    int server_port = get_int_arg(port_str);

    if (server_port < 0) {
        fprintf(stderr, "\n-p option only accepts valid ports\n\n");
        exit(print_server_usage_error());
    }
    if (server_port > 65535)
        server_port = find_available_port();
    return server_port;
}
