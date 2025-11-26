//
// Created by kicie on 15/11/2025.
//
#ifndef UNTITLEDTEXTGAME_PLAYER_H
#define UNTITLEDTEXTGAME_PLAYER_H
#pragma once
#include <string>

class Player {
private:
    static Player instance;
    std::string name;
    int playerClass;
    int gender;

    int hp;
    int str;
    int dex;

    // pronouns
    std::string subject;
    std::string object;
    std::string possessive;
    std::string reflexive;

public:
    Player();
    Player& get() { return instance; }


    // setters
    void setName(const std::string& n);
    void setGender(int g);
    void setClass(int c);

    void setPronouns();
    void setStats();

    // getters
    const std::string& getName() const { return name; }
    int getHP() const { return hp; }    //
    int getStr() const { return str; }  // Stats
    int getDex() const { return dex; }  //
    int getClass() const { return playerClass; }    // Player traits
    int getGender() const { return gender; }        //

    // gameplay interactions
    void takeDamage(int amount);



};
#endif //UNTITLEDTEXTGAME_PLAYER_H