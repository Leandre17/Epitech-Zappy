/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** tests
*/

#ifndef TESTS_H_
    #define TESTS_H_

    #include "server.h"
    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

    // Global variables
    extern int sockfd;
    extern struct sockaddr_in server_addr;

    #define SERVER_IP "127.0.0.1"
    #define SERVER_PORT 4242
    #define TEST_TEAM "BLUE\n"

    // Utils
        // send_receive.c
        void send_command(const char *command);
        char *receive_response();
        void check_response(const char *expected_response);
        void send_command_and_check_response(
            const char *command,
            const char *expected_response
        );
        void identify_user_as_team(const char *team_name);

        // setup.c
        void setup(void);

        // teardown.c
        void teardown(void);


#endif /* !TESTS_H_ */
