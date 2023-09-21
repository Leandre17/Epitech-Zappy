/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** inventory
*/

#include "server.h"

char *inventory_str(inventory_t *inventory)
{
    char *output1 = NULL;
    char *output2 = NULL;

    if (!inventory)
        exit_error("inventory_str()");
    output1 = msprintf("[food %d, linemate %d, deraumere %d, ",
        inventory->food,
        inventory->linemate,
        inventory->deraumere
    );
    output2 = msprintf("%ssibur %d, mendiane %d, phiras %d, thystame %d ]\n",
        output1,
        inventory->sibur,
        inventory->mendiane,
        inventory->phiras,
        inventory->thystame
    );
    free(output1);
    return output2;
}

void command_inventory(
    server_t *server,
    client_t *client,
    char **args
)
{
    char *output = NULL;

    if (!server || !client || !args)
        exit_error("command_inventory()");
    if (arrlen(args) != 1)
        return send_to_user(client, API_NOT_FOUND);
    output = inventory_str(client->player->inventory);
    send_to_user(client, output);
    free(output);
}
