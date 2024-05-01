#include "Tile.h"

Tile::Tile(int num)
    : m_num {num}
{

}

int Tile::getNum() const {
    return m_num;
}

bool Tile::isEmpty() const {
    return (m_num == 0) ? true : false;
}

std::ostream& operator<<(std::ostream& out, const Tile& tile){
    if(tile.m_num > 9){
        out << " " << tile.m_num << "  ";
    }

    else if(tile.m_num > 0){
        out << "  " << tile.m_num << "  ";
    }

    else if(tile.isEmpty()){
        out << "     ";
    }
    return out;
}
