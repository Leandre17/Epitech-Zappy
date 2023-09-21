/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** Menu
*/

#pragma once

#include "SFML.hpp"

#define PATH_TEXTURE_MENU "Gui/assets/menu/menu.png"
#define PATH_TEXTURE_EXIT "Gui/assets/menu/bouton_exit.png"
#define PATH_TEXTURE_SEXIT "Gui/assets/menu/exit2.png"
#define PATH_TEXTURES_SETTING "Gui/assets/menu/bouton_setting.png"
#define PATH_TEXTURE_MOINS "Gui/assets/menu/-.png"
#define PATH_TEXTURE_PLUS "Gui/assets/menu/+.png"
#define PATH_TEXTURE_RET "Gui/assets/menu/retour.png"
#define PATH_FONT_MENU "Gui/assets/font/base_font.ttf"
#define MOUSECLICKED event.type == sf::Event::MouseButtonPressed

namespace ZappyGUI {
    class Menu : public sf::Drawable, public sf::Transformable {
        public:
            Menu();
            ~Menu() = default;
            void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            sf::FloatRect getSettings();
            sf::FloatRect getExit();
            bool onMenu;
        private:
            sf::Texture menu_texture;
            sf::Texture exit_texture;
            sf::Texture setting_texture;
            sf::Sprite menu_sprite;
            sf::Sprite exit_sprite;
            sf::Sprite setting_sprite;
    };

    class SettingMenu {
        public:
            SettingMenu();
            ~SettingMenu() = default;
            void DrawMenu(sf::RenderWindow &window, int time);
            sf::FloatRect getSpriteMoins();
            sf::FloatRect getSpritePlus();
            sf::FloatRect getExit();
            sf::FloatRect getRet();
            bool onSetting;
        private:
            sf::Texture exit_texture;
            sf::Sprite exit_sprite;
            sf::Text menu_text;
            sf::Font menu_font;
            sf::Texture moins_texture;
            sf::Sprite moins_sprite;
            sf::Texture plus_texture;
            sf::Sprite plus_sprite;
            sf::Texture ret_texture;
            sf::Sprite ret_sprite;
    };

}

