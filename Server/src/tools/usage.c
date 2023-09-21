/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** usage
*/

#include "server.h"

int print_server_usage(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height "
        "-n name1 name2 ... -c clientsNb -f freq\n");
    printf("\tport is the port number\n");
    printf("\twidth is the width of the world\n");
    printf("\theight is the height of the world\n");
    printf("\tnameX is the name of the team X\n");
    printf("\tclientsNb is the number of authorized clients per team\n");
    printf("\tfreq is the reciprocal of time unit for execution of actions");
    printf("\n");
    return SUCCESS;
}

int print_server_usage_error(void)
{
    fprintf(stderr, "USAGE: ./zappy_server -p port -x width -y height "
        "-n name1 name2 ... -c clientsNb -f freq\n");
    fprintf(stderr, "\tport is the port number\n");
    fprintf(stderr, "\twidth is the width of the world\n");
    fprintf(stderr, "\theight is the height of the world\n");
    fprintf(stderr, "\tnameX is the name of the team X\n");
    fprintf(stderr, "\tclientsNb is the number of authorized clients per ");
    fprintf(stderr, "team\n\tfreq is the reciprocal of time unit for ");
    fprintf(stderr, "execution of actions\n");
    return ERROR;
}
