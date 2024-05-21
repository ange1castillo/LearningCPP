#include "Player.h"
#include "Potion.h"

#include <string>

Player::Player(std::string_view name)
    :	Creature { name, '@', 15, 1, 0 }
{

}

void Player::levelUp() {
    ++m_level;
    ++m_attackDmg;
}

bool Player::hasWon() const {
    return m_level >= 20;
}

int Player::getLevel() const {
    return m_level;
}

void Player::drinkPotion(const Potion& potion) {
    switch(potion.getType()){
        case Potion::health:
            m_health += potion.getPotion();
            return;
        case Potion::strength:
            m_attackDmg += potion.getPotion();
            return;
        case Potion::poison:
            m_health -= potion.getPotion();
            return;
        case Potion::max_types:
            return;
    }
}