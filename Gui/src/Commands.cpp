/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** commands
*/

#include "Commands.hpp"
#include <iostream>

ZappyGUI::CMD ZappyGUI::Commands::HandleMSZ(std::string line)
{
    int end = line.find(' ');
    std::string cmd = line.substr(0, end);
    line.erase(line.begin(), line.begin() + end + 1);

    this->mapHeight = std::stoi(line);
    this->mapWidth = std::stoi(cmd);
    if (this->mapHeight <= 0 || this->mapWidth <= 0)
        throw std::invalid_argument("Bad map size ( it can't be < 0 )");
    return CMD::MSZ;
}

ZappyGUI::CMD ZappyGUI::Commands::HandleSGT(std::string line)
{
    this->timeUnit = std::stoi(line);
    if (this->timeUnit < 0)
        throw std::invalid_argument("Bad time unit ( it can't be < 0 )");
    return CMD::SGT;
}

ZappyGUI::CMD ZappyGUI::Commands::HandleBCT(std::string line)
{
    int end = line.find(' ');

    std::string X = line.substr(0, end);
    line.erase(line.begin(), line.begin() + end + 1);
    end = line.find(' ');
    std::string Y = line.substr(0, end);
    line.erase(line.begin(), line.begin() + end + 1);
    end = line.find(' ');
    std::string Q0 = line.substr(0, end);
    line.erase(line.begin(), line.begin() + end + 1);
    end = line.find(' ');
    std::string Q1 = line.substr(0, end);
    line.erase(line.begin(), line.begin() + end + 1);
    end = line.find(' ');
    std::string Q2 = line.substr(0, end);
    line.erase(line.begin(), line.begin() + end + 1);
    end = line.find(' ');
    std::string Q3 = line.substr(0, end);
    line.erase(line.begin(), line.begin() + end + 1);
    end = line.find(' ');
    std::string Q4 = line.substr(0, end);
    line.erase(line.begin(), line.begin() + end + 1);
    end = line.find(' ');
    std::string Q5 = line.substr(0, end);
    line.erase(line.begin(), line.begin() + end + 1);
    std::string Q6 = line;
    if (std::stoi(Q0) < 0 || std::stoi(Q1) < 0 || std::stoi(Q2) < 0 || std::stoi(Q3) < 0 || std::stoi(Q4) < 0 || std::stoi(Q5) < 0 || std::stoi(Q6) < 0)
        throw std::invalid_argument("Bad quantity ( it can't be < 0 )");
    this->laMap[std::tuple<int, int>{std::stoi(X), std::stoi(Y)}] = {
        .food = std::stoi(Q0),
        .linemate = std::stoi(Q1),
        .deraumere = std::stoi(Q2),
        .sibur = std::stoi(Q3),
        .mendiane = std::stoi(Q4),
        .phiras = std::stoi(Q5),
        .thystame = std::stoi(Q6)
    };
    return CMD::BCT;
}

ZappyGUI::CMD ZappyGUI::Commands::HandleTNA(std::string line)
{
    this->teamName.push_back(line);
    return CMD::TNA;
}

ZappyGUI::CMD ZappyGUI::Commands::HandlePBC(std::string line)
{
    int end = line.find(' ');
    std::string id = line.substr(0, end);
    line.erase(line.begin(), line.begin() + end + 1);

    this->display.broadcast.AddBroadcast({line, std::stoi(id)});
    return CMD::PBC;
}

ZappyGUI::CMD ZappyGUI::Commands::HandlePPO(std::string line)
{
    this->display.broadcast.AddMessage(std::string("ppo") + " " + line);

    int end = line.find(' ');
    std::string n_str = line.substr(0, end);
    this->poke_n = std::stoi(n_str);
    line.erase(line.begin(), line.begin() + end + 1);

    end = line.find(' ');
    std::string x_str = line.substr(0, end);
    this->poke_x = std::stoi(x_str);
    line.erase(line.begin(), line.begin() + end + 1);

    end = line.find(' ');
    std::string y_str = line.substr(0, end);
    this->poke_y = std::stoi(y_str);
    line.erase(line.begin(), line.begin() + end + 1);

    end = line.find(' ');
    std::string o_str = line.substr(0, end);
    this->poke_o = std::stoi(o_str);
    line.erase(line.begin(), line.begin() + end + 1);

    this->moving = true;
    return CMD::PPO;
}

ZappyGUI::CMD ZappyGUI::Commands::HandlePNW(std::string line)
{
    this->display.broadcast.AddMessage(std::string("pnw") + " " + line);
    int end = line.find(' ');
    std::string n_str = line.substr(0, end);
    this->poke_n = std::stoi(n_str);
    line.erase(line.begin(), line.begin() + end + 1);

    end = line.find(' ');
    std::string x_str = line.substr(0, end);
    this->poke_x = std::stoi(x_str);
    line.erase(line.begin(), line.begin() + end + 1);

    end = line.find(' ');
    std::string y_str = line.substr(0, end);
    this->poke_y = std::stoi(y_str);
    line.erase(line.begin(), line.begin() + end + 1);

    end = line.find(' ');
    std::string o_str = line.substr(0, end);
    this->poke_o = std::stoi(o_str);
    line.erase(line.begin(), line.begin() + end + 1);

    end = line.find(' ');
    std::string l_str = line.substr(0, end);
    this->poke_l = std::stoi(l_str);
    line.erase(line.begin(), line.begin() + end + 1);

    end = line.find(' ');
    this->team_name = line.substr(0, end);
    line.erase(line.begin(), line.begin() + end + 1);

    isConnection = true;

    return CMD::PNW;
}

