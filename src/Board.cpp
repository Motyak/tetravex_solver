#include "Board.h"

#include <iostream>

unsigned nbOfInstances = 0;

Board::Board(std::vector<std::shared_ptr<Tile>> tiles)
{
    nbOfInstances++;
    std::cout<<"<<total nb of boards : "<<nbOfInstances<<std::endl;//debug

    unsigned nbOfTiles = tiles.size();
    // verifier que le nombre de tiles est >= 4
    // verifier que le nombre de tiles est un carre parfait

    this->tiles = tiles;

    for(int i = 0 ; i < nbOfTiles ; ++i)
        this->grid.push_back(std::make_shared<Tile>());

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

    // unsigned nbOfTiles = this->tiles.size();
    // for(int i = 0 ; i < nbOfTiles ; ++i)
    // {
    //     if(this->tiles[i] != nullptr)
    //     {
    //         delete this->tiles[i];
    //         this->tiles[i] = nullptr;
    //     }
    //     if(this->grid[i] != nullptr)
    //     {
    //         delete this->grid[i];
    //         this->grid[i] = nullptr;
    //     }
    // }
}
