// Copyright 2021 Austin Shen

#ifndef SAMPLE_CODE_CPP_MONSTER_H_
#define SAMPLE_CODE_CPP_MONSTER_H_

#include "Creature.h"
#include <array>

class Monster : public Creature {
 public:
    enum class Type {
        Dragon,
        Orc,
        Slime,
        max_types
    };

 private:
    static const Creature& getDefaultCreature(Type type);

 public:
    explicit Monster(Type type) : Creature(getDefaultCreature(type)) {
        std::cout << "A wild " << m_name << " appeared!\n";
    }

    static Monster getRandomMonster();
};

#endif  // SAMPLE_CODE_CPP_MONSTER_H_
