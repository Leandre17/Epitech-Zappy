/*
** EPITECH PROJECT, 2023
** B-YEP-400-BDX-4-1-zappy-johanna.bureau
** File description:
** main
*/

#include "GUI.hpp"
#include "Rocks.hpp"
#include "Ressources.hpp"
#include "Move.hpp"
#include "Menu.hpp"
#include <SFML/Audio.hpp>

void handleEvents(sf::Event event, ZappyGUI::Menu &menu, ZappyGUI::SettingMenu &smenu, ZappyGUI::Commands &cmd, ZappyGUI::Client &client) {
    if (event.type == sf::Event::Closed || 
    (menu.onMenu && menu.getExit().contains(cmd.getMousePos()) && MOUSECLICKED) ||
    (smenu.onSetting && smenu.getExit().contains(cmd.getMousePos()) && MOUSECLICKED) || event.key.code == sf::Keyboard::Key::Q)
        cmd.getWindow().close();
    if (!(menu.onMenu || smenu.onSetting) && event.mouseButton.button == sf::Mouse::Button::Left && MOUSECLICKED)
        cmd.checkClicque(event.mouseButton.x, event.mouseButton.y);
    if (menu.onMenu && event.key.code == sf::Keyboard::Key::A && sf::Event::KeyPressed == event.type)
        menu.onMenu = false;
    if ((sf::Event::KeyPressed == event.type && event.key.code == sf::Keyboard::Key::Escape) ||
    (smenu.onSetting && smenu.getRet().contains(cmd.getMousePos()) && MOUSECLICKED)) {
        menu.onMenu = true;
        smenu.onSetting = false;
    } else if (menu.onMenu && menu.getSettings().contains(cmd.getMousePos()) && MOUSECLICKED) {
        smenu.onSetting = true;
        menu.onMenu = false;
    }
    if (smenu.getSpritePlus().contains(cmd.getMousePos()) && MOUSECLICKED) {
        cmd.SetTimeUnit(cmd.GetTimeUnit() + 5);
        client.send("sst " + std::to_string(cmd.GetTimeUnit()) + "\n");
    } else if (smenu.getSpriteMoins().contains(cmd.getMousePos()) && MOUSECLICKED) {
        cmd.SetTimeUnit(cmd.GetTimeUnit() - 5);
        client.send("sst " + std::to_string(cmd.GetTimeUnit()) + "\n");
    }
}

int in_team_list(std::vector<std::string> team_name, ZappyGUI::Commands &cmd)
{
    int count = 1;

    while(count - 1 != int(team_name.size())) {
        if (team_name[count - 1] == cmd.team_name) {
            return count;
        }
        count++;
    }
    return 0;
}

std::string in_sprite_team_list(std::vector<std::string> team_sprite, std::unique_ptr<ZappyGUI::Sprite> &poke)
{
    int count = 0;
    std::string random_temp = poke->getRandomPokemon();
    while (count != int(team_sprite.size())) {
        if (random_temp == team_sprite[count]) {
            random_temp = poke->getRandomPokemon();
            count = 0;
        } else {
            count++;
        }
    }
    return random_temp;
}

