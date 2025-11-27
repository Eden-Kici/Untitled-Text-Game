//
// Created by kicie on 07/11/2025.
//
#include <iostream>
#include "choosePlayerGender.h"

int choosePlayerGender() {
    int gender {};
    int genderConfirmed {};
    while (gender != 1 || gender != 2 || gender != 3) {
        std::cout << std::endl << "Choose your gender: " << std::endl;
        std::cout << "1. He/Him" << std::endl << "2. She/Her" << std::endl << "3. They/Them" << std::endl;
        std::cin >> gender;

        while (gender > 3 || gender < 1) {
            std::cout << "Please enter 1, 2, or 3. " << std::endl;
            std::cin >> gender;
        }
        std::cout << "Are you sure? This cannot be changed later." << std::endl;
        std::cout << "1. Yes" << std::endl << "2. No" << std::endl;
        std::cin >> genderConfirmed;

        while (genderConfirmed != 1 && genderConfirmed != 2) {
            std::cout << "Please enter 1 or 2: " << std::endl;
            std::cin >> genderConfirmed;
        }

        if (genderConfirmed == 1) {
            std::cout << "Confirmed." << std::endl << std::endl;
            return gender;
        }
    }


}