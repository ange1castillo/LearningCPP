#include <iostream>
#include <vector>

class Point {
    private:
        int m_x {};
        int m_y {};

    public:
        Point(int x, int y)
            : m_x { x }, m_y { y }
        {

        }

        friend std::ostream& operator<<(std::ostream& out, const Point& point) {
            return out << "Point(" << point.m_x << ", " << point.m_y << ')';
        }
};

class Shape {
    public:
        virtual std::ostream& print(std::ostream& out) const = 0;
        friend std::ostream& operator<<(std::ostream& out , const Shape& shape) {
            return shape.print(out);
        }
        virtual ~Shape() = default;
};

class Triangle : public Shape {
    private:
        Point m_leftPoint;
        Point m_topPoint;
        Point m_rightPoint;

    public:
        Triangle(const Point& left, const Point& top, const Point& right) 
            :   m_leftPoint { left }, m_topPoint { top }, m_rightPoint { right }
        {

        }


        std::ostream& print(std::ostream& out) const override {
            out << "Triangle(" << m_leftPoint << ", " << m_topPoint << ", " << m_rightPoint << ')';

            return out;
        }
};

class Circle : public Shape {
    private:
        Point m_point;
        int m_radius {};

    public:
        Circle(const Point& point, int radius)
            :   m_point { point }, m_radius { radius }
        {

        }

        std::ostream& print(std::ostream& out) const override {
            out << "Circle(" << m_point << ", radius " << m_radius << ')';

            return out;
        }

        int getRadius() const {
            return m_radius;
        }
};

int getLargestRadius(const std::vector<Shape*>& shapes) {
    int largest { 0 };

    for(auto& shape : shapes){
        if(Circle* c { dynamic_cast<Circle*>(shape) }){
            if(c->getRadius() > largest){
                largest = c->getRadius();
            }
        };
    }

    return largest;
}

int main() {
    std::vector<Shape*> shapes {
        new Circle { Point { 1, 2 }, 7 },
        new Triangle { Point { 1, 2 }, Point { 4, 7 }, Point { 5, 6 } },
        new Circle { Point{ 7, 8 }, 3 }
    };

    for(const auto& shape : shapes) {
        std::cout << *shape << '\n';
    }

    std::cout << "The largest radius is: " << getLargestRadius(shapes) << '\n';
    
    for(const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}