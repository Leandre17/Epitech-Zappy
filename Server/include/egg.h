/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** egg
*/

#ifndef EGG_H_
    #define EGG_H_

    #include "server.h"

    // add.c
    void add_egg(server_t *server, player_t *player);

    // handler.c
    void handle_eggs(server_t *server);

    // remove.c
    void remove_egg(map_t *map);
    void remove_egg_by_id(server_t *server, int id);

#endif /* !EGG_H_ */
