#include "Creature.h"

void Creature::reduceHealth(int damage) {
    m_health -= damage;
}

bool Creature::isDead() const {
    return (m_health <= 0);
}

void Creature::addGold(int amount) {
    m_gold += amount;
}

