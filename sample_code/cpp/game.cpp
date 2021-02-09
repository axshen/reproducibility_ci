#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "utils.h"
#include <iostream>
#include <string>

Player getPlayer() {
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    Player player(name);
    return player;
}

void attackMonster(Player& player, Monster& monster) {
    std::cout << "You attack the " << monster.getName()
        << ", inflicting " << player.getStrength() << " damage.\n";
    monster.reduceHealth(player.getStrength());

    if (monster.isDead()) {
        std::cout << "Congratulations, you have slain the beast!\n";
        player.levelUp();
        if (player.hasWon()) {
            std::cout << "You win the game!\n";
        }
    };
};

void attackPlayer(Player& player, const Monster& monster) {
    std::cout << monster.getName() << " attacks and inflicts "
        << monster.getStrength() << " damage. Ouch!\n";
    player.reduceHealth(monster.getStrength());
};

void fightMonster(Player& player, Monster& monster) {
    char action;
    bool escapedSuccessfully = false;

    while (!monster.isDead() && !player.isDead()) {
        std::cout << "Attack (a) or run (r): \n";
        std::cin >> action;
        if (action == 'a') {
            attackMonster(player, monster);
            attackPlayer(player, monster);
        } else {
            escapedSuccessfully = (getRandomNumber(0, 1) == 1);
            if (escapedSuccessfully) {
                bool escapedSuccessfully = false;
                std::cout << "Got away safely!\n";
                break;
            } else {
                std::cout << "You attempt to run away but were unsuccessful.\n";
                attackPlayer(player, monster);
            }
        }
    };
};

int main()
{
    // Initialise game
    Player player = getPlayer();
    std::cout << "\n* You enter this mysterious world... *\n";
    
    // Gameplay
    while (!player.isDead() && !player.hasWon()) {
        std::cout << "\n* You walk around a bit. *\n\n";
        Monster monster = Monster::getRandomMonster();
        fightMonster(player, monster);

        if (player.isDead()) {
            std::cout << "\n";
            std::cout << "The world goes dark... You have died.\n";
            std::cout << "The game is over!\n";
            break;
        }
    };

	return 0;
}