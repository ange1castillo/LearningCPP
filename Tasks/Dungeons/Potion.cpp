#include "Potion.h"
#include "Random.h"

#include <string>

Potion::Potion(Type type, Size size)
    :	m_type { type }, m_size { size }
{

}

int Potion::getPotion() const {
    return potions[m_type][m_size];
}

Potion::Type Potion::getType() const {
    return m_type;
}

Potion::Size Potion::getSize() const {
    return m_size;
}

Potion Potion::getRandomPotion() {
    return { static_cast<Type>(Random::get(0, max_types - 1)), static_cast<Size>(Random::get(0, max_sizes - 1)) };
}

std::string_view Potion::getTypeName(Type type) {
    static constexpr std::string_view names[] {
        "Health",
        "Strength",
        "Poison",
    };

    return names[type];
}

std::string_view Potion::getSizeName(Size size) {
    static constexpr std::string_view sizes[] {
        "small",
        "medium",
        "large",
    };

    return sizes[size];
}