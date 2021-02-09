#ifndef MONSTER_H
#define MONSTER_H

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
    Monster(Type type) : Creature(getDefaultCreature(type)) {
        std::cout << "A wild " << m_name << " appeared!\n";
    };

    static Monster getRandomMonster();
};

#endif 