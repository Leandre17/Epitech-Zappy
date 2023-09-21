/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** mct
*/

#include "server.h"

char *get_tile_content_line(
    tile_t *t,
    int x,
    int y
)
{
    char *output = NULL;

    if (!t)
        exit_error("send_tile_content_to_user()");
    output = msprintf("bct %d %d %d %d %d %d %d %d %d\n",
        x,
        y,
        t->food,
        t->linemate,
        t->deraumere,
        t->sibur,
        t->mendiane,
        t->phiras,
        t->thystame
    );
    return output;
}

char *append_to_output(char *output, tile_t *t, int pos[2])
{
    char *tile_content_line = NULL;
    char *new_output = NULL;

    if (!t)
        exit_error("append_to_output()");
    tile_content_line = get_tile_content_line(t, pos[0], pos[1]);
    new_output = msprintf("%s%s", output, tile_content_line);
    if (strlen(output) > 0)
        free(output);
    free(tile_content_line);
    return new_output;
}

char *mct_str(map_t *map)
{
    char *output = "";
    tile_t *t = NULL;
    int pos[2] = {0, 0};

    if (!map)
        return output;
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            t = map->tiles[y][x];
            pos[0] = x;
            pos[1] = y;
            output = append_to_output(output, t, pos);
        }
    }
    return output;
}

void command_mct(
    server_t *server,
    client_t *client,
    char **args
)
{
    char *output = NULL;

    if (!server || !client || !args || !server->map || !server->map->tiles)
        exit_error("command_mct()");
    if (arrlen(args) != 1)
        return send_to_user(client, API_GRAPHIC_INVALID_PARAMETER);
    output = mct_str(server->map);
    send_to_user(client, output);
    free(output);
}
