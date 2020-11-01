#include "Board.h"

#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <iostream>

Board::Board(std::vector<Tile> tiles)
{
    float sr = sqrt(tiles.size());
    if(sr - floor(sr) != 0)
        throw "Nombre de tiles invalide (" 
                + std::to_string(tiles.size()) 
                + " n'est pas un carré parfait)";

    this->tiles = tiles;
    this->gridDim = (unsigned)sr;
}

Board::Tile* Board::getTileFromGrid(unsigned gridIndex)
{
    for(int i = 0 ; i < this->tiles.size() ; ++i)
        if(this->tiles[i].gridIndex == gridIndex)
            return &this->tiles[i];
    return nullptr;
}

bool Board::addTileToGrid(const unsigned& tileIndex, const unsigned& gridIndex)
{
    if(tileIndex >= this->tiles.size())
        throw "tileIndex incorrect ("
                + std::to_string(tileIndex) 
                + "), index max : " 
                + std::to_string(this->tiles.size() - 1);

    if(gridIndex >= this->tiles.size())
        throw "gridIndex incorrect (" 
                + std::to_string(gridIndex) 
                + "), index max : " 
                + std::to_string(this->tiles.size() - 1);

    if(this->tiles.at(tileIndex).inGrid)
        throw "La pièce à l'index " 
                + std::to_string(tileIndex) 
                + " est déjà placée";

    if(this->isFilled(gridIndex))
        throw "L'emplacement " 
                + std::to_string(gridIndex) 
                + " de la grille est déjà utilisé";

    Tile& t = tiles.at(tileIndex);

    // // check top tile
    // if(tileIndex >= this->gridDim)
    //     if(t.val.up != this->getTileFromGrid(gridIndex - this->gridDim)->val.down)
    //         return false;

    // // check left tile
    // if(tileIndex % this->gridDim != 0)
    //     if(t.val.right != this->getTileFromGrid(gridIndex - 1)->val.left)
    //         return false;

    // // check right tile
    // if(tileIndex % this->gridDim != this->gridDim - 1)
    //     if(t.val.left != this->getTileFromGrid(gridIndex + 1)->val.right)
    //         return false;

    // // check bottom tile
    // if(tileIndex < (this->gridDim - 1) * this->gridDim)
    //     if(t.val.down != this->getTileFromGrid(gridIndex - this->gridDim)->val.up)
    //         return false;

    // toutes les conditions tetravex sont remplies
    t.inGrid = true;
    t.gridIndex = gridIndex;

    return true;
}

bool Board::isFilled()    
{
    for(const Tile& t : this->tiles)
        if(!t.inGrid)
            return false;
    return true;
}

bool Board::isFilled(const unsigned& gridIndex)
{
    for(const Tile& t : this->tiles)
        if(t.gridIndex == gridIndex)
            return true;
    return false;
}

void Board::print()
{
    std::vector<Tile> placed = this->tiles;

    // supprimer tous les Tide non placés
    std::remove_if(placed.begin(), placed.end(), [](const Tile& t){
        return !t.inGrid;
    });
    
    // trier par ordre croissant selon position dans la grille du tile
    auto cmp = [](const Tile& t1, const Tile& t2){
        return t1.gridIndex > t2.gridIndex;
    };
    std::sort(placed.begin(), placed.end(), cmp);

    // afficher dans l'ordre (comment on gere les trous ?)
    int index = 0;
    for(int i = 0 ; i < this->tiles.size() ; ++i)
    {
        // combler les trous jusqu'à la première pièce placée
        for(index = i ; index < placed.at(i).gridIndex ; ++index)
            // afficher VIDE
            std::cout<<index<<"=>{}"<<std::endl;
        std::cout<<index<<"=>{"<<placed[i].val.left<<","<<placed[i].val.up<<","
                <<placed[i].val.right<<","<<placed[i].val.down<<"}"<<std::endl;
        // afficher placed.at(i).val
    }
}