#include "Board.h"

#include <algorithm>

Board::Board(std::vector<Tile> tiles)
{
    // unsigned sr = sqrt(tiles.size());
    // if(sr - floor(sr) != 0)
    //     std::cout<<"err dim non valide"<<std::endl;

    this->tiles = tiles;
}

Board::~Board()
{
    ;
}

bool Board::addTileToGrid(const unsigned& tileIndex, const unsigned& gridIndex)
{
    // si index dépasse taille-1 de tiles => err (index incorrect)
    // si tile.inGrid => err (déjà dans la grid)


    Tile& t = tiles.at(tileIndex);

    // retourne false si le tile ne rentre pas dans la grid (régles tetravex)
    // sinon..
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
        for(index ; index < placed.at(i).gridIndex ; ++index)
            // afficher VIDE
            ;
        // afficher placed.at(i).val

    }
}