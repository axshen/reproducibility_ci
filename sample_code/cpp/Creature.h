// Copyright 2021 Austin Shen

#ifndef SAMPLE_CODE_CPP_CREATURE_H_
#define SAMPLE_CODE_CPP_CREATURE_H_

#include <iostream>
#include <string>

class Creature {
 protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_strength;
    int m_gold;
 public:
    Creature(std::string name, char symbol, int health, int strength, int gold)
    : m_name(name), m_symbol(symbol), m_health(health),
      m_strength(strength), m_gold(gold) {}

    std::string getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getStrength() const { return m_strength; }
    int getGold() const { return m_gold; }

    void reduceHealth(int damage);
    bool isDead() const;
    void addGold(int amount);
};

#endif  // SAMPLE_CODE_CPP_CREATURE_H_
