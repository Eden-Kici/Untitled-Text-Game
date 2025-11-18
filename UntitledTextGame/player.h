//
// Created by kicie on 15/11/2025.
//
#ifndef UNTITLEDTEXTGAME_PLAYER_H
#define UNTITLEDTEXTGAME_PLAYER_H
#include <string>
struct Player {
    std::string name;
    int playerClass;
    int gender;
    int hp;
    int str;
    int dex;

    // pronouns
    std::string subject;   // he / she / they
    std::string object;    // him / her / them
    std::string possessive; // his / her / their
    std::string reflexive; // himself / herself / themself
};
extern Player player;
#endif //UNTITLEDTEXTGAME_PLAYER_H