#include "Board.h"
#include "Direction.h"
#include "Point.h"

void Board::randomize() {
    for(int x { 0 }; x < 1000; ++x){
        if(!moveTile(Direction::getRandomDirection())){
            --x;
        }
    }
}

bool Board::playerWon() const {
    static Board solvedBoard {};
    return *this == solvedBoard;
}

bool Board::isValidPoint(const Point& point) const {
    return ((point.xPos <= m_size - 1) && (point.xPos >= 0)) 
        && ((point.yPos >= 0) && (point.yPos <= m_size - 1));
}

Point Board::getEmptyTilePosition() const {
    for(int row { 0 }; row < Board::m_size; ++row){
        for(int col { 0 }; col < Board::m_size; ++col){
            if(m_board[row][col].isEmpty()){
                return Point { col, row };
            }
        }
    }
}

void Board::swapAdjacentTiles(Point& emptyTile, Point& selectedPoint) {
    std::swap(m_board[emptyTile.yPos][emptyTile.xPos], m_board[selectedPoint.yPos][selectedPoint.xPos]);
}

bool Board::moveTile(Direction direction) {
    Point emptyTile { getEmptyTilePosition() };
    Point selectedPoint { emptyTile.getAdjacentPoint(-direction)};

    if(!isValidPoint(selectedPoint)){
        return false;
    }

    swapAdjacentTiles(emptyTile, selectedPoint);
    return true;   
}

std::ostream& operator<<(std::ostream& out, const Board& board){
    for(int row { 0 }; row < Board::m_size; ++row){
        for(int col { 0 }; col < Board::m_size; ++col){
            out << board.m_board[row][col];
        }

        out << '\n';
    }

    return out;
}

bool operator==(const Board& board1, const Board& board2){
    for (int y { 0 }; y < Board::m_size; ++y){
        for (int x { 0 }; x < Board::m_size; ++x){
            if (board1.m_board[y][x].getNum() != board2.m_board[y][x].getNum()){
                return false; 
            }
        }  
    }
    
    return true;
}