ZappyGUI::CMD ZappyGUI::Commands::HandlePDI(std::string line)
{
    std::cout << "PDI " << line << std::endl;
    int end = line.find(' ');
    std::string n_str = line.substr(0, end);
    this->poke_leave = std::stoi(n_str);
    this->leaving = true;
    return CMD::PDI;
}

ZappyGUI::CMD ZappyGUI::Commands::HandleENW(std::string line)
{
    std::cout << "ENW " << line << std::endl;
    ZappyGUI::Eggs egg{this->display.egg_texture};
    int end = line.find(' ');
    std::string egg_num = line.substr(0, end);
    int x = 0;
    int y = 0;

    this->display.broadcast.AddMessage("ENW " + line);
    line.erase(line.begin(), line.begin() + end + 1);
    end = line.find(' ');
    egg.setPlayerNum(std::stoi(line.substr(0, end)));
    line.erase(line.begin(), line.begin() + end + 1);
    end = line.find(' ');
    x = std::stoi(line.substr(0, end));
    line.erase(line.begin(), line.begin() + end + 1);
    y = std::stoi(line);
    egg.setPosition(x * this->display.window_size.x, y * this->display.window_size.y);
    this->display.eggs.push_back(egg);
    return CMD::ENW;
}

ZappyGUI::CMD ZappyGUI::Commands::HandleEDI(std::string line)
{
    std::cout << "EDI " << line << std::endl;
    int egg_nb = std::stoi(line);

    for (std::size_t i = 0; i < this->display.eggs.size(); i++) {
        if (this->display.eggs[i].getEggNum() == egg_nb) {
            this->display.eggs.erase(this->display.eggs.begin() + i);
            return CMD::EDI;
        };
    }
    return CMD::NONE;
}

ZappyGUI::CMD ZappyGUI::Commands::HandleEBO(std::string line)
{
    std::cout << "EBO " << line << std::endl;
    this->display.broadcast.AddMessage("EGG " + line + " Hatched");

    HandleEDI(line);
    return CMD::EBO;
}

ZappyGUI::CMD ZappyGUI::Commands::HandlePIC(std::string line)
{
    std::cout << "PIC " << line << std::endl;
    this->isPic = true;
    return CMD::PIC;
}

ZappyGUI::CMD ZappyGUI::Commands::HandlePIE(std::string line)
{
    std::cout << "PIE " << line << std::endl;
    this->isPic = false;
    return CMD::PIE;
}

ZappyGUI::CMD ZappyGUI::Commands::HandlePLV(std::string line)
{
    std::cout << "PLV " << line << std::endl;
    return CMD::PLV;    
}

ZappyGUI::CMD ZappyGUI::Commands::HandleSEG(std::string line)
{
    std::cout << "SEG " << line << std::endl;
    return CMD::SEG;    
}

ZappyGUI::CMD ZappyGUI::Commands::HandleLine(std::string line)
{
    int end = line.find(' ');
    std::string cmd = line.substr(0, end);

    line.erase(line.begin(), line.begin() + end + 1);
    if (cmd == "WELCOME" || cmd.length() != 3) return CMD::NONE;
    if (cmd == "msz") return HandleMSZ(line);
    if (cmd == "sgt") return HandleSGT(line);
    if (cmd == "bct") return HandleBCT(line);
    if (cmd == "tna") return HandleTNA(line);
    if (cmd == "tna") return HandleTNA(line);
    if (cmd == "pbc") return HandlePBC(line);
    if (cmd == "ppo") return HandlePPO(line);
    if (cmd == "pdi") return HandlePDI(line);
    if (cmd == "pnw") return HandlePNW(line);
    if (cmd == "enw") return HandleENW(line);
    if (cmd == "edi") return HandleEDI(line);
    if (cmd == "ebo") return HandleEBO(line);
    if (cmd == "pic") return HandlePIC(line);
    if (cmd == "pie") return HandlePIE(line);
    if (cmd == "plv") return HandlePLV(line);
    if (cmd == "seg") return HandleSEG(line);
    if (cmd == "pex") std::cout << "PEX " << std::endl;
    // std::cout << cmd << " " << line << "\n";
    // this->display.broadcast.AddMessage(cmd + " " + line);
    return CMD::NONE;
}

ZappyGUI::CMD ZappyGUI::Commands::RecuperateInfo(std::string lines)
{
    int end = lines.find('\n');
    ZappyGUI::CMD last = CMD::NONE;

    while (end != -1) {
        last = HandleLine(lines.substr(0, end));
        lines.erase(lines.begin(), lines.begin() + end + 1);
        end = lines.find('\n');
    }
    return last;
}

int ZappyGUI::Commands::GetTimeUnit()
{
    return this->timeUnit;
}

void ZappyGUI::Commands::SetTimeUnit(int time) {
    this->timeUnit = time;
}
