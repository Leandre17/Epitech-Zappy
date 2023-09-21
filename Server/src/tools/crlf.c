/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** crlf
*/

#include "server.h"

void remove_crlf(char *str)
{
    int param_length = 0;

    if (!str)
        return;
    param_length = strlen(str);
    if (str[param_length - 1] == '\n')
        str[param_length - 1] = '\0';
    if (str[param_length - 2] == '\r')
        str[param_length - 2] = '\0';
}
