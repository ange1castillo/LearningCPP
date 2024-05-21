#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"

#include <iostream>

class Direction;
class Point;

class Board {
    private:
        static constexpr int m_size { 4 };

        Tile m_board[m_size][m_size] {
            {Tile {1}, Tile {2}, Tile {3}, Tile {4}},
            {Tile {5}, Tile {6}, Tile {7}, Tile {8}},
            {Tile {9}, Tile {10}, Tile {11}, Tile {12}},
            {Tile {13}, Tile {14}, Tile {15}, Tile {0}}};

    public:
        Board() = default;

        void randomize();

        bool playerWon() const;

        bool isValidPoint(const Point& point) const;

        Point getEmptyTilePosition() const;

        void swapAdjacentTiles(Point& emptyTile, Point& selectedPoint);

        bool moveTile(Direction direction);

        friend std::ostream& operator<<(std::ostream& out, const Board& board);

        friend bool operator==(const Board& board1, const Board& board2);
};

#endif
