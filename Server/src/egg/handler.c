/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** handler
*/

#include "server.h"

void handle_egg(
    server_t *server,
    egg_t *egg
)
{
    long long current_time = 0;
    client_t *client = NULL;

    if (!server || !egg)
        exit_error("handle_egg()");
    current_time = get_current_time_in_ms();
    if ((current_time - egg->lay_start_time) / 1000 >=
        42 / server->freq) {
        if (!(client = get_client_from_player_id(server, egg->player_id)))
            return;
        egg->is_layed = true;
        add_a_free_slot_to_team(server, egg->team_name);
        send_to_user(client, API_SUCCESS);
        send_enw_to_all_graphics(server, egg);
    }
}

void handle_eggs(server_t *server)
{
    egg_t *current = NULL;

    if (!server || !server->map)
        exit_error("handle_eggs()");
    if (!server->map->egg)
        return;
    current = server->map->egg;
    while (current) {
        if (!current->is_layed)
            handle_egg(server, current);
        current = current->next;
    }
}
