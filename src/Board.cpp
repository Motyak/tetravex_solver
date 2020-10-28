#include "Board.h"

Board::Board(Board* parent) : parent(parent)
{
    this->grid = std::vector<Tile>(parent->getGrid());
    this->unused = std::vector<Tile>(parent->getUnused());
}

Board::Board(const std::vector<Tile>& tiles) : unused(tiles)
{
    // unsigned short sr = sqrt(tiles.size());
    // if(sr - floor(sr) != 0)
    //     std::cout<<"err dim non valide"<<std::endl;
    for(int i = 1 ; i <= tiles.size() ; ++i)
        this->grid.push_back(NULL_TILE);
}

Board::~Board()
{
    ;
}

Board* Board::getParent()
{
    return this->parent;
}

Board* Board::generateChild()
{
    return new Board(this);
}

bool Board::isFilled()    
{
    return this->unused.empty();
}