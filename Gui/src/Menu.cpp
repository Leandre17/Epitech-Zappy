/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** menu
*/

#include "Menu.hpp"

ZappyGUI::Menu::Menu() {
    this->exit_texture.loadFromFile(PATH_TEXTURE_EXIT);
    this->exit_sprite.setTexture(this->exit_texture);
    this->menu_texture.loadFromFile(PATH_TEXTURE_MENU);
    this->menu_sprite.setTexture(this->menu_texture);
    this->setting_texture.loadFromFile(PATH_TEXTURES_SETTING);
    this->setting_sprite.setTexture(this->setting_texture);
    this->onMenu = true;
    this->exit_sprite.setPosition({1400, 0});
}

void ZappyGUI::Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &menu_texture;
    target.draw(menu_sprite, states);
    states.texture = &setting_texture;
    target.draw(setting_sprite, states);
    states.texture = &exit_texture;
    target.draw(exit_sprite, states);
}

sf::FloatRect ZappyGUI::Menu::getSettings() {
    sf::FloatRect rect = this->setting_sprite.getGlobalBounds();
    return rect;
}

sf::FloatRect ZappyGUI::Menu::getExit() {
    sf::FloatRect rect = this->exit_sprite.getGlobalBounds();
    return rect;
}

ZappyGUI::SettingMenu::SettingMenu() {
    this->exit_texture.loadFromFile(PATH_TEXTURE_SEXIT);
    this->plus_texture.loadFromFile(PATH_TEXTURE_PLUS);
    this->moins_texture.loadFromFile(PATH_TEXTURE_MOINS);
    this->ret_texture.loadFromFile(PATH_TEXTURE_RET);
    this->exit_sprite.setTexture(this->exit_texture);
    this->moins_sprite.setTexture(this->moins_texture);
    this->plus_sprite.setTexture(this->plus_texture);
    this->ret_sprite.setTexture(this->ret_texture);
    menu_font.loadFromFile(PATH_FONT_MENU);
    menu_text.setFont(menu_font);
    this->exit_sprite.setPosition({1280, 0});
    this->moins_sprite.setPosition({690, 350});
    this->plus_sprite.setPosition({780, 350});
    this->menu_text.setPosition({700, 300});
    this->onSetting = false;
}

void ZappyGUI::SettingMenu::DrawMenu(sf::RenderWindow &window, int time) {
    window.clear();
    window.draw(exit_sprite);
    window.draw(moins_sprite);
    window.draw(plus_sprite);
    window.draw(ret_sprite);
    menu_text.setString("Time Unit : " + std::to_string(time));
    window.draw(menu_text);
    window.display();
}

sf::FloatRect ZappyGUI::SettingMenu::getSpriteMoins() {return this->moins_sprite.getGlobalBounds();}
sf::FloatRect ZappyGUI::SettingMenu::getSpritePlus() {return this->plus_sprite.getGlobalBounds();}
sf::FloatRect ZappyGUI::SettingMenu::getRet() {return this->ret_sprite.getGlobalBounds();}

sf::FloatRect ZappyGUI::SettingMenu::getExit() {
    sf::FloatRect rect = this->exit_sprite.getGlobalBounds();
    return rect;
}
