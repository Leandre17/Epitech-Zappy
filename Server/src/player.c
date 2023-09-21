/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** player
*/

#include "server.h"

int nb_commands(player_t *player)
{
    command_t *tmp = NULL;
    int nb_commands = 0;

    if (!player)
        return 0;
    tmp = player->command;
    while (tmp) {
        tmp = tmp->next;
        nb_commands += 1;
    }
    return nb_commands;
}

command_t *create_player_command(
    const ai_command_t *ai_command,
    char **args
)
{
    command_t *cmd = NULL;

    if (!(cmd = malloc(sizeof(command_t))))
        return NULL;
    cmd->name = ai_command->name;
    cmd->function = ai_command->function;
    cmd->args = clone_arr(args);
    cmd->time_limit = ai_command->time_limit;
    cmd->start_time = get_current_time_in_ms();
    cmd->next = NULL;
    return cmd;
}

void add_command_to_end(
    player_t *player,
    command_t *new_cmd
)
{
    command_t *tmp = NULL;

    if (!player || !new_cmd)
        return;
    if (!player->command) {
        player->command = new_cmd;
        return;
    }
    tmp = player->command;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_cmd;
}

void add_player_command(
    player_t *player,
    const ai_command_t *command,
    char **args
)
{
    command_t *new_cmd = NULL;

    if (!player || !command || !args)
        return;
    if (nb_commands(player) >= MAX_WAITING_COMMANDS)
        return;
    if (!(new_cmd = create_player_command(command, args)))
        exit_error("add_player_command()");
    add_command_to_end(player, new_cmd);
}
