//
// Created by kicie on 07/11/2025.
//
#include "choosePlayerClass.h"
#include <iostream>

int choosePlayerClass() {
    int playerClass {};
    int playerClassConfirmed {};
    while (playerClass != 1 || playerClass != 2 || playerClass != 3) {
        std::cout << std::endl << "Choose your class: " << std::endl;
        std::cout << "1. Sellsword: | 20 HP |  STR 7 | DEX 2 |  " << std::endl;
        std::cout << "2. Thief: | 14 HP |  STR 4 | DEX 4 |  " << std::endl;
        std::cout << "3. Archer: | 10 HP |  STR 3 | DEX 8 |  " << std::endl;

        std::cin >> playerClass;

        while (playerClass > 3 || playerClass < 1) {
            std::cout << "Please enter 1, 2, or 3. " << std::endl;
            std::cin >> playerClass;
        }
        std::cout << "Are you sure? This cannot be changed later." << std::endl;
        std::cout << "1. Yes     2. No" << std::endl;
        std::cin >> playerClassConfirmed;

        while (playerClassConfirmed != 1 && playerClassConfirmed != 2) {
            std::cout << "Please enter 1 or 2: " << std::endl;
            std::cin >> playerClassConfirmed;
        }

        if (playerClassConfirmed == 1) {
            std::cout << "Confirmed." << std::endl << std::endl;
            return playerClass;
        }
    }


}