#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile {
    private:
        int m_num {};
    
    public:
        explicit Tile(int num);

        int getNum() const;

        bool isEmpty() const;

        friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
};

#endif
