#ifndef POINT_H
#define POINT_H

class Direction;

struct Point {
    public:
        int xPos { 0 };
        int yPos { 0 };

        Point getAdjacentPoint(const Direction& direction) const;

        friend bool operator==(const Point& point1, const Point& point2);

        friend bool operator!=(const Point& point1, const Point& point2);
};

#endif
