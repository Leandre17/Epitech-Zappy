/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** tile
*/

#include "server.h"

char *combine_content(
    char *player_content,
    char *egg_content,
    char *resource_content
)
{
    if (!player_content && !egg_content && !resource_content)
        return "";
    if (!player_content && !egg_content)
        return strdup(resource_content);
    if (!player_content && !resource_content)
        return strdup(egg_content);
    if (!egg_content && !resource_content)
        return strdup(player_content);
    if (!player_content)
        return msprintf("%s %s", egg_content, resource_content);
    if (!egg_content)
        return msprintf("%s %s", player_content, resource_content);
    if (!resource_content)
        return msprintf("%s %s", player_content, egg_content);
    return msprintf(
        "%s %s %s",
        player_content,
        egg_content,
        resource_content
    );
}

void free_content(
    char *player_content,
    char *egg_content,
    char *resource_content
)
{
    if (egg_content) {
        free(egg_content);
        egg_content = NULL;
    }
    if (player_content) {
        free(player_content);
        player_content = NULL;
    }
    if (resource_content) {
        free(resource_content);
        resource_content = NULL;
    }
}
