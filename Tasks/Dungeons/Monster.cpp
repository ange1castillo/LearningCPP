#include "Monster.h"
#include "Random.h"

Monster::Monster(Type type)
    :	Creature { MonsterData [type] }
{

}

Monster::Type Monster::getRandomMonster() {
    return static_cast<Type>(Random::get(0, max_types - 1));
}