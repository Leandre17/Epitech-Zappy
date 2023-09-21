/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** Params
*/

#pragma once
#include <string>

namespace ZappyGUI {
    class Params {
        public:
            Params(int argc, char **argv);
            ~Params() = default;
            int printUsage();
            int getPort();
            std::string const &getIp();

        private:
            int port;
            std::string ip;
    };
}
