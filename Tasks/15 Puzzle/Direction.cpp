#include "Direction.h"
#include "Random.h"

Direction::Direction(Direction::Type type)
    : m_type {type}
{

}

Direction::Type Direction::getType() const { 
    return m_type; 
}

Direction Direction::getRandomDirection() {
    return Direction {static_cast<Direction::Type>(Random::get(0, max_directions - 1))};
}

Direction Direction::operator-(){
    switch(m_type){
        case Direction::up: return Direction { down };
        case Direction::down: return Direction { up };
        case Direction::left: return Direction { right };
        case Direction::right: return Direction { left };
    }
}

std::ostream& operator<<(std::ostream& out, const Direction& direction) {
    switch(direction.m_type){
        case Direction::up: return (out << "up");
        case Direction::down: return (out << "down");
        case Direction::left: return (out << "left");
        case Direction::right: return (out << "right");
    }
}

