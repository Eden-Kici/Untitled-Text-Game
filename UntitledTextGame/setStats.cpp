//
// Created by kicie on 16/11/2025.
//
#include "player.h"

void setStats() {
    switch (player.playerClass) { // initialize player stats
        case 1:
            player.hp = 20;
            player.str = 7;
            player.dex = 2;
            break;
        case 2:
            player.hp = 14;
            player.str = 4;
            player.dex = 4;
            break;
        case 3:
            player.hp = 10;
            player.str = 3;
            player.dex = 8;
            break;
    } //
}