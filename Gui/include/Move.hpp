/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Move
*/

#ifndef MOVE_HPP_
#define MOVE_HPP_
#include "Commands.hpp"
#include "Sprite.hpp"
#include <memory>
#include <iostream>

class Move {
  public:
    void move_command(ZappyGUI::Commands &cmd, bool onMenu, Move &move_player,
        std::vector<std::unique_ptr<ZappyGUI::Sprite>> &pokes,
        std::vector<int> &num_players);
    void move_on_down(ZappyGUI::Commands &cmd, ZappyGUI::Sprite &poke);
    void move_on_up(ZappyGUI::Commands &cmd, ZappyGUI::Sprite &poke);
    void move_on_left(ZappyGUI::Commands &cmd, ZappyGUI::Sprite &poke);
    void move_on_right(ZappyGUI::Commands &cmd, ZappyGUI::Sprite &poke);
    void incantation_anim(ZappyGUI::Sprite &poke);
    void SpriteAnim(ZappyGUI::Commands &cmd, bool onMenu, std::vector<std::unique_ptr<ZappyGUI::Sprite>> &pokes, std::vector<int> &num_players);

  protected:
  private:
};

#endif /* !MOVE_HPP_ */
