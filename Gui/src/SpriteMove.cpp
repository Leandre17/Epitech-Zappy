/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** move_sprite
*/

#include <iostream>
#include <memory>
#include "Move.hpp"

void Move::move_command(ZappyGUI::Commands &cmd, bool onMenu,
    Move &move_player, std::vector<std::unique_ptr<ZappyGUI::Sprite>> &pokes,
    std::vector<int> &num_players)
{
    if (!pokes.empty()) {
        int count = 0;
        while (num_players[count] != cmd.poke_n) {
            count++;
        }
        if (onMenu == false && cmd.poke_o == 1) {
            move_player.move_on_right(cmd, *pokes[count]);
            return;
        }
        if (onMenu == false && cmd.poke_o == 3) {
            move_player.move_on_left(cmd, *pokes[count]);
            return;
        }
        if (onMenu == false && cmd.poke_o == 0) {
            move_player.move_on_up(cmd, *pokes[count]);
            return;
        }
        if (onMenu == false && cmd.poke_o == 2) {
            move_player.move_on_down(cmd, *pokes[count]);
            return;
        }
        if (onMenu == false && cmd.isPic) {
            incantation_anim(*pokes[count]);
            return;
        }
    }
}

void Move::move_on_down(ZappyGUI::Commands &cmd, ZappyGUI::Sprite &poke)
{
    poke.set_rect(0, 0);
    poke.setPosition(
        cmd.poke_x * cmd.getWindowSize().x / static_cast<float>(64) * 64,
        cmd.poke_y * cmd.getWindowSize().y / static_cast<float>(64) * 64);
    return;
}

void Move::move_on_up(ZappyGUI::Commands &cmd, ZappyGUI::Sprite &poke)
{
    poke.set_rect(0, 32);
    poke.setPosition(
        cmd.poke_x * cmd.getWindowSize().x / static_cast<float>(64) * 64,
        cmd.poke_y * cmd.getWindowSize().y / static_cast<float>(64) * 64);
    return;
}

void Move::move_on_left(ZappyGUI::Commands &cmd, ZappyGUI::Sprite &poke)
{
    poke.set_rect(0, 64);
    poke.setPosition(
        cmd.poke_x * cmd.getWindowSize().x / static_cast<float>(64) * 64,
        cmd.poke_y * cmd.getWindowSize().y / static_cast<float>(64) * 64);
    return;
}

void Move::move_on_right(ZappyGUI::Commands &cmd, ZappyGUI::Sprite &poke)
{
    poke.set_rect(0, 96);
    poke.setPosition(
        cmd.poke_x * cmd.getWindowSize().x / static_cast<float>(64) * 64,
        cmd.poke_y * cmd.getWindowSize().y / static_cast<float>(64) * 64);
    return;
}
