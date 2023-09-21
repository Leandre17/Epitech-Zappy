/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** setup
*/

#include "tests.h"

void setup(void)
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    cr_assert_neq(sockfd, -1, "Socket creation failed");
    cr_assert_eq(connect(
        sockfd,
        (struct sockaddr *)&server_addr,
        sizeof(server_addr)),
        0,
        "Connection failed"
    );
    check_response(API_WELCOME);
}
