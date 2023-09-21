/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** no_team
*/

#include "server.h"

void send_team_output(
    server_t *server,
    client_t *client,
    int i
)
{
    char *output = NULL;

    if (!server || !client)
        exit_error("send_team_output()");
    output = msprintf(
        "%d\n%d %d\n",
        server->teams[i]->free_slots,
        server->map->width,
        server->map->height);
    send_to_user(client, output);
    free(output);
}

int *init_int_arr(int value1, int value2)
{
    int *arr = malloc(sizeof(int) * 2);

    if (!arr)
        exit_error("init_int_arr()");
    arr[0] = value1;
    arr[1] = value2;
    return arr;
}

int *get_player_pos_from_eggs(server_t *server, char *team_name)
{
    egg_t *egg = NULL;
    int *pos = NULL;

    if (!server || !team_name)
        exit_error("get_player_pos_from_eggs()");
    egg = server->map->egg;
    while (egg) {
        if (!strcmp(egg->team_name, team_name) && egg->is_layed) {
            pos = init_int_arr(egg->pos_x, egg->pos_y);
            send_ebo_to_all_graphics(server, egg->id);
            remove_egg_by_id(server, egg->id);
            return pos;
        }
        egg = egg->next;
    }
    return init_int_arr(
        rand() % server->map->width,
        rand() % server->map->height
    );
}

int handle_ai_command_no_team(
    server_t *server,
    client_t *client,
    char **args
)
{
    if (!server || !client || !args)
        exit_error("handle_ai_command_no_team()");
    if (arrlen(args) != 1)
        return -1;
    for (int i = 0; server->teams[i] != NULL; i += 1) {
        if (!strcmp(server->teams[i]->name, args[0]) &&
            server->teams[i]->free_slots > 0) {
            set_player_position(client->player,
                get_player_pos_from_eggs(server, args[0]));
            client->player->team_name = strdup(server->teams[i]->name);
            server->teams[i]->free_slots -= 1;
            send_team_output(server, client, i);
            send_pnw_to_all_graphics(server, client->player);
            return SUCCESS;
        }
    }
    return -1;
}
