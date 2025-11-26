#include <iostream>
#include <string>
#include "choosePlayerClass.h"
#include "choosePlayerName.h"
#include "choosePlayerGender.h"
#include "player.h"
#include "levelOne.h"
using namespace std;

int main() {
    Player player;

    player.setName(choosePlayerName());
    player.setGender(choosePlayerGender());
    player.setClass(choosePlayerClass());

    player.setPronouns();
    player.setStats();

    LevelOne level(player);   // give level access to the player
    level.run();
}