/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** pic
*/

#include "server.h"

char *get_players_id_str(incantation_t *incantation)
{
    char *str = NULL;
    char *tmp = NULL;

    if (!incantation || !incantation->players_id)
        exit_error("get_players_id_str()");
    for (int i = 0; incantation->players_id[i] != -1; i += 1) {
        tmp = msprintf("%d", incantation->players_id[i]);
        if (!str)
            str = tmp;
        else
            str = msprintf("%s %s", str, tmp);
    }
    return str;
}

void send_pic_to_all_graphics(
    server_t *server,
    incantation_t *incantation
)
{
    char *output = NULL;
    char *players_id_str = NULL;

    if (!server || !incantation)
        exit_error("send_pdi_to_all_graphics()");
    players_id_str = get_players_id_str(incantation);
    output = msprintf(
        "pic %d %d %d %s\n",
        incantation->pos_x,
        incantation->pos_y,
        incantation->level,
        players_id_str
    );
    free(players_id_str);
    send_to_all_graphics(server, output);
    free(output);
}
