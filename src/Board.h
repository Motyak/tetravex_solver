#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <stack>
#include <array>

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
	unsigned gridDim;

  public:	
	// vector passé par copie pour empecher modification depuis exterieur
	// (pb de 'const&' : init du vector en une ligne => degueulasse)
    Board(std::vector<Tile> tiles);

	Board::Tile* getTileFromGrid(unsigned gridIndex);

	bool addTileToGrid(const unsigned& tileIndex, const unsigned& gridIndex);
    bool isFilled();
	bool isFilled(const unsigned& gridIndex);
    void print();
};
#endif