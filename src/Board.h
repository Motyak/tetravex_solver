#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>

struct Tile
{
	unsigned left, up, right, down;
};

struct Board
{
	/*constants, et communs à tous les boards générés*/
	unsigned *width, *height;
	std::vector<std::shared_ptr<Tile>>* tiles;
	/*-----------------------------------------------*/

    std::vector<std::shared_ptr<Tile>> grid;
	unsigned tileToPlace;

    Board(std::vector<std::shared_ptr<Tile>>* tiles, unsigned* width, unsigned* height);
	Board(const Board& board);
	~Board();

	bool isSolved();
	bool tileCanBePlaced(const unsigned& tileIndex, const unsigned& gridIndex);
};
#endif