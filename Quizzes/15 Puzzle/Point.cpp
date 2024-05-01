#include "Direction.h"
#include "Point.h"

Point Point::getAdjacentPoint(const Direction& direction) const {
    switch(direction.getType()){
        case Direction::up: return Point { xPos, yPos - 1 };
        case Direction::down: return Point { xPos, yPos + 1 };
        case Direction::left: return Point { xPos - 1, yPos };
        case Direction::right: return { xPos + 1, yPos };
    }
}

bool operator==(const Point& point1, const Point& point2){
    return (point1.xPos == point2.xPos) && (point1.yPos == point2.yPos);
}

bool operator!=(const Point& point1, const Point& point2){
    return !(point1 == point2);
}
