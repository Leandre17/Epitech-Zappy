/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    // C
    #include <unistd.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <arpa/inet.h>
    #include <stddef.h>
    #include <sys/select.h>
    #include <string.h>
    #include <errno.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <sys/time.h>
    #include <math.h>

    // Constants
    #define SUCCESS 0
    #define ERROR 84
    #define BACKLOG_SIZE 10
    #define MAX_CLIENTS 4096
    #define READ_BUFFER_SIZE (size_t) 32768
    #define MAX_WAITING_COMMANDS 10
    #define SEPARATOR "--------------------------------------------------\n"
    #define PI 3.14159265358979323846

    // API Codes
    #define API_WELCOME "WELCOME\n"
    #define API_SUCCESS "ok\n"
    #define API_NOT_FOUND "ko\n"
    #define API_GRAPHIC_INVALID_PARAMETER "sbp\n"
    #define API_GRAPHIC_NOT_FOUND "suc\n"
    #define API_WELCOME "WELCOME\n"

    // Data
        typedef struct client_s client_t;

        typedef struct point_s {
            int x;
            int y;
        } point_t;

        // Config
        typedef struct config_s {
            int port;
            int width;
            int height;
            char **team_names;
            int team_count;
            int clients_nb;
            float freq;
        } config_t;

        typedef struct {
            const char *option;
            void (*func)(config_t *, char **, int *);
        } option_mapping_t;

        // Server
        typedef struct incantation_s {
            int *players_id;
            int pos_x;
            int pos_y;
            int level;
            long long start_time;
            struct incantation_s *next;
        } incantation_t;

        typedef struct egg_s {
            int id;
            int player_id;
            char *team_name;
            int pos_x;
            int pos_y;
            bool is_layed;
            long long lay_start_time;
            struct egg_s *next;
        } egg_t;

        typedef struct tile_s {
            int food;
            int linemate;
            int deraumere;
            int sibur;
            int mendiane;
            int phiras;
            int thystame;
        } tile_t;

        typedef struct map_s {
            int width;
            int height;
            long long resources_time;
            tile_t ***tiles;
            egg_t *egg;
            incantation_t *incantation;
        } map_t;

        typedef struct team_s {
            char *name;
            int free_slots;
        } team_t;

        typedef struct server_s {
            int port;
            int sockfd;
            float freq;
            int nb_clients;
            int global_egg_id;
            bool is_ended;
            client_t *clients;
            map_t *map;
            team_t **teams;
        } server_t;

        // Client
        enum orientations {
            NORTH,
            EAST,
            SOUTH,
            WEST
        };

        typedef struct inventory_s {
            int food;
            int linemate;
            int deraumere;
            int sibur;
            int mendiane;
            int phiras;
            int thystame;
        } inventory_t;

        typedef struct command_s {
            char *name;
            void (*function)(server_t *server, client_t *client, char **args);
            char **args;
            float time_limit;
            long long start_time;
            struct command_s *next;
        } command_t;

        typedef struct player_s {
            int id;
            char *team_name;
            int pos_x;
            int pos_y;
            int level;
            enum orientations orientation;
            bool is_available;
            long long food_time;
            inventory_t *inventory;
            command_t *command;
        } player_t;

        struct client_s {
            int sockfd;
            char *buffer;
            bool is_connected;
            bool is_graphic;
            player_t *player;
        };

        enum elements {
            FOOD,
            LINEMATE,
            DERAUMERE,
            SIBUR,
            MENDIANE,
            PHIRAS,
            THYSTAME
        };

    // Project headers
    #include "ai_commands.h"
    #include "broadcasting.h"
    #include "debug.h"
    #include "destroy.h"
    #include "egg.h"
    #include "graphic_commands.h"
    #include "incantation.h"
    #include "init.h"
    #include "logs.h"
    #include "tools.h"

    // Functions
        // Commands
            // command_manager.c
            void command_manager(server_t *server, client_t *client);

            // handler.c
            bool is_waiting_commands(client_t *clients, int nb_clients);
            void handle_command(server_t *server, client_t *client);
            void handle_commands(server_t *server);

            // log.c
            void log_received_command(client_t *client, char **params);

        // client.c
        void handle_clients(server_t *server, fd_set read_fds);
        void remove_disconnected_clients(server_t *server);

        // connection.c
        void accept_new_connection(server_t *server, int *max_fd);

        // loop.c
        void connection_loop(server_t *server);

        // player.c
        void add_player_command(
            player_t *player,
            const ai_command_t *command,
            char **args
        );

        // players.c
        void handle_players(server_t *server);

        // resources.c
        bool is_valid_resource(char *resource);
        bool update_resource(
            int *map_resource,
            int *inventory_resource,
            bool take
        );
        bool find_and_update_resource(
            char *resource,
            tile_t *t,
            inventory_t *i,
            bool take
        );
        bool take_resource(
            tile_t ***tiles,
            inventory_t *inventory,
            int pos[2],
            char *resource
        );
        bool set_resource(
            tile_t ***tiles,
            inventory_t *inventory,
            int pos[2],
            char *resource
        );

        // resources2.c
        int get_resource_id(char *resource);
        void handle_resources(server_t *server);

        // teams.c
        void add_a_free_slot_to_team(server_t *server, char *team_name);
        void remove_a_free_slot_to_team(server_t *server, char *team_name);

        // tile.c
        char *get_tile_content(server_t *server, int x, int y);

        // tile2.c
        char *combine_content(
            char *player_content,
            char *egg_content,
            char *resource_content
        );

        void free_content(
            char *player_content,
            char *egg_content,
            char *resource_content
        );

        // win.c
        void handle_win(server_t *server);

        // zappy_server.c
        int zappy_server(config_t *config);

#endif /* !SERVER_H_ */
