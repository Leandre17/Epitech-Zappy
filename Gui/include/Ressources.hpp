/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Ressources
*/

#pragma once

#include "Rocks.hpp"
#include <vector>
#include <memory>

namespace ZappyGUI {
    typedef struct tile_s {
            int food;
            int linemate;
            int deraumere;
            int sibur;
            int mendiane;
            int phiras;
            int thystame;
    } tile_t;

    class Ressources {
        public:
            Ressources();
            ~Ressources() = default;
            ZappyGUI::Rocks generateFoods(int x, int y, sf::Vector2f size);
            ZappyGUI::Rocks generateLinemate(int x, int y, sf::Vector2f size);
            ZappyGUI::Rocks generateMendiane(int x, int y, sf::Vector2f size);
            ZappyGUI::Rocks generateDeraumere(int x, int y, sf::Vector2f size);
            ZappyGUI::Rocks generatePhiras(int x, int y, sf::Vector2f size);
            ZappyGUI::Rocks generateSibur(int x, int y, sf::Vector2f size);
            ZappyGUI::Rocks generateThystame(int x, int y, sf::Vector2f size);
            void generateRocks(std::map<std::tuple<int, int>, tile_t> map, sf::Vector2f size);
            std::vector<ZappyGUI::Rocks> &getRocks();
        private:
            std::vector<ZappyGUI::Rocks> all_rocks;
            sf::Texture foodTexture;
            sf::Texture linemateTexture;
            sf::Texture mendianeTexture;
            sf::Texture deraumereTexture;
            sf::Texture phirasTexture;
            sf::Texture siburTexture;
            sf::Texture thystameTexture;
    };
}
