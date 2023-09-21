/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** client
*/

#include "server.h"

void handle_client(server_t *server, client_t *client)
{
    if (!server || !client)
        exit_error("handle_client()");
    client->buffer = read_from_fd(client->sockfd, READ_BUFFER_SIZE);
    if (!client->buffer) {
        client->is_connected = false;
        return close_socket(client->sockfd);
    }
    command_manager(server, client);
    free(client->buffer);
}

void handle_clients(server_t *server, fd_set read_fds)
{
    if (!server || !server->clients || !server->nb_clients)
        return;
    for (int i = 0; i < server->nb_clients; i += 1) {
        if (FD_ISSET(server->clients[i].sockfd, &read_fds))
            handle_client(server, &server->clients[i]);
    }
}

void disconnect_client(server_t *server, client_t *client)
{
    if (!client)
        return;
    if (!client->is_graphic && client->player) {
        send_pdi_to_all_graphics(server, client->player);
        add_a_free_slot_to_team(server, client->player->team_name);
        destroy_player(client->player);
    }
    client->is_connected = false;
    close(client->sockfd);
    printf("Client %d disconnected\n", client->sockfd);
}

void reorganize_clients(server_t *server)
{
    int j = 0;

    if (!server->clients || !server->nb_clients)
        return exit_error("reorganized_clients()");
    for (int i = 0; i < server->nb_clients; i++) {
        if (!server->clients[i].is_connected)
            continue;
        if (i != j)
            server->clients[j] = server->clients[i];
        j += 1;
    }
    server->nb_clients = j;
}

void remove_disconnected_clients(server_t *server)
{
    char buffer[1024] = {0};
    int rv = 0;
    client_t *client = NULL;

    if (!server->clients || !server->nb_clients)
        return;
    for (int i = 0; i < server->nb_clients; i += 1) {
        client = &server->clients[i];
        rv = recv(client->sockfd, buffer,
            sizeof(buffer), MSG_PEEK | MSG_DONTWAIT);
        if (rv == 0 || (rv < 0 && errno != EAGAIN && errno != EWOULDBLOCK))
            disconnect_client(server, client);
    }
    reorganize_clients(server);
}
