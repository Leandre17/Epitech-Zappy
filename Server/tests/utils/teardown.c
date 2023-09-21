/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** teardown
*/

#include "tests.h"

void teardown(void)
{
    close_socket(sockfd);
}
