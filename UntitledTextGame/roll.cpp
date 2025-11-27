//
// Created by kicie on 09/11/2025.
//
#include <ctime>
#include <iostream>
#include "roll.h"

int roll(int mod, int dc) {
    std::cout << "DC " << dc << " | Rolling..." << std::endl;
    int x = rand() % 21;
    if (x == 1) {
        std::cout << "1 | Critical fail!" << std::endl;
        return 1;
    }
    if (x == 20) {
        std::cout << "20 | Critical success!" << std::endl;
        return 100;
    }
    x += mod;
    if (x >= dc) {
        std::cout << x << " | Success!" << std::endl;
        return x;
    }
    else {
        std::cout << x << " | Fail!" << std::endl;
        return x;
    }
}
