//
// Created by kicie on 16/11/2025.
//
#include "player.h"

void setPronouns() {
    switch (player.gender) {
        case 1: // male
            player.subject = "he";
            player.object = "him";
            player.possessive = "his";
            player.reflexive = "himself";
            break;

        case 2: // female
            player.subject = "she";
            player.object = "her";
            player.possessive = "her";
            player.reflexive = "herself";
            break;

        default: // nonbinary
            player.subject = "they";
            player.object = "them";
            player.possessive = "their";
            player.reflexive = "themself";
            break;
    }
}
