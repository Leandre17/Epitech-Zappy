/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** send_receive
*/

#include "tests.h"

void send_command(const char *command) {
    cr_assert_eq(
        send(sockfd, command, strlen(command), 0),
        strlen(command),
        "Send failed"
    );
}

char *receive_response() {
    char *response = calloc(READ_BUFFER_SIZE, sizeof(char));

    cr_assert_neq(
        recv(sockfd, response, READ_BUFFER_SIZE, 0),
        -1,
        "Receive failed"
    );
    return response;
}

void check_response(const char *expected_response)
{
    char *response = receive_response();
    char *error = msprintf("Response mismatch: expected '%s', got '%s'",
        expected_response, response);

    cr_assert_eq(
        strncmp(response, expected_response, strlen(expected_response)),
        0,
        "%s", error
    );
    free(error);
}

void send_command_and_check_response(
    const char *command,
    const char *expected_response
)
{
    send_command(command);
    check_response(expected_response);
}

void identify_user_as_team(const char *team_name)
{
    send_command(team_name);

    // Nb of free slots
    receive_response();

    // Player position
    receive_response();
}
