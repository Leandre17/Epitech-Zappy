/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** client
*/

#pragma once

#include "GUI.hpp"
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define READ_BUFFER_SIZE 1024

namespace ZappyGUI {
    class Client {
        public:
            Client(std::string ip, int port);
            ~Client() = default;
            void connectToServer();
            void closeConnection();
            void send(std::string message);
            std::string receive();

        private:
            int socketId;
            struct sockaddr_in serverAddress;
            std::string ip;
            int port;
    };
}
