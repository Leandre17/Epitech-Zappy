/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** graphic_commands
*/

#ifndef GRAPHIC_COMMANDS_H_
    #define GRAPHIC_COMMANDS_H_

    #include "server.h"

    // Data
    typedef struct graphic_command_s {
        char *name;
        void (*function)(server_t *server, client_t *client, char **args);
    } graphic_command_t;

    // Functions
    void command_bct(server_t *server, client_t *client, char **args);
    void command_mct(server_t *server, client_t *client, char **args);
    void command_msz(server_t *server, client_t *client, char **args);
    void command_pin(server_t *server, client_t *client, char **args);
    void command_plv(server_t *server, client_t *client, char **args);
    void command_ppo(server_t *server, client_t *client, char **args);
    void command_sgt(server_t *server, client_t *client, char **args);
    void command_sst(server_t *server, client_t *client, char **args);
    void command_tna(server_t *server, client_t *client, char **args);

    // Str functions
    char *mct_str(map_t *map);
    char *msz_str(map_t *map);
    char *pin_str(player_t *player);
    char *plv_str(player_t *player);
    char *ppo_str(player_t *player);
    char *sgt_str(float freq);
    char *tna_str(team_t **teams);

    // Not recognized as GRAPHIC function
    void command_graphic(
        server_t *server,
        client_t *client,
        char **args
    );

    // Commands
    #define COMMAND_BCT "bct"
    #define COMMAND_MCT "mct"
    #define COMMAND_MSZ "msz"
    #define COMMAND_PIN "pin"
    #define COMMAND_PLV "plv"
    #define COMMAND_PPO "ppo"
    #define COMMAND_SGT "sgt"
    #define COMMAND_SST "sst"
    #define COMMAND_TNA "tna"

    #define GRAPHIC_COMMANDS_COUNT 9
    #define GRAPHIC_COMMANDS {{                                             \
            COMMAND_BCT, &command_bct,                                      \
        }, {                                                                \
            COMMAND_MCT, &command_mct,                                      \
        }, {                                                                \
            COMMAND_MSZ, &command_msz,                                      \
        }, {                                                                \
            COMMAND_PIN, &command_pin,                                      \
        }, {                                                                \
            COMMAND_PLV, &command_plv,                                      \
        }, {                                                                \
            COMMAND_PPO, &command_ppo,                                      \
        }, {                                                                \
            COMMAND_SGT, &command_sgt,                                      \
        }, {                                                                \
            COMMAND_SST, &command_sst,                                      \
        }, {                                                                \
            COMMAND_TNA, &command_tna,                                      \
        }, {                                                                \
            NULL, NULL                                                      \
        }                                                                   \
    }

#endif /* !GRAPHIC_COMMANDS_H_ */
