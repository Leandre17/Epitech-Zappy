/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** map
*/

#include "server.h"

void print_tile_line(tile_t **tiles)
{
    for (int x = 0; tiles[x] != NULL; x += 1) {
        printf("\t\t[%d]: {%d, %d, %d, %d, %d, %d, %d}\n",
            x,
            tiles[x]->food,
            tiles[x]->linemate,
            tiles[x]->deraumere,
            tiles[x]->sibur,
            tiles[x]->mendiane,
            tiles[x]->phiras,
            tiles[x]->thystame
        );
    }
}

void print_eggs(egg_t *egg)
{
    egg_t *cur = egg;

    printf("\t- eggs:\n");
    if (!egg)
        printf("\tNULL\n");
    else
        while (cur) {
            printf("\t\tegg [%d]:\n", cur->id);
            printf("\t\t\t- player_id: %d\n", cur->player_id);
            printf("\t\t\t- team_name: %s\n", cur->team_name);
            printf("\t\t\t- x: %d\n", cur->pos_x);
            printf("\t\t\t- y: %d\n", cur->pos_y);
            printf("\t\t\t- is_layed: %d\n", cur->is_layed);
            printf("\t\t\t- lay_start_time: %lld\n", cur->lay_start_time);
            cur = cur->next;
        }
}

void print_incantations(incantation_t *ict)
{
    incantation_t *cur = ict;
    int i = 0;
    char *players_id_str = NULL;

    printf("\t- incantations:\n");
    if (!ict)
        printf("\tNULL\n");
    else
        while (cur) {
            players_id_str = get_players_id_str(cur);
            printf("\t\tincantation [%d]:\n", i);
            printf("\t\t\t- players_id: [%s]\n", players_id_str);
            printf("\t\t\t- x: %d\n", cur->pos_x);
            printf("\t\t\t- y: %d\n", cur->pos_y);
            printf("\t\t\t- level: %d\n", cur->level);
            printf("\t\t\t- start_time: %lld\n", cur->start_time);
            cur = cur->next;
            i += 1;
            free(players_id_str);
        }
}

void debug_map(map_t *map)
{
    if (!map)
        fprintf(stderr, "Map is NULL\n");
    printf("Map:\n");
    printf("\t- width: %d\n", map->width);
    printf("\t- height: %d\n", map->height);
    printf("\t- tiles:\n");
    if (!map->tiles)
        printf("\tNULL\n");
    else
        for (int y = 0; map->tiles[y] != NULL; y += 1) {
            printf("\t\t[%d]:\n", y);
            print_tile_line(map->tiles[y]);
            printf("\n");
        }
    print_eggs(map->egg);
    print_incantations(map->incantation);
}
