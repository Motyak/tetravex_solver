#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <stack>

// const struct TileValue NULL_TILE = { 0, 0, 0, 0 };

struct TileValue
{
	unsigned left, up, right, down;
};

class Board
{
  public:
	struct Tile
	{
		TileValue val;
		bool inGrid = false;
		int gridIndex = -1;
	};


  private:
    std::vector<Tile> tiles;

  public:	
	// vector passé par copie pour empecher modification depuis exterieur
	// (pb de 'const&' : init du vector en une ligne => degueulasse)
    Board(std::vector<Tile> tiles);
    ~Board();

	bool addTileToGrid(const unsigned& tileIndex, const unsigned& gridIndex);
    bool isFilled();
    void print();
};
#endif