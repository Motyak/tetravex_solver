#include "Board.h"

Board::Board(std::vector<std::shared_ptr<Tile>>* tiles, unsigned* width, unsigned* height)
{
    unsigned nbOfTiles = tiles->size();

    this->tiles = tiles;
    this->width = width;
    this->height = height;

    for(int i = 0 ; i < nbOfTiles ; ++i)
        this->grid.push_back(std::make_shared<Tile>());

    this->tileToPlace = 0;
    this->whereToPlaceTile = -1;
}

Board::Board(const Board& board)
{
    this->tiles = board.tiles;
    this->width = board.width;
    this->height = board.height;
    this->grid = board.grid;
    this->tileToPlace = board.tileToPlace;
    this->whereToPlaceTile = board.whereToPlaceTile;
}

bool Board::isSolved()
{
    return this->tileToPlace >= this->tiles->size();
}

bool Board::tileCanBePlaced()
{
    Tile* t = (*this->tiles)[this->tileToPlace].get();
    unsigned gridIndex = this->whereToPlaceTile;

    // si l'emplacement est déjà pris => pas possible
    if(this->grid[gridIndex] != nullptr)
        return false;

    // check left tile
    if(gridIndex % *this->width != 0)
        if(this->grid[gridIndex - 1] != nullptr)
            if(t->left != this->grid[gridIndex - 1]->right)
                return false;

    // check top tile
    if(gridIndex >= *this->width)
        if(this->grid[gridIndex - *this->width] != nullptr)
            if(t->up != this->grid[gridIndex - *this->width]->down)
                return false;

    // check right tile
    if(gridIndex % *this->width != *this->width - 1)
        if(this->grid[gridIndex + 1] != nullptr)
            if(t->right != this->grid[gridIndex + 1]->left)
                return false;

    // check bottom tile
    if(gridIndex < (*this->height - 1) * *this->width)
        if(this->grid[gridIndex + *this->width] != nullptr)
            if(t->down != this->grid[gridIndex + *this->width]->up)
                return false;

    return true;
}

void Board::nextCandidate()
{
    this->whereToPlaceTile++;
}
