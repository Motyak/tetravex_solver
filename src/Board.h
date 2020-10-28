#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <stack>

const struct Tile NULL_TILE = {0, 0, 0, 0};

struct Tile
{
    int left;
    int up;
    int right;
    int down;
};

class Board
{
    std::vector<Tile> grid;
    std::vector<Tile> unused;

  public:
    Board(const std::vector<Tile>& tiles);
    ~Board();

    // std::vector<Tile> getGrid();
    // std::vector<Tile> getUnused();

    bool isFilled();    //if unused is empty
    
};
#endif