#include "Board.h"

#include <iostream>

unsigned Board::nbOfInstances = 1;

Board::Board(std::vector<Tile*> tiles)
{
    unsigned nbOfTiles = tiles.size();
    // verifier que le nombre de tiles est >= 4
    // verifier que le nombre de tiles est un carre parfait

    this->tiles = tiles;

    for(int i = 0 ; i < nbOfTiles ; ++i)
        this->grid.push_back(nullptr);

    this->tileToPlace = 0;
}

// on pourra laisser celui par défaut apres debuggage
Board::Board(const Board& board)
{
    this->nbOfInstances++;
    std::cout<<"nb de boards : "<<this->nbOfInstances<<std::endl;

    this->tiles = board.tiles;
    this->grid = board.grid;
    this->tileToPlace = board.tileToPlace;
}

Board::~Board()
{
    unsigned nbOfTiles = this->tiles.size();
    for(int i = 0 ; i < nbOfTiles ; ++i)
    {
        if(this->tiles[i] != nullptr)
        {
            delete this->tiles[i];
            this->tiles[i] = nullptr;
        }
        // if(this->grid[i] != nullptr)
        // {
        //     delete this->grid[i];
        //     this->grid[i] = nullptr;
        // }
    }
}
