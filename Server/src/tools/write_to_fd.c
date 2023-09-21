/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** write_to_fd
*/

#include "server.h"

void write_to_fd(int fd, const char *buffer)
{
    if (!buffer)
        exit_error("Buffer is NULL!\n");
    if (write(fd, buffer, strlen(buffer)) < 0)
        exit_error("write()");
}
