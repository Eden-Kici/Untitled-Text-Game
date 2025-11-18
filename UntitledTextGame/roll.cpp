//
// Created by kicie on 09/11/2025.
//
#include <ctime>
#include <iostream>
#include "roll.h"

int roll(int mod, int dc) {
    std::cout << "DC " << dc << " | Rollng with advantage..." << std::endl;
    int x = rand() % 21 + mod;
    std::cout << x;
    return x;
}