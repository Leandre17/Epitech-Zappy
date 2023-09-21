/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** destroy
*/

#ifndef DESTROY_H_
    #define DESTROY_H_

    #include "server.h"

    // config.c
    void destroy_config(config_t *config);

    // data.c
    void destroy_data(server_t *server, config_t *config);

    // map.c
    void destroy_map(map_t *map);

    // player.c
    void destroy_player_command(player_t *player);
    void destroy_player(player_t *player);

    // server.c
    void destroy_server(server_t *server);

    // teams.c
    void destroy_teams(team_t **teams);


#endif /* !DESTROY_H_ */
