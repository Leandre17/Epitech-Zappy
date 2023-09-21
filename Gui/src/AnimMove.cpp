/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** AnimMove
*/

#include "Move.hpp"

void Move::SpriteAnim(
    ZappyGUI::Commands &cmd,
    bool onMenu,
    std::vector<std::unique_ptr<ZappyGUI::Sprite>> &pokes,
    std::vector<int> &num_players
)
{
    if (!pokes.empty()) {
        int count = 0;
        while (num_players[count] != cmd.poke_n) {
            count++;
        }
        if (onMenu == false && cmd.isPic) {
            incantation_anim(*pokes[count]);
            return;
        }
    }
}

void Move::incantation_anim(ZappyGUI::Sprite &poke)
{ 
    int poke_rect = poke.get_rect();
 
    if (poke_rect != 96) {
        poke.set_rect(0,  poke_rect + 32);
    } else {
        poke.set_rect(0, 0);
    }
}
