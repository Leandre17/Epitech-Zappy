/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** pokemon_list
*/

#include "Sprite.hpp"
#include "iostream"

void ZappyGUI::Sprite::create_player_texture()
{
    int random = rand() % this->pokemon.size();
    this->m_texture.loadFromFile(this->pokemon[random]);
}

void ZappyGUI::Sprite::create_player_sprite()
{
    this->m_sprite.setTexture(this->m_texture);
    this->m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->m_sprite.setPosition(10, 10);
}

std::string ZappyGUI::Sprite:: getRandomPokemon()
{
    std::vector<std::string> pokemon_list = {
        "Gui/assets/player/bulbi/bulbi.png",
        "Gui/assets/player/abo/abo.png",
        "Gui/assets/player/tortipouss/tortipouss.png",
        "Gui/assets/player/pikachu/pikachu.png"
    };

    std::vector<std::string> pokemon_list2 = {
        "Gui/assets/player/bulbi/herbizarre.png",
        "Gui/assets/player/abo/arbok.png",
        "Gui/assets/player/tortipouss/boskara.png",
        "Gui/assets/player/pikachu/pikachu.png"
    };

    std::vector<std::string> pokemon_list3 = {
        "Gui/assets/player/bulbi/florizarre.png",
        "Gui/assets/player/abo/arbok.png",
        "Gui/assets/player/tortipouss/torterra.png",
        "Gui/assets/player/pikachu/pikachu.png"
    };

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, pokemon_list.size() - 1);
    int random_index = distribution(generator);
    return pokemon_list[random_index];
}
