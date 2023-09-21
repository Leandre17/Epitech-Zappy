/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Popup
*/

#pragma once

#include "SFML.hpp"
#include "Ressources.hpp"
#define TEXTURE_PATH_POPUP "Gui/assets/other/popup.png"
#define FONT_PATH_POPUP "Gui/assets/font/base_font.ttf"

namespace ZappyGUI {
    class IPopup {
        public:
            virtual ~IPopup() = default;
            virtual void update(tile_t tile) = 0;
            virtual void update(void) = 0;

            sf::Texture PopUpTexture;
            sf::Sprite PopUpSprite;
            std::vector<sf::Text> PopUpTexts;
            sf::Font PopUpFont;
            bool isVisible;
    };

    class RockPopup : public IPopup {
        public:
            RockPopup();
            ~RockPopup() = default;
            void update(tile_t tile);
            void update(void);
    };

}
