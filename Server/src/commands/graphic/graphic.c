/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** graphic
*/

#include "server.h"

char *get_graphic_output(server_t *server)
{
    char *output = NULL;
    char *msz = NULL;
    char *sgt = NULL;
    char *mct = NULL;
    char *tna = NULL;
    char *all_pnw = NULL;

    msz = msz_str(server->map);
    sgt = sgt_str(server->freq);
    mct = mct_str(server->map);
    tna = tna_str(server->teams);
    all_pnw = all_pnw_str(server->clients, server->nb_clients);
    output = msprintf("%s%s%s%s%s", msz, sgt, mct, tna, all_pnw);
    free(msz);
    free(sgt);
    free(mct);
    free(tna);
    free(all_pnw);
    return output;
}

void command_graphic(
    server_t *server,
    client_t *client,
    char **args
)
{
    char *output = NULL;

    if (!server || !client || !args)
        exit_error("command_graphic()");
    if (arrlen(args) != 1 || client->is_graphic)
        return send_to_user(client, API_NOT_FOUND);
    client->is_graphic = true;
    output = get_graphic_output(server);
    send_to_user(client, output);
    free(output);
}
