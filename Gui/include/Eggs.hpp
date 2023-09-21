/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** Eggs
*/

#pragma once
#include "SFML.hpp"

namespace ZappyGUI {
    class Eggs : public sf::Drawable, public sf::Transformable {
        public:
            Eggs() = default;
            Eggs(sf::Texture &texture_egg);
            ~Eggs() = default;
            void setPosition(unsigned int width, unsigned int height);
            void setPlayerNum(int nb);
            int getPlayerNum();
            void setEggNum(int nb);
            int getEggNum();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        private:
            sf::Texture texture_eggs;
            sf::Sprite sprite_eggs;
            sf::Vector2u pos;
            std::string team_name;
            int player_num;
            int egg_num;
    };
} // namespace ZappyGUI
