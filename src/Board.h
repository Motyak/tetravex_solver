#ifndef BOARD_H
#define BOARD_H

#include <vector>

typedef struct 
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
}Tile;

class Board
{
  public:	
	//const
	std::vector<Tile*> tiles;
    std::vector<Tile*> grid;
	unsigned tileToPlace;

    Board(std::vector<Tile*> tiles);
	~Board();
};
#endif