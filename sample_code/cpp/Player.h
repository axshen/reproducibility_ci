// Copyright 2021 Austin Shen

#ifndef SAMPLE_CODE_CPP_PLAYER_H_
#define SAMPLE_CODE_CPP_PLAYER_H_

#include "Creature.h"
#include <string>
#include <iostream>

class Player : public Creature {
 private:
    int m_level;
 public:
    Player(std::string name, char symbol = '@',
           int health = 10, int strength = 1, int gold = 0)
    : Creature(name, symbol, health, strength, gold), m_level(0) {
        std::cout << "Welcome " << name << ".\n";
        std::cout << "You have " << health
                  << " health and are carrying " << gold << " gold.\n";
    }

    int getLevel() const { return m_level; }
    bool hasWon() const { return (m_level >= 20); }
    void levelUp();
};

#endif  // SAMPLE_CODE_CPP_PLAYER_H_
