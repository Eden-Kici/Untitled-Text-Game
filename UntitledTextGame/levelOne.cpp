//
// Created by kicie on 08/11/2025.
//
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "roll.h"
#include "rollAdv.h"
#include "player.h"
#include "choice.h"
#include "levelOne.h"
using namespace std;
LevelOne::LevelOne(Player& p)
    : player(p)  // <- reference must be initialized here
{}

int LevelOne::breakFreeChoice(bool escapeFailed) {
    if (escapeFailed == true) {
        cout << "Nothing left to do but to try to escape now." << endl << endl;
        switch (player.getClass()) {
            case 1:
                cout << "   1. [Sellsword] Try to force your arms free." << endl;
                break;
            case 2:
                cout << "   1. [Thief] Try to wriggle out of your bindings." << endl;
                break;
            case 3:
                cout << "   1. [Archer] Try to cut the bindings against the tree." << endl;
                break;
            default:
                cout << "Player class not found (escapeFailed).";

        }
        return choice(1, 1); // checks for correct input value from user
    }
    else {
        switch (player.getClass()) {
            case 1:
                cout << "   2. [Sellsword] Try to force your arms free." << endl;
                break;
            case 2:
                cout << "   2. [Thief] Try to wriggle out of your bindings." << endl;
                break;
            case 3:
                cout << "   2. [Archer] Try to cut the bindings against the tree." << endl;
                break;
            default:
                cout << "No player class found!";
        }
        return choice(1, 2); // checks for correct input value from user
    }




}
int LevelOne::waitChoice() {
    cout << "Some bandits huddled around a campfire laugh in the distance, although you can't tell what about exactly." << endl;
    cout << "Not long passes until one of the bandits approaches with a bowl of water." << endl;
    cout << " Bandit: Drink up. Can't have you dying on us." << endl << endl;

    cout << "   1. Intimidate him." << endl;
    cout << "   2. Persuade him to let you go." << endl;
    cout << "   3. Wait for him to go away." << endl;

    return choice(1, 3);
}
int LevelOne::waitIntimidate() {
    int roll1;
    roll1 = {roll(player.getStr(), 15)};
    cout << "You tell the bandit that if he doesn't let you go now, when someone does, he will be"
                "the first to go. ";
    if (roll1 >= 15) {
        cout << "He takes a step back and looks back at the camp.";
        cout << "Bandit: You're a pyscho - I know it. Fine, just go.";
        cout << "He cuts you free while no one is looking at takes a step back. You walk away before anybody notices.";
        return 0;
    } // success
    else {
        cout << "Bandit: Yeah, right. No water for you then, 'tough' ";
        switch (player.getClass()) {
            case 1:
                cout << "guy.";
                break;
            case 2:
                cout << "girl.";
            case 3:
                cout << "one.";
        }
        return 1;
    } // fail
}
int LevelOne::waitPersuade() {
    int roll1;
    roll1 = {roll(player.getStr(), 15)};
    cout << "You tell the bandit that no one is going to pay for you no matter how long they keep you here.";
    if (roll1 >= 15) {
        cout << "Bandit: Well, shit. You don't look like anybody important either. Aight, piss off.";
        cout << "He cuts you free. You walk away before anybody notices.";
        return 0;
    } // success
    else {
        cout << "Bandit: Yeah, right, that's what they all say.";
        cout << "He pours out the water and walks away.";
        return 1;
    } // fail
}
void LevelOne::breakFree() {
    rollAdv(+20, +10);
    switch (player.getClass()) {
        case 1:
            cout << endl << "You press your wrists against the bindings. They ache and cry out to stop, but the rope"
                    " breaks before your body does." << endl;
            break;
        case 2:
            cout << endl << "You've found yourself in trouble more than you can count, with bindings tighter than "
                    "these. You wriggle your hands out easily. These amatures clearly don't know what they're"
                    " doing." << endl;
            break;
        case 3:
            cout << endl <<
                    "You wrap one leg around the tree and reach for the shiv in your boot. It takes a few tries "
                    "but you eventually grab it and cut the ropes off." << endl;
            break;
    }
}

