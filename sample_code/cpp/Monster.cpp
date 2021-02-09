#include "Monster.h"
#include "utils.h"
#include <iostream>

const Creature& Monster::getDefaultCreature(Type type) {
    static std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData = {
        { 
            Creature( "Dragon", 'D', 20, 4, 100 ),
            Creature( "Orc", 'O', 4, 2, 25 ),
            Creature( "Slime", 'S', 1, 1, 10 ) 
        }
    };
    
    return monsterData.at(static_cast<std::size_t>(type));
};


Monster Monster::getRandomMonster() {
    int num = getRandomNumber(0, static_cast<int>(Type::max_types) - 1);
    return Monster( static_cast<Type>(num) );
};