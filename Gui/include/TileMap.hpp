/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** tile_map
*/

#pragma once

#include "SFML.hpp"

namespace ZappyGUI {
    class TileMap : public sf::Drawable, public sf::Transformable {
        public:
            bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height);
        private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            sf::VertexArray m_vertices;
            sf::Texture m_tileset;
    };
}
