/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** pnw
*/

#include "server.h"

char *pnw_str(player_t *player)
{
    char *output = NULL;

    if (!player)
        exit_error("pnw_str()");
    output = msprintf(
        "pnw %d %d %d %d %d %s\n",
        player->id,
        player->pos_x,
        player->pos_y,
        player->orientation,
        player->level,
        player->team_name
    );
    return output;
}

char *all_pnw_str(client_t *clients, int nb_clients)
{
    char *output = strdup("");
    char *pnw = NULL;

    for (int i = 0; i < nb_clients; i += 1) {
        if (clients[i].is_graphic)
            continue;
        pnw = pnw_str(clients[i].player);
        output = msprintf("%s%s", output, pnw);
        free(pnw);
    }
    return output;
}

void send_pnw_to_all_graphics(
    server_t *server,
    player_t *player
)
{
    char *output = NULL;

    if (!server || !player)
        exit_error("send_team_output_to_all_graphics()");
    output = pnw_str(player);
    send_to_all_graphics(server, output);
    free(output);
}
