/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** lib
*/

#include "server.h"

int arrlen(char **arr)
{
    int i = 0;

    if (!arr)
        return 0;
    for (; arr[i] != NULL; i += 1);
    return i;
}

void free_arr(char **arr)
{
    if (!arr)
        return;
    for (int i = 0; arr[i] != NULL; i += 1)
        free(arr[i]);
    free(arr);
}

char **clone_arr(char **arr)
{
    int size = 0;
    char **new_arr = NULL;

    if (!arr)
        return NULL;
    size = arrlen(arr);
    if (!(new_arr = malloc(sizeof(char *) * (size + 1))))
        exit_error("clone_arr(): malloc()");
    for (int i = 0; arr[i] != NULL; i += 1)
        new_arr[i] = strdup(arr[i]);
    new_arr[size] = NULL;
    return new_arr;
}
