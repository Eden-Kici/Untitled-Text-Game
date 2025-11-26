//
// Created by kicie on 16/11/2025.
//

#ifndef UNTITLEDTEXTGAME_LEVELONE_H
#define UNTITLEDTEXTGAME_LEVELONE_H
#pragma once
#include "player.h"

class LevelOne {
private:
    Player& player;   // Key

public:
    LevelOne(Player& p); // constructor

    void run();

    int breakFreeChoice(bool escapeFailed); //
    int waitChoice();                       //
    int waitIntimidate();                   //  Start + Wait Choices
    int waitPersuade();                     //
    void breakFree();                       //

    int freeChoice();
    int freeHandsWait(bool failedEscape, bool persFailedEscape);
    void freeHandsAmbush();
    void freeHandsPersuade();
    void freeHandIntimidate();

    void sneakEscape();
    void confrontEscape();
};

#endif //UNTITLEDTEXTGAME_LEVELONE_H