cmake_minimum_required(VERSION 4.0)
project(UntitledTextGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(UntitledTextGame main.cpp
        choosePlayerName.cpp
        choosePlayerName.h
        choosePlayerGender.cpp
        choosePlayerClass.cpp
        choosePlayerGender.h
        choosePlayerClass.h
        roll.cpp
        roll.h
        rollAdv.cpp
        rollAdv.h
        player.h
        levelOne.cpp
        choice.cpp
        choice.h
        levelOne.h
        player.cpp
)
