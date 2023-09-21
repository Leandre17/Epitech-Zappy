/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Display
*/

#include "Commands.hpp"

void ZappyGUI::Commands::InitilizeDisplay() {
    std::string teams;

    if (this->mapHeight <= 0 || this->mapWidth <= 0)
        throw std::invalid_argument("Bad map size or map size not inisialized");
    this->display.window_size = (sf::Vector2u){static_cast<unsigned int>(1000) / this->mapWidth, static_cast<unsigned int>(750) / this->mapHeight};
    this->display.tiles.load("Gui/assets/arena/ms.png", this->display.window_size, this->mapWidth, this->mapHeight);
    this->display.window.create(sf::VideoMode(1500, 800), "Zappy");
    
    this->display.res.generateRocks(this->laMap, {this->display.window_size.x / static_cast<float>(64), this->display.window_size.y / static_cast<float>(64)});
    this->display.team_font.loadFromFile(PATH_FONT_TEAM);
    this->display.team_text.setFont(this->display.team_font);
    this->display.team_text.setPosition({10, 750});
    for (auto x : this->teamName)
        teams = teams + "    " + x + "    ";
    this->display.team_text.setString(teams);
    this->display.egg_texture.loadFromFile(PATH_TEXTURE_EGGS);
}

void ZappyGUI::Commands::Display() {
    this->display.window.clear();
    this->display.window.draw(this->display.tiles);
    for (auto x : this->display.res.getRocks())
        this->display.window.draw(x);
    if (this->display.pop.isVisible) {
        this->display.window.draw(this->display.pop.PopUpSprite);
        for (auto x : this->display.pop.PopUpTexts)
            this->display.window.draw(x);
    }
    this->display.window.draw(this->display.team_text);
    this->display.window.draw(this->display.broadcast.GetText());
    // this->display.window.display();
    for (auto x : this->display.eggs)
        this->display.window.draw(x);
}

sf::RenderWindow &ZappyGUI::Commands::getWindow() {return this->display.window;}
sf::Vector2u ZappyGUI::Commands::getWindowSize() const {return display.window_size;}
sf::Vector2f ZappyGUI::Commands::getMousePos() {return (sf::Vector2f)sf::Mouse::getPosition(this->getWindow());}

void ZappyGUI::Commands::checkClicque(int x, int y) {
    int realposx = (x / this->display.window_size.x);
    int realposy = (y / this->display.window_size.y);

    if (realposx < 0 || realposx > this->mapHeight - 1 || realposy < 0 || realposy > this->mapWidth - 1)
        this->display.pop.update();
    else
        this->display.pop.update(this->laMap[{realposx, realposy}]);
}

