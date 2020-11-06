#include "Board.h"

#include <iostream>

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
