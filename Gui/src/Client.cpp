/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** client
*/

#include "Client.hpp"

ZappyGUI::Client::Client(std::string ip, int port)
{
    this->ip = ip;
    this->port = port;
    this->socketId = socket(AF_INET, SOCK_STREAM, 0);
    if (this->socketId == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        exit(84);
    }
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_port = htons(port);
    if (inet_pton(AF_INET, "127.0.0.1", &this->serverAddress.sin_addr) <= 0) {
        std::cerr << "Failed to set server address." << std::endl;
        exit(84);
    }
}

void ZappyGUI::Client::connectToServer()
{
    if (connect(this->socketId, (struct sockaddr *)&this->serverAddress, sizeof(this->serverAddress)) < 0) {
        std::cerr << "Failed to connect to server." << std::endl;
        exit(84);
    }
}

void ZappyGUI::Client::closeConnection()
{
    close(this->socketId);
}

void ZappyGUI::Client::send(std::string message)
{
    if (write(this->socketId, message.c_str(), message.length()) < 0) {
        std::cerr << "Failed to send message." << std::endl;
        exit(84);
    }
}

std::string ZappyGUI::Client::receive()
{
    char buffer[READ_BUFFER_SIZE + 1] = {0};
    std::string message;
    ssize_t size = read(this->socketId, buffer, READ_BUFFER_SIZE);

    buffer[size] = '\0';
    message = buffer;
    if (size < 0) {
        std::cerr << "Failed to receive message." << std::endl;
        exit(84);
    } else if (size == READ_BUFFER_SIZE) {
        while (size == READ_BUFFER_SIZE) {
            size = read(this->socketId, buffer, READ_BUFFER_SIZE);
            buffer[size] = '\0';
            message += buffer;
        }
    }
    return message;
}
