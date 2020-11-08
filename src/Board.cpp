#include "Board.h"

#include <iostream>

unsigned nbOfInstances = 0;

Board::Board(std::vector<std::shared_ptr<Tile>> tiles)
{
    nbOfInstances++;
    std::cout<<"<<total nb of boards : "<<nbOfInstances<<std::endl;//debug

    unsigned nbOfTiles = tiles.size();

    this->tiles = tiles;

    for(int i = 0 ; i < nbOfTiles ; ++i)
    {
        this->grid.push_back(std::make_shared<Tile>());
        this->freePositions.push(i);
    }

    this->tileToPlace = 0;
}

// on pourra laisser celui par défaut apres debuggage
Board::Board(const Board& board)
{
    nbOfInstances++;
    std::cout<<"<<total nb of boards : "<<nbOfInstances<<std::endl;//debug

    this->tiles = board.tiles;
    this->grid = board.grid;
    this->tileToPlace = board.tileToPlace;
}

Board::~Board()
{
    nbOfInstances--;
    std::cout<<"<<total nb of boards : "<<nbOfInstances<<std::endl;//debug
}
