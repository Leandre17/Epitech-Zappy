/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** ppo
*/

#include "server.h"

char *ppo_str(player_t *player)
{
    char *output = NULL;

    if (!player || !player->inventory)
        exit_error("ppo_str()");
    output = msprintf(
        "ppo %d %d %d %d\n",
        player->id,
        player->pos_x,
        player->pos_y,
        player->orientation
    );
    return output;
}

void command_ppo(
    server_t *server,
    client_t *client,
    char **args
)
{
    char *output = NULL;

    if (!server || !client || !args)
        exit_error("command_ppo()");
    if (arrlen(args) != 2)
        return send_to_user(client, API_GRAPHIC_INVALID_PARAMETER);
    for (int i = 0; i < server->nb_clients; i++)
        if (server->clients[i].player->id == atoi(args[1]) &&
            !server->clients[i].is_graphic) {
            output = ppo_str(server->clients[i].player);
            send_to_user(client, output);
            free(output);
            return;
        }
    send_to_user(client, API_GRAPHIC_INVALID_PARAMETER);
}
