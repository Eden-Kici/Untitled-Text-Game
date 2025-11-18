#include <iostream>
#include <string>
#include "choosePlayerClass.h"
#include "choosePlayerName.h"
#include "choosePlayerGender.h"
#include "player.h"
#include "levelOne.h"
#include "setPronouns.h"
#include "setStats.h"
using namespace std;

int main() {
    player.name = choosePlayerName();
    player.gender = choosePlayerGender();
    player.playerClass = choosePlayerClass();
    setPronouns();
    setStats();


    levelOne();

}