//
// Created by kicie on 09/11/2025.
//
#include <ctime>
#include <iostream>
#include "rollAdv.h"
#include <utility> // for std::pair


std::pair<int, int> rollAdv(int mod, int dc) {
    // make sure to seed rand once in main(), not here
    std::cout << "DC " << dc << " | Rollng with advantage..." << std::endl;
    int x = rand() % 21 + mod;
    int y = rand() % 21 + mod;
    std::cout << x << "  |  " << y;

    return {x, y};
}