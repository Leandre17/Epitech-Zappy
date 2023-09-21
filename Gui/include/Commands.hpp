/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** Commands
*/

#pragma once

#include <string>
#include <vector>
#include <map>
#include "TileMap.hpp"
#include "Ressources.hpp"
#include "Popup.hpp"
#include "Eggs.hpp"
#include "Broadcast.hpp"

#define PATH_FONT_TEAM "Gui/assets/font/base_font.ttf"

namespace ZappyGUI {
    typedef struct display_s {
        ZappyGUI::TileMap tiles;
        ZappyGUI::Ressources res;
        sf::RenderWindow window;
        sf::Vector2u window_size;
        ZappyGUI::RockPopup pop;
        ZappyGUI::Message broadcast;
        sf::Font team_font;
        sf::Texture egg_texture;
        sf::Text team_text;
        std::vector<ZappyGUI::Eggs> eggs;
    } display_t;

    enum class CMD {MSZ, SGT, TNA, BCT, PBC, PPO, PNW, PDI, ENW, EDI, EBO, PIC, PIE, PLV, SEG, NONE};

    class Commands {
        public:
            Commands() = default;
            ~Commands() = default;
            CMD RecuperateInfo(std::string line);
            CMD HandleLine(std::string line);
            CMD HandleMSZ(std::string line);
            CMD HandleSGT(std::string line);
            CMD HandleTNA(std::string line);
            CMD HandleBCT(std::string line);
            CMD HandlePBC(std::string line);
            CMD HandlePPO(std::string line);
            CMD HandlePNW(std::string line);
            CMD HandlePDI(std::string line);
            CMD HandleENW(std::string line);
            CMD HandleEDI(std::string line);
            CMD HandleEBO(std::string line);
            CMD HandlePIC(std::string line);
            CMD HandlePIE(std::string line);
            CMD HandlePLV(std::string line);
            CMD HandleSEG(std::string line);

            void InitilizeDisplay();
            void Display();
            void checkClicque(int x, int y);
            sf::RenderWindow &getWindow();
            sf::Vector2u getWindowSize() const;
            sf::Vector2f getMousePos();
            int GetTimeUnit();
            void SetTimeUnit(int time);
            int poke_x;
            int poke_y;
            int poke_o;
            int poke_l;
            int poke_n;
            int poke_leave;
            std::string team_name;
            bool leaving;
            bool isConnection;
            bool moving;
            bool isPic;
        private:
            display_t display;
            int mapWidth;
            int mapHeight;
            int timeUnit;
            std::vector<std::string> teamName;
            std::map<std::tuple<int, int>, tile_t> laMap;

    };
}
