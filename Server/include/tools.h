/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** tools
*/

#ifndef TOOLS_H_
    #define TOOLS_H_

    #include "server.h"

    // Functions
        // angles.c
        double calculate_angle(point_t a, point_t b, point_t c);

        // args.c
        int get_int_arg(char *arg);
        float get_float_arg(char *str);
        int get_team_count_from_args(char **args, int i);
        char **get_teams_names_from_args(
            char **args,
            int i,
            int team_count
        );
        int get_server_port(char *arg);

        // crlf.c
        void remove_crlf(char *str);

        // error.c
        void exit_error(char *str);
        void exit_error_no_perror(char *str);
        void put_error(char *str);

        // getnbr.c
        int getnbr(char const *str);

        // lib.c
        int arrlen(char **arr);
        void free_arr(char **arr);
        char **clone_arr(char **arr);

        // msprintf.c
        char *msprintf(const char *format, ...);

        // parsing.c
        char **parse_args(const char *str);

        // pos.c
        bool check_invalid_pos(server_t *server, char *x, char *y);

        // read_from_fd.c
        char *read_from_fd(int fd, size_t size);

        // send.c
        void send_to_user(client_t *client, char *buffer);
        void send_tile_content_to_user(
            client_t *client,
            tile_t *t,
            int x,
            int y
        );
        void send_to_all_graphics(server_t *server, char *buffer);
        void send_to_all_ai(server_t *server, char *buffer);
        void send_to_all(server_t *server, char *buffer);

        // socket.c
        int init_socket(int port);
        void close_socket(int sockfd);

        // time.c
        long long get_current_time_in_ms(void);

        // usage.c
        int print_server_usage(void);
        int print_server_usage_error(void);

        // write_to_fd.c
        void write_to_fd(int fd, const char *buffer);

#endif /* !TOOLS_H_ */
