#include "Creature.h"

#include <string>

Creature::Creature(std::string_view name, char symbol, int health, int attackDmg, int gold)
    :	m_name { name }, m_symbol { symbol }, m_health { health }, m_attackDmg { attackDmg }, m_gold { gold }
{

}

void Creature::addGold(int gold){
    m_gold += gold;
}

void Creature::reduceHealth(int reduceBy) {
    m_health -= reduceBy;
}

bool Creature::isDead() const {
    return m_health <= 0;
}

const std::string_view Creature::getName() const {
    return m_name;
}

char Creature::getSymbol() const {
    return m_symbol;
}

int Creature::getHealth() const {
    return m_health;
}

int Creature::getAttackDmg() const {
    return m_attackDmg;
}

int Creature::getGold() const {
    return m_gold;
}