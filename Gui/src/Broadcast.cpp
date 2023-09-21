/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Broadcast
*/

#include "Broadcast.hpp"

ZappyGUI::Message::Message() {
    BrFont.loadFromFile(FONT_PATH_BROADCAST);
    BrText.setFont(BrFont);
    BrText.setPosition({1040, 470});
}
void ZappyGUI::Message::AddMessage(std::string msg) {
    this->message = FormatMessage(msg) + '\n' + this->message;
    FormatMessageEnd();
    this->BrText.setString(this->message);
}
void ZappyGUI::Message::AddBroadcast(Broadcast_t broadcast) {
    broadcast.cmds = FormatMessage("[ Player " + std::to_string(broadcast.playerID) + " ] -> " + broadcast.cmds);
    this->message = broadcast.cmds + '\n' + this->message;
    FormatMessageEnd();
    this->BrText.setString(this->message);
}
sf::Text &ZappyGUI::Message::GetText() {return this->BrText;}

std::string ZappyGUI::Message::FormatMessage(std::string msg) {
    int l = msg.length() / 49;

    for (int i = 0; i < l; i++)
        msg.insert(msg.begin() + ((i + 1) * 49), '\n');
    return msg;
}

void ZappyGUI::Message::ResetMessage() {
    this->message = "";
    this->BrText.setString(this->message);
}

int ZappyGUI::Message::CountLine() {
    int count = 0;

    for (auto i : this->message) {
        if (i == '\n')
            count++;
    }
    return count;
}

void ZappyGUI::Message::FormatMessageEnd() {
    int end = -1;

    while (CountLine() > 11) {
        end = message.rfind('\n');
        message.erase(message.begin() + end, message.end());
    }
}
