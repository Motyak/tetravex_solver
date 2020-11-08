#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <queue>
#include <memory>

extern unsigned nbOfInstances;

struct Tile
{
	// unsigned operator[](unsigned i)
	// {
	// 	switch(i)
	// 	{
	// 		case 0: return this->left;
	// 		case 1: return this->up;
	// 		case 2: return this->right;
	// 		case 3: return this->down;
	// 	}
	// }
	unsigned left, up, right, down;
};

class Board
{
  public:	
	// static unsigned nbOfInstances;
	//const
	std::vector<std::shared_ptr<Tile>> tiles;
    std::vector<std::shared_ptr<Tile>> grid;
	std::queue<unsigned> freePositions;
	unsigned tileToPlace;

    Board(std::vector<std::shared_ptr<Tile>> tiles);
	Board(const Board& board);
	~Board();
};
#endif