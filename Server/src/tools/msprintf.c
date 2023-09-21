/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** msprintf
*/

#include "server.h"

char *msprintf(const char *format, ...)
{
    char *str = NULL;
    va_list args;
    int len = 0;

    va_start(args, format);
    len = vsnprintf(NULL, 0, format, args);
    va_end(args);
    if (len >= 0) {
        str = malloc(len + 1);
        if (str) {
            va_start(args, format);
            vsnprintf(str, len + 1, format, args);
            va_end(args);
        }
    }
    return str;
}
