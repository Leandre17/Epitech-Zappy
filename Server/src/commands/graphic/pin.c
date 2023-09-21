/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** pin
*/

#include "server.h"

char *pin_str(player_t *player)
{
    char *output = NULL;

    if (!player || !player->inventory)
        exit_error("pin_str()");
    output = msprintf(
        "pin %d %d %d %d %d %d %d %d %d %d\n",
        player->id,
        player->pos_x,
        player->pos_y,
        player->inventory->food,
        player->inventory->linemate,
        player->inventory->deraumere,
        player->inventory->sibur,
        player->inventory->mendiane,
        player->inventory->phiras,
        player->inventory->thystame
    );
    return output;
}

void command_pin(
    server_t *server,
    client_t *client,
    char **args
)
{
    char *output = NULL;

    if (!server || !client || !args)
        exit_error("command_pin()");
    if (arrlen(args) != 2)
        return send_to_user(client, API_GRAPHIC_INVALID_PARAMETER);
    for (int i = 0; i < server->nb_clients; i++)
        if (server->clients[i].player->id == atoi(args[1]) &&
            !server->clients[i].is_graphic) {
            output = pin_str(server->clients[i].player);
            send_to_user(client, output);
            free(output);
            return;
        }
    send_to_user(client, API_GRAPHIC_INVALID_PARAMETER);
}
