/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** incantations
*/

#ifndef INCANTATIONS_H_
    #define INCANTATIONS_H_

    #include "server.h"

    // add.c
    void add_incantation(server_t *server, player_t *player);

    // handler.c
    void handle_incantations(server_t *server);

    // remove.c
    void remove_incantation(map_t *map);

    // requirements.c
    bool are_incantation_requirements_met(server_t *server, player_t *player);

    // send.c
    client_t *get_client_from_player_id(server_t *server, int player_id);
    void send_to_all_players_in_incantation(
        server_t *server,
        incantation_t *incantation,
        char *buffer
    );

    // update_players.c
    void set_all_players_in_incantation_unavailable(
        server_t *server,
        incantation_t *incantation
    );

#endif /* !INCANTATIONS_H_ */
