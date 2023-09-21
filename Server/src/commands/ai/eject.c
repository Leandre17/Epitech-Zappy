/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** eject
*/

#include "server.h"

bool send_to_all_ai_sharing_tile_and_eject_player(
    server_t *server,
    int pos[2],
    enum orientations orientation,
    int except_fd
)
{
    int has_player_to_eject = false;
    char *output = NULL;

    if (!server)
        exit_error("send_to_all_ai_sharing_tile()");
    for (int i = 0; i < server->nb_clients; i++) {
        if (server->clients[i].sockfd == except_fd)
            continue;
        if (server->clients[i].player->pos_x == pos[0] &&
            server->clients[i].player->pos_y == pos[1]) {
            has_player_to_eject = true;
            move_player_forward(server, server->clients[i].player,
                orientation);
            output = msprintf("eject: %d\n", orientation);
            send_to_user(&server->clients[i], output);
            free(output);
        }
    }
    return has_player_to_eject;
}

bool destroy_all_eggs_in_tile_and_send_to_graphics(
    server_t *server,
    int pos_x,
    int pos_y
)
{
    bool has_eggs_to_eject = false;
    egg_t *cur = NULL;
    egg_t *tmp = NULL;

    if (!server || !server->map)
        exit_error("destroy_all_eggs_in_tile_and_send_to_graphics()");
    if (!server->map->egg)
        return false;
    cur = server->map->egg;
    while (cur) {
        if (cur->pos_x == pos_x && cur->pos_y == pos_y && cur->is_layed) {
            has_eggs_to_eject = true;
            tmp = cur->next;
            remove_egg_by_id(server, cur->id);
            remove_a_free_slot_to_team(server, cur->team_name);
            cur = tmp;
        }
    }
    return has_eggs_to_eject;
}

void command_eject(
    server_t *server,
    client_t *client,
    char **args
)
{
    int has_element_to_eject = false;

    if (!server || !client || !client->player || !args)
        exit_error("command_eject()");
    if (arrlen(args) != 1)
        return send_to_user(client, API_NOT_FOUND);
    has_element_to_eject = send_to_all_ai_sharing_tile_and_eject_player(
        server, (int[2]){client->player->pos_x, client->player->pos_y},
        client->player->orientation, client->sockfd);
    has_element_to_eject = has_element_to_eject == 0
        ? destroy_all_eggs_in_tile_and_send_to_graphics(
            server, client->player->pos_x, client->player->pos_y)
        : has_element_to_eject;
    if (!has_element_to_eject)
        return send_to_user(client, API_NOT_FOUND);
    send_pex_to_all_graphics(server, client->player->id);
    send_to_user(client, API_SUCCESS);
}
