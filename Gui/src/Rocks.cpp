/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Rocks
*/

#include "Rocks.hpp"
#include <iostream>

void ZappyGUI::Rocks::setPosition(unsigned int width, unsigned int height)
{
    m_sprite.setPosition(width, height);
}

void ZappyGUI::Rocks::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_sprite, states);
}

void ZappyGUI::Rocks::setTexture(sf::Texture &texture) { 
    m_texture = texture;
    m_sprite.setTexture(texture, true);
}

sf::Texture &ZappyGUI::Rocks::getTexture() { return m_texture; }