int main(int argc, char **argv)
{
    ZappyGUI::Params params(argc, argv);
    ZappyGUI::Client client(params.getIp(), params.getPort());
    ZappyGUI::Commands cmd;
    Move move_player;
    ZappyGUI::Menu menu;
    ZappyGUI::SettingMenu smenu;

    cmd.leaving = false;
    cmd.isConnection = false;
    cmd.moving = false;
    cmd.isPic = false;
    client.connectToServer();
    client.send("GRAPHIC\n");
    cmd.RecuperateInfo(client.receive());
    cmd.RecuperateInfo(client.receive());
    cmd.InitilizeDisplay();
    cmd.RecuperateInfo("pbc 1 Broadcast of player 1 \n");
    cmd.RecuperateInfo("pbc 2 Reponce du joueur 2 \n");
    cmd.getWindow().setFramerateLimit(30);

    std::vector<std::unique_ptr<ZappyGUI::Sprite>> sprites;
    std::vector<int> num_players;
    std::vector<std::string> team_name;
    std::vector<std::string> team_sprite;

    bool play_menu_music = true;
    sf::Music music;
    if (!music.openFromFile("Gui/assets/song/menu.wav")) {
        std::cout << "Music not found" << std::endl;
    }
    sf::Music music_secret;
    std::string keyword = "HEY";
    std::string input;
    int secret_music = 0;
    if (!music_secret.openFromFile("Gui/assets/song/HEYYEYAAEYAAAEYAEYAA.wav")) {
        std::cout << "Music not found" << std::endl;
    }

    
    while (cmd.getWindow().isOpen()) {
        sf::Event event;
        while (cmd.getWindow().pollEvent(event)) {
            handleEvents(event, menu, smenu, cmd, client);
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Enter)
                {
                    // Vérifiez si le mot-clé est présent dans l'entrée
                    if (input.find(keyword) != std::string::npos)
                    {
                        // Le mot-clé est présent dans l'entrée, jouez le son
                        secret_music = 1;
                        music_secret.play();
                    }
                    input.clear(); // Réinitialiser l'entrée
                }
                else if (event.key.code == sf::Keyboard::Backspace)
                {
                    if (!input.empty())
                    {
                        input.pop_back(); // Supprimer le dernier caractère de l'entrée
                    }
                }
                else if (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z)
                {
                    // Ajouter le caractère correspondant à la touche appuyée
                    input += static_cast<char>('A' + (event.key.code - sf::Keyboard::A));
                }
            }
        }
        if (music_secret.getStatus() == sf::Sound::Stopped && secret_music == 1) {
            secret_music = 3;
        }
        if (secret_music == 1) {
            music.stop();
        }
        
        if (menu.onMenu) {
            if ((play_menu_music == true && secret_music == 0) || secret_music == 3) {
                music.play();
                play_menu_music = false;
                secret_music = 0;
            }
            cmd.getWindow().draw(menu);
            cmd.getWindow().display();
        } else if (smenu.onSetting) {
            smenu.DrawMenu(cmd.getWindow(), cmd.GetTimeUnit());
        } else {
            if (play_menu_music == false) {
                music.stop();
                play_menu_music = true;
            }
            if (event.type == sf::Event::TextEntered)
            {
                std::string input;
                if (event.text.unicode < 128)
                {
                    input += static_cast<char>(event.text.unicode);
                }

                // Vérifiez si le mot-clé est présent dans l'entrée
                if (input.find(keyword) != std::string::npos)
                {
                    // Le mot-clé est présent dans l'entrée, jouez le son
                    music_secret.play();
                }
            }
            if (cmd.isConnection) {
                std::unique_ptr<ZappyGUI::Sprite> poke = std::make_unique<ZappyGUI::Sprite>();
                std::string random_pokemon = in_sprite_team_list(team_sprite, poke);
                int is_listed = in_team_list(team_name, cmd);
                if (is_listed == 0) {
                    if (!poke->load(random_pokemon, sf::Vector2u(cmd.getWindowSize().x / static_cast<float>(64) * 64, cmd.getWindowSize().y / static_cast<float>(64) * 64), 5, 5))
                        return -1;
                    team_name.push_back(cmd.team_name);
                    team_sprite.push_back(random_pokemon);
                } else {
                    if (!poke->load(team_sprite[is_listed - 1], sf::Vector2u(cmd.getWindowSize().x / static_cast<float>(64) * 64, cmd.getWindowSize().y / static_cast<float>(64) * 64), 5, 5))
                        return -1;
                }
                sprites.push_back(std::move(poke));
                num_players.push_back(cmd.poke_n);
                cmd.isConnection = false;
            }
            if (cmd.leaving) {
                int count = 0;
                while (num_players[count] != cmd.poke_leave) {
                    count++;
                }
                sprites.erase(sprites.begin() + count);
                num_players.erase(num_players.begin() + count);
                cmd.leaving = false;
            }
            if (cmd.moving) {
                move_player.move_command(cmd, menu.onMenu, move_player, sprites, num_players);
                cmd.moving = false;
            }
            move_player.SpriteAnim(cmd, menu.onMenu, sprites, num_players);
            cmd.Display();
            for (const auto& sprite : sprites) {
                cmd.getWindow().draw(*sprite);
            }
            cmd.getWindow().display();
        }
        
        client.send("mct\n");
        while (cmd.RecuperateInfo(client.receive()) != ZappyGUI::CMD::BCT){}
    }

    client.closeConnection();
    return 0;
}
