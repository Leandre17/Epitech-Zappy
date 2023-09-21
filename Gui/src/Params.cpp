/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** Params
*/

#include "GUI.hpp"
#include "Params.hpp"
#include <iostream>

ZappyGUI::Params::Params(int argc, char **argv)
{
    if (argc == 1) {
        this->port = 4242;
        this->ip = "localhost";
        return;
    }
    if (argc == 2 && (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help"))
        exit(this->printUsage());
    if (argc < 3) {
        std::cerr << "Invalid arguments." << std::endl;
        exit(ERROR);
    }
    this->port = std::stoi(argv[2]);
    this->ip = argc == 5 ? argv[4] : "localhost";
}

int ZappyGUI::Params::printUsage()
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport is the port number" << std::endl;
    std::cout << "\tmachine is the name of the machine; localhost by default" << std::endl;
    return (SUCCESS);
}

int ZappyGUI::Params::getPort()
{
    return this->port;
}

std::string const &ZappyGUI::Params::getIp()
{
    return this->ip;
}
