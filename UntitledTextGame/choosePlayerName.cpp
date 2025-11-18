#include <iostream>
#include <string>
#include "choosePlayerName.h"


std::string choosePlayerName() {

    int nameConfirmed {0};
    while (nameConfirmed != 1) {
        std::cout << "Enter your name: " << std::endl;
        std::string playerName;
        std::cin >> playerName;

        std::cout << "Your name is " << playerName << ". Are you sure? This cannot be changed later." << std::endl;
        std::cout << "1. Yes" << std::endl<< "2. No" << std::endl;
        std::cin >> nameConfirmed;

        while (nameConfirmed != 1 && nameConfirmed != 2) {
            std::cout << "Please enter 1 or 2: " << std::endl;
            std::cin >> nameConfirmed;
        }

    if (nameConfirmed == 1) {
            std::cout << "Confirmed. Your name is: " << playerName << std::endl;
    return playerName;
        }
    }
}