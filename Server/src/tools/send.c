/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** send
*/

#include "server.h"

void send_to_user(client_t *client, char *buffer)
{
    if (!client)
        exit_error("send_to_user()");
    if (!buffer)
        return;
    if (send(client->sockfd, buffer, strlen(buffer), 0) < 0)
        exit_error("send()");
    char *buffer_to_print = strdup(buffer);
    if (buffer_to_print[strlen(buffer_to_print) - 1] == '\n') {
        buffer_to_print[strlen(buffer_to_print) - 1] = '\0';
        printf("Send to client %d:\n\"%s\\n\"\n",
            client->sockfd, buffer_to_print);
    } else
        printf("Send to client %d:\n\"%s\"\n",
            client->sockfd, buffer_to_print);
    free(buffer_to_print);
    printf("%s\n", SEPARATOR);
}

void send_tile_content_to_user(
    client_t *client,
    tile_t *t,
    int x,
    int y
)
{
    char *output = NULL;

    if (!client || !t)
        exit_error("send_tile_content_to_user()");
    output = msprintf("bct %d %d %d %d %d %d %d %d %d\n",
        x,
        y,
        t->food,
        t->linemate,
        t->deraumere,
        t->sibur,
        t->mendiane,
        t->phiras,
        t->thystame
    );
    send_to_user(client, output);
    free(output);
}

void send_to_all_graphics(server_t *server, char *buffer)
{
    if (!server || !server->clients || !server->nb_clients || !buffer)
        exit_error("send_to_all_graphics()");
    for (int i = 0; i < server->nb_clients; i += 1) {
        if (server->clients[i].is_graphic)
            send_to_user(&server->clients[i], buffer);
    }
}

void send_to_all_ai(server_t *server, char *buffer)
{
    if (!server || !server->clients || !server->nb_clients || !buffer)
        exit_error("send_to_all_ai()");
    for (int i = 0; i < server->nb_clients; i += 1) {
        if (!server->clients[i].is_graphic && server->clients[i].player &&
            server->clients[i].player->team_name)
            send_to_user(&server->clients[i], buffer);
    }
}

void send_to_all(server_t *server, char *buffer)
{
    if (!server || !server->clients || !server->nb_clients || !buffer)
        exit_error("send_to_all()");
    for (int i = 0; i < server->nb_clients; i += 1) {
        send_to_user(&server->clients[i], buffer);
    }
}
