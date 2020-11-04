#include "Solver.h"

#include <fstream>
#include <iostream>

Solver::Solver(const std::string& instanceFileName)
{
    std::ifstream file(instanceFileName);
    unsigned length, width, nbOfTiles;
    file >> length;
    file >> width;
    nbOfTiles = length * width;
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
Board* Solver::solve()
{
    // je push dans la stack le plateau non rempli
    this->stack.push(this->currentBoard);

    // tant que la stack n'est pas vide..
    while(!this->stack.empty())
    {
        // on traite la pile
        this->currentBoard = this->stack.top();
        this->stack.pop();
        // si currentBoard est solution..
        if(this->boardIsSolved())
        {
            // on return currentBoard (premiere solution)
            return this->currentBoard;
        }
        else
        {
            // on push dans la stack les différents scénarios possibles (boards)
            unsigned freePosition;
            Tile* t = this->currentBoard->tiles[this->currentBoard->tileToPlace];
            while(!this->currentBoard->freePositions.empty())
            {
                // on recupere une position libre
                freePosition =  this->currentBoard->freePositions.top();
                this->currentBoard->freePositions.pop();
                // si la tileToPlace est placable a la position..
                if(this->tileCanBePlaced(*t, freePosition))
                {
                    // on clone currentBoard et on y ajoute la tile
                    Board* child = new Board(*this->currentBoard);
                    child->grid[freePosition] = child->tiles[child->tileToPlace];
                    child->tileToPlace++;
                    // on l'ajoute à la stack
                    this->stack.push(child);
                } 
            }
        }
    }
}

bool Solver::boardIsSolved()
{
    // stub
    return true;
}

bool Solver::tileCanBePlaced(const Tile& t, unsigned i)
{
    // stub
    return true;
}

void Solver::printBoard()
{
    unsigned nbOfTiles = this->currentBoard->tiles.size();
    for(int i = 0 ; i < nbOfTiles ; ++i)
    {
        Tile* t = this->currentBoard->tiles[i];
        std::cout<<"["<<i<<"] => ";
        std::cout<<t->left<<";"<<t->up<<";"<<t->right<<";"<<t->down<<std::endl;
    } 
}