/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** look
*/

#include "server.h"

void append_tile_content(char **output, server_t *server, int x, int y)
{
    char *tmp = NULL;
    char *tile_content = get_tile_content(server, x, y);

    tmp = msprintf(tile_content);
    if (!(*output))
        *output = msprintf("%s", tmp);
    else {
        if (strlen(tmp) > 0)
            *output = msprintf("%s, %s", *output, tmp);
        else
            *output = msprintf("%s,%s", *output, tmp);
    }
    free(tmp);
}

int get_infinite_value(int value, int max)
{
    if (value < 0)
        return max + value;
    return value % max;
}

void append_player_vision_from_level(
    char **output,
    server_t *server,
    player_t *player,
    int level
)
{
    int o = player->orientation;
    int start_x = o == EAST ? level : -level;
    int start_y = o == SOUTH ? level : -level;
    int end_x = o == WEST ? -level : level;
    int end_y = o == NORTH ? -level : level;

    for (int x = start_x; x <= end_x; x += 1)
        for (int y = start_y; y <= end_y; y += 1) {
            append_tile_content(
                output,
                server,
                get_infinite_value(player->pos_x + x, server->map->width),
                get_infinite_value(player->pos_y + y, server->map->height)
            );
        }
}

char *get_player_vision(server_t *server, player_t *player)
{
    char *output = NULL;

    if (!server || !player)
        exit_error("Invalid arguments");
    output = get_tile_content(server, player->pos_x, player->pos_y);
    for (int i = 1; i <= player->level; i += 1)
        append_player_vision_from_level(&output, server, player, i);
    return output;
}

void command_look(
    server_t *server,
    client_t *client,
    char **args
)
{
    char *vision = NULL;
    char *output = NULL;

    if (!server || !client || !client->player || !args)
        exit_error("command_look()");
    if (arrlen(args) != 1)
        return send_to_user(client, API_NOT_FOUND);
    vision = get_player_vision(server, client->player);
    output = msprintf("[ %s ]\n", vision);
    free(vision);
    send_to_user(client, output);
    free(output);
}
