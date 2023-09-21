/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** ai_commands
*/

#ifndef AI_COMMANDS_H_
    #define AI_COMMANDS_H_

    #include "server.h"

    // Data
    typedef struct ai_command_s {
        char *name;
        void (*function)(server_t *server, client_t *client, char **args);
        float time_limit;
    } ai_command_t;

    // Functions
    void command_broadcast(server_t *server, client_t *client, char **args);
    void command_connect_nbr(server_t *server, client_t *client, char **args);
    void command_eject(server_t *server, client_t *client, char **args);
    void command_fork(server_t *server, client_t *client, char **args);
    void command_forward(server_t *server, client_t *client, char **args);
    void command_left(server_t *server, client_t *client, char **args);
    void command_look(server_t *server, client_t *client, char **args);
    void command_incantation(server_t *server, client_t *client, char **args);
    void command_inventory(server_t *server, client_t *client, char **args);
    void command_right(server_t *server, client_t *client, char **args);
    void command_set(server_t *server, client_t *client, char **args);
    void command_take(server_t *server, client_t *client, char **args);

    // No team function
    int handle_ai_command_no_team(
        server_t *server,
        client_t *client,
        char **args
    );

    // Other functions
    void move_player_forward(
        server_t *s,
        player_t *player,
        enum orientations orientation
    );

    // Commands
    #define COMMAND_BROADCAST "Broadcast"
    #define COMMAND_CONNECT_NBR "Connect_nbr"
    #define COMMAND_EJECT "Eject"
    #define COMMAND_FORK "Fork"
    #define COMMAND_FORWARD "Forward"
    #define COMMAND_LEFT "Left"
    #define COMMAND_LOOK "Look"
    #define COMMAND_INCANTATION "Incantation"
    #define COMMAND_INVENTORY "Inventory"
    #define COMMAND_RIGHT "Right"
    #define COMMAND_SET "Set"
    #define COMMAND_TAKE "Take"

    #define AI_COMMANDS_COUNT 12
    #define AI_COMMANDS {{                                                  \
            COMMAND_BROADCAST, &command_broadcast, 7.0f,                    \
        }, {                                                                \
            COMMAND_CONNECT_NBR, &command_connect_nbr, 0.0f,                \
        }, {                                                                \
            COMMAND_EJECT, &command_eject, 7.0f,                            \
        }, {                                                                \
            COMMAND_FORK, &command_fork, 0.0f,                              \
        }, {                                                                \
            COMMAND_FORWARD, &command_forward, 7.0f,                        \
        }, {                                                                \
            COMMAND_LEFT, &command_left, 7.0f,                              \
        }, {                                                                \
            COMMAND_LOOK, &command_look, 7.0f,                              \
        }, {                                                                \
            COMMAND_INCANTATION, &command_incantation, 0.0f,                \
        }, {                                                                \
            COMMAND_INVENTORY, &command_inventory, 1.0f,                    \
        }, {                                                                \
            COMMAND_RIGHT, &command_right, 7.0f,                            \
        }, {                                                                \
            COMMAND_SET, &command_set, 7.0f,                                \
        }, {                                                                \
            COMMAND_TAKE, &command_take, 7.0f,                              \
        }                                                                   \
    }

#endif /* !AI_COMMANDS_H_ */
