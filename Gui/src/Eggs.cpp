/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** Eggs
*/

#include "Eggs.hpp"

ZappyGUI::Eggs::Eggs(sf::Texture &texture_egg) {
    sprite_eggs.setTexture(texture_egg);
    texture_eggs = texture_egg;
}

void ZappyGUI::Eggs::setPosition(unsigned int width, unsigned int height) {
    sprite_eggs.setPosition(width, height);
}

void ZappyGUI::Eggs::setPlayerNum(int nb) {this->player_num = nb;}
int ZappyGUI::Eggs::getPlayerNum() { return this->player_num;}
void ZappyGUI::Eggs::setEggNum(int nb) {this->egg_num = nb;}
int ZappyGUI::Eggs::getEggNum() { return this->egg_num;}


void ZappyGUI::Eggs::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &texture_eggs;
    target.draw(sprite_eggs, states);
}
