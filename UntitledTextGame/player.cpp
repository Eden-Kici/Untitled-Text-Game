//
// Created by kicie on 16/11/2025.
//
#include "player.h"

#include <iostream>
#include <ostream>

Player::Player()
    : hp(0), str(0), dex(0),
      playerClass(0), gender(0),
      name("Tav")
{}

void Player::setName(const std::string& n) {
    name = n;
}

void Player::setGender(int g) {
    gender = g;
}

void Player::setClass(int c) {
    playerClass = c;
}

void Player::setPronouns() {
    if (gender == 1) {
        subject = "he";
        object = "him";
        possessive = "his";
        reflexive = "himself";
    } else if (gender == 2) {
        subject = "she";
        object = "her";
        possessive = "her";
        reflexive = "herself";
    } else {
        subject = "they";
        object = "them";
        possessive = "their";
        reflexive = "themself";
    }
}

void Player::setStats() {
    if (playerClass == 1) {
        hp = 20; str = 7; dex = 2;
    } else if (playerClass == 2) {
        hp = 14; str = 4; dex = 4;
    }
    else if (playerClass == 3) {
        hp = 10; str = 3; dex = 8;
    }
}

void Player::takeDamage(int amount) {
    hp -= amount;
    std::cout << "\nYou take " << amount << " damage." << std::endl;
    if (hp < 0) hp = 0;  // Reset negative HP to 0.
    std::cout << "You have " << hp << " HP." << std::endl;
}