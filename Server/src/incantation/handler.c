/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** handler
*/

#include "server.h"

void upgrade_players(
    server_t *server,
    incantation_t *incantation
)
{
    client_t *client = NULL;
    char *output = NULL;

    if (!server || !incantation)
        exit_error("upgrade_players()");
    for (int i = 0; incantation->players_id[i] != -1; i++) {
        if (!(client = get_client_from_player_id(
            server, incantation->players_id[i])))
            continue;
        client->player->level += 1;
        client->player->is_available = true;
    }
    output = msprintf("Current level: %d\n", client->player->level);
    send_to_all_players_in_incantation(server, incantation, output);
    free(output);
}

void handle_incantation(
    server_t *server,
    incantation_t *incantation
)
{
    long long current_time = 0;

    if (!server || !incantation)
        exit_error("handle_incantation()");
    current_time = get_current_time_in_ms();
    if ((current_time - incantation->start_time) / 1000 >=
        300 / server->freq) {
        if (are_incantation_requirements_met(
            server,
            get_client_from_player_id(
                server,
                incantation->players_id[0])->player
            )
        ) {
            upgrade_players(server, incantation);
            send_pie_to_all_graphics(server, incantation, true);
        } else
            send_pie_to_all_graphics(server, incantation, false);
        remove_incantation(server->map);
    }
}

void handle_incantations(server_t *server)
{
    incantation_t *current = NULL;

    if (!server || !server->map)
        exit_error("handle_incantations()");
    if (!server->map->incantation)
        return;
    current = server->map->incantation;
    while (current) {
        handle_incantation(server, current);
        current = current->next;
    }
}
