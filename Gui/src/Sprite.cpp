/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** sprite
*/

#include "Sprite.hpp"
#include "iostream"

bool ZappyGUI::Sprite::load(const std::string &sprite, sf::Vector2u tileSize,
    unsigned int width, unsigned int height)
{
    if (!m_texture.loadFromFile(sprite))
        return false;
    sf::IntRect rectSprite(0, 0, 32, 32);
    sf::Sprite mm_sprite(m_texture, rectSprite);
    m_sprite = mm_sprite;
    m_sprite.setScale(tileSize.x / m_sprite.getLocalBounds().width, tileSize.y / m_sprite.getLocalBounds().height);
    m_sprite.setPosition(width, height);

    return true;
}

void ZappyGUI::Sprite::set_rect(int top, int left)
{
    sf::IntRect result(top, left, 32, 32);
    m_sprite.setTextureRect(result);
    return;
}

int ZappyGUI::Sprite::get_rect()
{
    return (m_sprite.getTextureRect().top);
}

void ZappyGUI::Sprite::draw(
    sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_sprite, states);

}
