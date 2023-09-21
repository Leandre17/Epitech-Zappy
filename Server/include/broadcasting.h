/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** broadcasting
*/

#ifndef BROADCASTING_H_
    #define BROADCASTING_H_

    #include "server.h"

    // angles.c
    double get_angle_of_destination_message(
        map_t *map,
        player_t *src,
        player_t *dest
    );

    // output.c
    void send_broadcast_output_to_all_ai(
        server_t *server,
        player_t *player,
        char *message
    );

    // points.c
    point_t get_point_in_front_of_player(player_t *player);
    point_t *get_all_theorical_player_points(
        map_t *map,
        player_t *src,
        player_t *dest
    );
    point_t get_closest_theorical_player_point(
        map_t *map,
        player_t *src,
        player_t *dest
    );

    // tile.c
    int get_tile_of_destination_message(
        map_t *map,
        player_t *src,
        player_t *dest
    );

#endif /* !BROADCASTING_H_ */
