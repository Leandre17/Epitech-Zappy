/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** init
*/

#ifndef INIT_H_
    #define INIT_H_

    #include "server.h"

    // config
        // set_values.c
        void set_port(config_t *config, char **args, int *i);
        void set_width(config_t *config, char **args, int *i);
        void set_height(config_t *config, char **args, int *i);
        void set_team_names(config_t *config, char **args, int *i);

        // set_values2.c
        void set_clients_nb(config_t *config, char **args, int *i);
        void set_freq(config_t *config, char **args, int *i);

    // config.c
    config_t *init_empty_config(void);
    void get_config_from_args(config_t *config, char **args, int *i);
    config_t *init_config(char **args);

    // fd_set.c
    void init_fd_set(server_t *server, fd_set *read_fds);

    // fill_map.c
    void fill_tiles(int width, int height, tile_t ***tiles);

    // map.c
    map_t *init_map(config_t *config);

    // player.c
    void set_player_position(player_t *player, int *pos);
    player_t *init_player(server_t *server);

    // server.c
    int find_available_port(void);
    server_t *init_server(config_t *config);

    // teams.c
    char **init_default_config_teams(void);
    team_t **init_teams(config_t *config);

#endif /* !INIT_H_ */
