/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Popup
*/

#include "Popup.hpp"

ZappyGUI::RockPopup::RockPopup()
{
    sf::Text text1;

    this->PopUpTexture.loadFromFile(TEXTURE_PATH_POPUP);
    this->PopUpSprite.setTexture(this->PopUpTexture);
    this->PopUpSprite.setPosition(1060, 20);
    this->PopUpFont.loadFromFile(FONT_PATH_POPUP);
    text1.setFont(this->PopUpFont);
    text1.setFillColor(sf::Color::Black);

    text1.setString("Food : ");
    text1.setPosition({1070, 60});
    this->PopUpTexts.push_back(text1);

    text1.setPosition({1070, 110});
    text1.setString("Linemate : ");
    this->PopUpTexts.push_back(text1);
    text1.setString("Deraumere : ");
    text1.setPosition({1070, 160});
    this->PopUpTexts.push_back(text1);
    text1.setString("sibur : ");
    text1.setPosition({1070, 210});
    this->PopUpTexts.push_back(text1);
    text1.setString("mendiane : ");
    text1.setPosition({1070, 260});
    this->PopUpTexts.push_back(text1);
    text1.setString("phiras : ");
    text1.setPosition({1070, 310});
    this->PopUpTexts.push_back(text1);
    text1.setString("thystame : ");
    text1.setPosition({1070, 360});
    this->PopUpTexts.push_back(text1);
    isVisible = false;
}

void ZappyGUI::RockPopup::update(ZappyGUI::tile_t tile) {
    this->PopUpTexts[0].setString("Food : " + std::to_string(tile.food));
    this->PopUpTexts[1].setString("Linemate : " + std::to_string(tile.linemate));
    this->PopUpTexts[2].setString("Deraumere : " + std::to_string(tile.deraumere));
    this->PopUpTexts[3].setString("sibur : " + std::to_string(tile.sibur));
    this->PopUpTexts[4].setString("mendiane : " + std::to_string(tile.mendiane));
    this->PopUpTexts[5].setString("phiras : " + std::to_string(tile.phiras));
    this->PopUpTexts[6].setString("thystame : " + std::to_string(tile.thystame));
    isVisible = true;
}

void ZappyGUI::RockPopup::update(void) {
    isVisible = false;
}
