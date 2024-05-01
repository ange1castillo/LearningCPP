#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>

class Direction {
    public:
        enum Type {
            up,
            down,
            left,
            right,
            max_directions
        };

    private:
        Type m_type {};

    public:
        Direction(Type type);

        Type getType() const;

        static Direction getRandomDirection();

        Direction operator-();

        friend std::ostream& operator<< (std::ostream& out, const Direction& direction);
};

#endif
