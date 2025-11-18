//
// Created by kicie on 16/11/2025.
//

#include <algorithm>
#include <iostream>
#include "choice.h"
int choice(int min, int max) {
    int choice;
    std::cin >> choice;

    while (choice > max || choice < min) {
        std::cout << "\n" << "Please enter a valid choice.";
        std::cin >> choice;
        std::cout << std::endl;
    }
    return choice;
}
