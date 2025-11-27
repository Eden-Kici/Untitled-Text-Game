//
// Created by kicie on 09/11/2025.
//
#include <ctime>
#include <iostream>
#include "rollAdv.h"
#include <utility> // for std::pair


std::pair<int, int> rollAdv(int mod, int dc) {

    std::cout << "DC " << dc << " | Rolling with advantage..." << std::endl;
    int x = rand() % 21;
    int y = rand() % 21;

    if (x == 1 && y == 1)
    {
        std::cout << "1 & 1 | Critical Fail!" << std::endl;
        return {1, 1};
    }

    if (x == 20 || y == 20) {
        std::cout << x << " & " << y <<  " | Critical Success!" << std::endl;
        return {100, 100};
    }
    x += mod;
    y += mod;
    if (x >= dc || y >= dc) {
        std::cout << x << " & " << " | Success!" << std::endl;
        return {x, y};
    }
    std::cout << x << " & " << y << " | Fail!" << std::endl;
    return {x, y};
}