int LevelOne::freeChoice() {
    cout << endl << endl << "Your hands are free, but no one seems to have noticed yet. You could pretend to be "
            "tied still, or make your move now." << endl << endl;

    cout << "   1. Pretend you are still tied." << endl;
    cout << "   2. Attempt to sneak in the dark." << endl;
    cout << "   3. Confront the bandits." << endl;

    return choice(1,3);
}
int LevelOne::freeHandsWait(bool failedEscape, bool persFailedEscape) {
    if (failedEscape) {
        cout << "You put your hands back where they were and wait some more, hoping another bandit comes by.";
    } else {
        cout << "You put your hands back where they were and wait, hoping a bandit comes by.";
    }
    cout << endl << " It doesn't take long for one to approach." << endl << endl;
    cout << "   1. Surprise attack!";
    if (failedEscape && persFailedEscape) {
        cout << "   2. Try to talk your way out again.";
    } else {
        cout << "   2. Try to talk your way out.";
    }
    cout << "   3. Try to intimidate him.";
    return choice(1, 3);
}
void LevelOne::freeHandsAmbush() {
    auto [roll1, roll2] = rollAdv(player.getStr(), 15);
                    if (roll1 >= 15 || roll2 >= 15) {
                        cout << endl << endl << "The bandit falls to the ground unconcious. He has a scimitar sheathed "
                        "on his belt." << endl << endl;
                        cout << "   1. Can't stay here any longer. Run away.";
                        cout << "   2. Quickly take the scimitar before escaping.";
                        int x = choice(1,2);

                        if (x == 2) {
                            cout << endl << endl << "You quickly undo the bandits belt and put it on, scimitar along with "
                                    "it. Player escapes.";
                        } else {
                            cout << endl << endl << "player escapes without scimitar";
                        }
                    } else {
                        cout << endl << endl << "surprise attack fail.";
                        cout << "The bandit stumbles back and shouts." << endl;
                        cout << "Bandit: What the hell? How did you escape?!" << endl;
                        cout << "The rest of the bandits heads snap to you. They get up from the camp fire, some pulling out "
                                "weapons. You're severely out-numbered and unarmed." << endl << endl;

                        cout << "   1. Run away.";

                        choice(1,1);
                        cout << endl << endl;
                        roll1 = {roll(player.getDex(), 12)};
                        if (roll1 >= 12) {
                            cout << "Player runs away and escapes.";
                            // escape
                        } else {
                            cout << "Player gets injured but escapes. (-3 HP)";
                            cout << "hp: " << player.getHP();
                            player.takeDamage(3);
                            cout << player.getHP();
                        }
                    }
}
void LevelOne::freeHandsPersuade() {
    int roll1 = {roll(player.getDex(), 15)};
    if (roll1 >= 15) {
        cout << endl << endl << "try to talk success.";
        cout << endl << endl << "player escapes";
    } else {
        cout << endl << endl << "try to talk fail.";
        player.takeDamage(3);
    }
}
void LevelOne::freeHandIntimidate() {
    int roll1 = {roll(player.getDex(), 15)};
    if (roll1 >= 15) {
        cout << endl << endl << "try to intimidate him success.";
        cout << endl << endl << "player escapes";
    } else {
        cout << endl << endl << "try to intimidate him, fail. -3 HP";
        player.takeDamage(3);
    }
}

