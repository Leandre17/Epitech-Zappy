/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** pos
*/

#include "server.h"

bool check_invalid_pos(server_t *server, char *x, char *y)
{
    if (!server || !server->map)
        exit_error("check_invalid_pos()");
    if (getnbr(x) < 0 || getnbr(x) >= server->map->width)
        return true;
    if (getnbr(y) < 0 || getnbr(y) >= server->map->height)
        return true;
    return false;
}
