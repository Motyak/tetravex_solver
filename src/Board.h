#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <stack>
#include <array>

typedef struct Tile
{
	unsigned left, up, right, down;
};

class Board
{
  public:	
	//const
	std::vector<Tile*> tiles;
    std::vector<Tile*> grid;
	std::stack<unsigned> freePositions;
	unsigned tileToPlace;

    Board(std::vector<Tile*> tiles);
	~Board();
};
#endif