void LevelOne::sneakEscape() {
    int roll1 = roll(player.getDex(), 10);
    if (roll1 >= 10) {
        cout << endl << endl << "You escape.";
    }
    else {
        cout << endl << endl << "You are spotted.";
        cout << endl << endl << "   1. Fight the bandit.";
        cout << endl << "   2. Run away.";
        int x = choice(1, 2);

        if (x == 1) {    // fighting
            roll1 = {roll(player.getStr(), 15)};
            if (roll1 >= 15) {
                cout << endl << endl << "You beat the bandit and escaped.";
            } else {
                cout << endl << endl << "You got injured but escaped.";
                player.takeDamage(3);
            }
        }
        if (x == 2) {    // running away

            roll1 = {roll(player.getDex(), 10)};
            if (roll1 >= 10) {
                cout << endl << endl << "You escaped.";
            } else {
                cout << endl << endl << "You get injured but escaped.";
            }
        } // running away
    }
}
void LevelOne::confrontEscape() {
    int roll1;
    cout << "You get up and step forward, shouting for the bandits attention. The chatter stops and "
            "is immediately replaced by the sounds of blades being unsheathed. The man from earlier "
            "steps forward, challenging you.";
    cout << endl << endl << "   1. Nevermind, run away.";
    cout << endl << "   2. Fight him.";
    int x = choice(1, 2);

    if (x == 1) {
        roll1 = {roll(player.getDex(), 12)};
        if (roll1 >= 12) {
            cout << endl << endl << "You escape.";
        } else {
            cout << endl << endl <<
                    "You make a run for it but he tackles you (-3HP). You throw him off "
                    "and quickly get back to your feet. He's now blocking your path.";
            player.takeDamage(3);
            cout << endl << endl << "   1. Fight him.";
            x = choice(1, 1);
            roll1 = {roll(player.getStr(), 15)};
            if (roll1 >= 15) {
                cout << endl << endl << "You beat him and escape.";
            } else {
                cout << endl << endl << "He beats you and throws you out.";
                player.takeDamage(3);
            }
        }
    }
    if (x == 2) {
        roll1 = {roll(player.getStr(), 15)};
        if (roll1 >= 15) {
            cout << endl << endl << "You beat him. The rest of the bandits seem hesitant to fight you.";
            cout << endl << endl << "   1. Make them fear you.";
            cout << endl << "   2. Run while they're still frozen.";
            x = choice(1, 2);
            if (x == 1) {
                auto [roll1, roll2] = rollAdv(player.getStr(), 10);
                if (roll1 >= 10 || roll2 >= 10) {
                    cout << endl << endl << "You take his scimitar and execute him. The bandits take "
                            "a step back.";
                    cout << endl << "Bandit: Frenfri...";
                    cout << endl << "You eye them closely while sheathing your new scimitar. They're "
                            "no threat to you any longer, but best to get out of there "
                            "before they change their minds.";
                }
                else {
                    cout << endl << endl << "'Who's next?' You ask taking a step forward.";
                    cout << endl << "Bandit: Get 'em!";
                    cout << endl << "The bandits rush toward you. You can take one, but not all of "
                            "them at the same time. You run the opposite direction, but "
                            "not before catching a slash to the back. (-3 HP)";
                    player.takeDamage(3);
                }
            }
            if (x == 2) {
                cout << endl << endl << "You escaped.";
            }
        }
        else {
            cout << endl << endl << "He beats you and throws you out.";
        }
    }
}

void LevelOne::run() {
    srand(time(0)); // seed RNG once at the start
    int choice{};
    bool failedEscape = false;
    bool persFailedEscape = false;
    // wake up
    cout << endl << endl << "You wake up with your arms bound to a tree with rope. It's night. Not too far from you, "
            "people walk by tents lit by fireplaces. You realize it's a bandit camp. You're probably "
            "getting ransomed.";

    cout << endl << endl << "   1. Wait. " << endl;

    // Tided up Section - Wait / Escape Route
    choice = breakFreeChoice(failedEscape);
    if (choice == 1) {
        choice = waitChoice();
        switch (choice) {
            case 1: // intimidate
                failedEscape = waitIntimidate();
                if (failedEscape == false) {
                    return; // escape
                }
                break;
            case 2: // persuade
                failedEscape = waitPersuade();
                if (failedEscape == false) {
                    return; // escape
                }
                persFailedEscape = true;
                break;
            case 3: // wait
                cout << "You stare at the bandit, refusing to drink. He tries to force the bowl onto your "
                        "lips, but quickly grows frustrated." << endl;
                cout << "Bandit: Ugh, fine. Don't complain later when you're parched." << endl;
                failedEscape = true;
        }
    }

    if (failedEscape) { // In case player didn't escape
        choice = breakFreeChoice(failedEscape);
        choice = 2;
    }

    if (choice == 2) { // Broken free
        breakFree();
    }
    choice = freeChoice(); // Free Hands Choice

    switch (choice) {
        case 1: // wait
            choice = freeHandsWait(failedEscape, persFailedEscape);
            switch (choice) {
                case 1:
                    freeHandsAmbush();
                    return;
                case 2:
                    freeHandsPersuade();
                    return;
                case 3:
                    freeHandIntimidate();
                    return;
            }
        case 2: // try to sneak
            sneakEscape();
            return;

        case 3: // confront bandits
            confrontEscape();
            return;
    }
}
