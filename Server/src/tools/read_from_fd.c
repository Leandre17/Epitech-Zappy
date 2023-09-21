/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** read_from_fd
*/

#include "server.h"

char *read_from_fd(int fd, size_t size)
{
    char *buffer = malloc(sizeof(char) * size);
    ssize_t read_size = 0;

    if (buffer == NULL)
        exit_error("Malloc failed!");
    read_size = read(fd, buffer, size);
    if (read_size == -1) {
        free(buffer);
        return NULL;
    }
    buffer[read_size] = '\0';
    return buffer;
}
