/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** resources
*/

#include "server.h"

bool is_valid_resource(char *resource)
{
    char *resources[] = {
        "food",
        "linemate",
        "deraumere",
        "sibur",
        "mendiane",
        "phiras",
        "thystame",
        NULL
    };

    for (int i = 0; resources[i] != NULL; i++)
        if (!strcmp(resources[i], resource))
            return true;
    return false;
}

bool update_resource(
    int *map_resource,
    int *inventory_resource,
    bool take
)
{
    if (!map_resource || !inventory_resource)
        exit_error("update_resource()");
    if (*map_resource == 0 && take)
        return false;
    if (*inventory_resource == 0 && !take)
        return false;
    *map_resource += take ? -1 : 1;
    *inventory_resource += take ? 1 : -1;
    return true;
}

bool find_and_update_resource(
    char *resource,
    tile_t *t,
    inventory_t *i,
    bool take
)
{
    if (!resource || !t || !i)
        exit_error("find_and_update_resource()");
    if (!strcmp(resource, "food"))
        return update_resource(&t->food, &i->food, take);
    if (!strcmp(resource, "linemate"))
        return update_resource(&t->linemate, &i->linemate, take);
    if (!strcmp(resource, "deraumere"))
        return update_resource(&t->deraumere, &i->deraumere, take);
    if (!strcmp(resource, "sibur"))
        return update_resource(&t->sibur, &i->sibur, take);
    if (!strcmp(resource, "mendiane"))
        return update_resource(&t->mendiane, &i->mendiane, take);
    if (!strcmp(resource, "phiras"))
        return update_resource(&t->phiras, &i->phiras, take);
    if (!strcmp(resource, "thystame"))
        return update_resource(&t->thystame, &i->thystame, take);
    return false;
}

bool take_resource(
    tile_t ***tiles,
    inventory_t *inventory,
    int pos[2],
    char *resource
)
{
    if (!tiles || !tiles[pos[1]] || !tiles[pos[1]][pos[0]] ||
        !inventory || !resource)
        exit_error("take_resource()");
    if (!is_valid_resource(resource))
        return false;
    return find_and_update_resource(resource, tiles[pos[1]][pos[0]],
        inventory, true);
}

bool set_resource(
    tile_t ***tiles,
    inventory_t *inventory,
    int pos[2],
    char *resource
)
{
    if (!tiles || !tiles[pos[1]] || !tiles[pos[1]][pos[0]] ||
        !inventory || !resource)
        exit_error("set_resource()");
    if (!is_valid_resource(resource))
        return false;
    return find_and_update_resource(resource, tiles[pos[1]][pos[0]],
        inventory, false);
}
