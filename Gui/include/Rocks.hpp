/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Rocks
*/

#pragma once
#include "SFML.hpp"
#include  <cstdlib>

namespace ZappyGUI {
    class Rocks : public sf::Drawable, public sf::Transformable {
        public:
            void setPosition(unsigned int width, unsigned int height);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            void setTexture(sf::Texture &texture);
            sf::Texture &getTexture();
        private:
            sf::Texture m_texture;
            sf::Sprite m_sprite;
    };
}
