/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** command_manager
*/

#include "server.h"

int graphic_command_manager(
    server_t *server,
    client_t *client,
    char **params
)
{
    const graphic_command_t graphic_commands[] = GRAPHIC_COMMANDS;

    if (!server || !client || !params || !arrlen(params))
        exit_error("graphic_command_manager()");
    for (int i = 0; i < GRAPHIC_COMMANDS_COUNT; i += 1) {
        if (!strcmp(graphic_commands[i].name, params[0])) {
            graphic_commands[i].function(server, client, params);
            return 0;
        }
    }
    return -1;
}

int ai_command_manager(
    server_t *server,
    client_t *client,
    char **params
)
{
    const ai_command_t ai_commands[] = AI_COMMANDS;

    if (!server || !client || !client->player || !params || !arrlen(params))
        exit_error("ai_command_manager()");
    if (!client->player->team_name)
        return handle_ai_command_no_team(server, client, params);
    for (int i = 0; i < AI_COMMANDS_COUNT; i += 1) {
        if (!strcmp(ai_commands[i].name, params[0])) {
            add_player_command(client->player, &ai_commands[i], params);
            return SUCCESS;
        }
    }
    return -1;
}

void command_manager(server_t *server, client_t *client)
{
    int ret = -1;
    char **params = NULL;

    if (!client || !client->buffer)
        exit_error("command_manager()");
    remove_crlf(client->buffer);
    if (!(params = parse_args(client->buffer)) || !params[0])
        return send_to_user(client, API_NOT_FOUND);
    log_received_command(client, params);
    if (!strcasecmp("GRAPHIC", params[0]))
        return command_graphic(server, client, params);
    if (client->is_graphic) {
        ret = graphic_command_manager(server, client, params);
        free_arr(params);
    } else
        ret = ai_command_manager(server, client, params);
    if (ret != -1)
        return;
    client->is_graphic ? send_to_user(client, API_GRAPHIC_NOT_FOUND) :
        send_to_user(client, API_NOT_FOUND);
}
