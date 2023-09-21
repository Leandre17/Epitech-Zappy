/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** win
*/

#include "server.h"

void get_nb_players_at_max_level_in_team_and_send_winning_team(
    server_t *server,
    char *team_name
)
{
    int nb_player_max_level = 0;
    player_t *current_player = NULL;
    char *output = NULL;

    if (!server || !team_name)
        exit_error("get_nb_players_at_max_level_in_team()");
    for (int i = 0; i < server->nb_clients; i += 1) {
        current_player = server->clients[i].player;
        if (!current_player || !current_player->team_name)
            continue;
        if (current_player->level >= 8 &&
            !strcmp(current_player->team_name, team_name))
            nb_player_max_level += 1;
    }
    if (nb_player_max_level >= 6) {
        output = msprintf("seg %s\n", team_name);
        send_to_all_graphics(server, output);
        server->is_ended = true;
        free(output);
    }
}

void handle_win(server_t *server)
{
    if (!server || !server->teams)
        exit_error("handle_win()");
    if (server->nb_clients == 0 || !server->clients)
        return;
    for (int i = 0; server->teams[i] != NULL; i += 1) {
        get_nb_players_at_max_level_in_team_and_send_winning_team(
            server,
            server->teams[i]->name
        );
    }
}
