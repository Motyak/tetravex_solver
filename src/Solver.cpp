#include "Solver.h"

#include <fstream>
#include <iostream>

Solver::Solver(const std::string& instanceFileName)
{
    std::ifstream file(instanceFileName);
    unsigned nbOfTiles;
    file >> this->width;
    file >> this->height;
    nbOfTiles = this->width * this->height;
    std::vector<Tile*> tiles;
    for(int i = 0 ; i < nbOfTiles ; ++i)
    {
        tiles.push_back(new Tile());
        file >> tiles[i]->left;
        file >> tiles[i]->up;
        file >> tiles[i]->right;
        file >> tiles[i]->down;
    }
    this->currentBoard = new Board(tiles);
    file.close();
}

Solver::~Solver()
{
    delete(this->currentBoard);

    // on désalloue la stack complète
    while(!this->stack.empty())
    {
        delete(this->stack.top());
        this->stack.pop();
    }
}

//solve the problem and return the first board configuration found
bool Solver::solve()
{
    // je push dans la stack le plateau non rempli
    this->stack.push(this->currentBoard);

    // tant que la stack n'est pas vide..
    while(!this->stack.empty())
    {
        // on traite la pile
        this->currentBoard = this->stack.top();
        this->stack.pop();
        // si currentBoard est solution, on arrete la
        if(this->boardIsSolved())
            return true;
        else
        {
            // on push dans la stack les différents scénarios possibles (boards)
            unsigned freePosition;
            // Tile* t = this->currentBoard->tiles[this->currentBoard->tileToPlace];
            while(!this->currentBoard->freePositions.empty())
            {
                // on recupere une position libre
                freePosition =  this->currentBoard->freePositions.top();
                // si la tileToPlace est placable a la position..
                if(this->tileCanBePlaced(this->currentBoard->tileToPlace, freePosition))
                {
                    // on enleve l'emplacement utilisé des emplacements libres
                    this->currentBoard->freePositions.pop();
                    // on clone currentBoard et on y ajoute la tile
                    Board* child = new Board(*this->currentBoard);
                    child->grid[freePosition] = child->tiles[child->tileToPlace];
                    child->tileToPlace++;
                    // on l'ajoute à la stack
                    this->stack.push(child);
                    std::cout<<"";//debug
                }
            }
        }
    }
    return false;
}

bool Solver::boardIsSolved()
{
    unsigned nbOfTiles = this->currentBoard->tiles.size();
    for(int i = 0 ; i < nbOfTiles ; ++i)
        if(this->currentBoard->grid[i] == nullptr)
            return false;
    return true;
}

bool Solver::tileCanBePlaced(const unsigned& tileIndex, const unsigned& gridIndex)
{
    Tile* t = this->currentBoard->tiles[tileIndex];

    // check left tile
    if(gridIndex % this->width != 0)
        if(this->currentBoard->grid[gridIndex - 1] != nullptr)
            if(t->right != this->currentBoard->grid[gridIndex - 1]->left)
                return false;

    // check top tile
    if(gridIndex >= this->width)
        if(this->currentBoard->grid[gridIndex - this->width] != nullptr)
            if(t->up != this->currentBoard->grid[gridIndex - this->width]->down)
                return false;

    // check right tile
    if(gridIndex % this->width != this->width - 1)
        if(this->currentBoard->grid[gridIndex + 1] != nullptr)
            if(t->left != this->currentBoard->grid[gridIndex + 1]->right)
                return false;

    // check bottom tile
    if(gridIndex < (this->height - 1) * this->width)
        if(this->currentBoard->grid[gridIndex + this->width] != nullptr)
            if(t->down != this->currentBoard->grid[gridIndex + this->width]->up)
                return false;

    return true;
}

void Solver::printBoard()
{
    unsigned nbOfTiles = this->currentBoard->tiles.size();
    for(int i = 0 ; i < nbOfTiles ; ++i)
    {
        Tile* t = this->currentBoard->grid[i];
        std::cout<<"["<<i<<"] => ";
        if(t == nullptr)
            std::cout<<"<vide>"<<std::endl;
        else
            std::cout<<t->left<<";"<<t->up<<";"<<t->right<<";"<<t->down<<std::endl;
    } 
}