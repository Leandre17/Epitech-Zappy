/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** error
*/

#include "server.h"

void exit_error(char *str)
{
    perror(str);
    exit(ERROR);
}
