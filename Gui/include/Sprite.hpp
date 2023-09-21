/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** Sprite
*/

#pragma once

#include "SFML.hpp"
#include <random>

namespace ZappyGUI {
    class Sprite : public sf::Drawable, public sf::Transformable {
        public:
            bool load(const std::string& sprite, sf::Vector2u tileSize, unsigned int width, unsigned int height);
            void set_rect(int top, int left);
            int get_rect();
            std::string getRandomPokemon();
            void create_player_texture();
            void create_player_sprite();

        private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            std::vector<std::string> pokemon;
            sf::VertexArray m_vertices;
            sf::Texture m_texture;
            sf::Sprite m_sprite;
    };
}
