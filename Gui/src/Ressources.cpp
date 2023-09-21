/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Ressources
*/

#include "Ressources.hpp"
#include "GUI.hpp"
#include <iostream>

ZappyGUI::Ressources::Ressources() {
    int loaded = 0;

    loaded += foodTexture.loadFromFile(TEXTURE_PATH_FOOD);
    loaded += linemateTexture.loadFromFile(TEXTURE_PATH_LINEMATE);
    loaded += mendianeTexture.loadFromFile(TEXTURE_PATH_MENDIANE);
    loaded += deraumereTexture.loadFromFile(TEXTURE_PATH_DERAUMERE);
    loaded += phirasTexture.loadFromFile(TEXTURE_PATH_PHIRAS);
    loaded += siburTexture.loadFromFile(TEXTURE_PATH_SIBUR);
    loaded += thystameTexture.loadFromFile(TEXTURE_PATH_THYSTAME);
    if (loaded != 7) {
        std::cout << "Failled to load all texture : \n";
        std::cout << "Load : " << loaded << "/7 Texture\n";
    }
}

ZappyGUI::Rocks ZappyGUI::Ressources::generateFoods(int x, int y, sf::Vector2f size) {
    ZappyGUI::Rocks rock;

    rock.setScale(size);
    rock.setPosition(x + rand() % 48, y + rand() % 48);
    rock.setTexture(foodTexture);
    return rock;
}

ZappyGUI::Rocks ZappyGUI::Ressources::generateLinemate(int x, int y, sf::Vector2f size) {
    ZappyGUI::Rocks rock;

    rock.setScale(size);
    rock.setPosition(x + rand() % 48, y + rand() % 48);
    rock.setTexture(linemateTexture);
    return rock;
}

ZappyGUI::Rocks ZappyGUI::Ressources::generateMendiane(int x, int y, sf::Vector2f size) {
    ZappyGUI::Rocks rock;

    rock.setScale(size);
    rock.setPosition(x + rand() % 48, y + rand() % 48);
    rock.setTexture(mendianeTexture);
    return rock;
}

ZappyGUI::Rocks ZappyGUI::Ressources::generateDeraumere(int x, int y, sf::Vector2f size) {
    ZappyGUI::Rocks rock;

    rock.setScale(size);
    rock.setPosition(x + rand() % 48, y + rand() % 48);
    rock.setTexture(deraumereTexture);
    return rock;
}

ZappyGUI::Rocks ZappyGUI::Ressources::generatePhiras(int x, int y, sf::Vector2f size) {
    ZappyGUI::Rocks rock;

    rock.setScale(size);
    rock.setPosition(x + rand() % 48, y + rand() % 48);
    rock.setTexture(phirasTexture);
    return rock;
}

ZappyGUI::Rocks ZappyGUI::Ressources::generateSibur(int x, int y, sf::Vector2f size) {
    ZappyGUI::Rocks rock;

    rock.setScale(size);
    rock.setPosition(x + rand() % 48, y + rand() % 48);
    rock.setTexture(siburTexture);
    return rock;
}

ZappyGUI::Rocks ZappyGUI::Ressources::generateThystame(int x, int y, sf::Vector2f size) {
    ZappyGUI::Rocks rock;

    rock.setScale(size);
    rock.setPosition(x + rand() % 48, y + rand() % 48);
    rock.setTexture(thystameTexture);
    return rock;
}

void ZappyGUI::Ressources::generateRocks(std::map<std::tuple<int, int>, tile_t> map, sf::Vector2f size) {
    this->all_rocks.clear();

    for (auto x : map) {
        if (x.second.deraumere)
            this->all_rocks.push_back(generateDeraumere((std::get<0>(x.first))*64, (std::get<1>(x.first))*64, size));
        if (x.second.linemate)
            this->all_rocks.push_back(generateLinemate((std::get<0>(x.first))*64, (std::get<1>(x.first))*64, size));
        if (x.second.mendiane)
            this->all_rocks.push_back(generateMendiane((std::get<0>(x.first))*64, (std::get<1>(x.first))*64, size));
        if (x.second.phiras)
            this->all_rocks.push_back(generatePhiras((std::get<0>(x.first))*64, (std::get<1>(x.first))*64, size));
        if (x.second.sibur)
            this->all_rocks.push_back(generateSibur((std::get<0>(x.first))*64, (std::get<1>(x.first))*64, size));
        if (x.second.thystame)
            this->all_rocks.push_back(generateThystame((std::get<0>(x.first))*64, (std::get<1>(x.first))*64, size));
        if (x.second.food)
            this->all_rocks.push_back(generateFoods((std::get<0>(x.first))*64, (std::get<1>(x.first))*64, size));
    }
}

std::vector<ZappyGUI::Rocks> &ZappyGUI::Ressources::getRocks() { return this->all_rocks; }
