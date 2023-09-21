/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Broadcast
*/

#pragma once

#include <string>
#include <vector>
#include "SFML.hpp"
#define FONT_PATH_BROADCAST "Gui/assets/font/base_font.ttf"

namespace ZappyGUI {
    typedef struct Broadcast_s {
        std::string cmds;
        int playerID;
    } Broadcast_t;

    class Message {
        public:
            Message();
            Message(Message &&) = default;
            Message(const Message &) = default;
            Message &operator=(Message &&) = default;
            Message &operator=(const Message &) = default;
            ~Message() = default;

            void AddMessage(std::string msg);
            void ResetMessage();
            void AddBroadcast(Broadcast_t broadcast);
            sf::Text &GetText();
        private:
            std::string FormatMessage(std::string msg);
            void FormatMessageEnd();
            int CountLine();

            std::vector<Broadcast_t> msgs;
            std::string message;
            sf::Text BrText;
            sf::Font BrFont;
    };
}