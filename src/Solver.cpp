#include "Solver.h"

Solver::Solver(const std::string& instanceFileName)
{
    // on ouvre le fichier correspondant (si il existe)

    // on intialise this->currentBoard avec les données du fichier
}

Solver::~Solver()
{
    // on désalloue la stack complète
    while(!this->stack.empty())
    {
        delete(this->stack->top());
        this->stack->pop();
    }
}

// based on currentBoard, which will be pushed on stack afterwards
Board* Solver::generateChild()
{
    // on clone this->currentBoard

    // on génére un move à partir du clone

    // on push this->currentBoard dans la stack

    // this->currentBoard prend la valeur du clone
}

//just do this->stack.top();
Board* Solver::getParent()
{
    return this->stack.top();
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
        if(this->boardIsSolved)
        {
            // on return currentBoard (premiere solution)
            return this->currentBoard;
        }
        else
        {
            // on push dans la stack les différents scénarios possibles (boards)
            unsigned freePosition;
            Tile& t = this->currentBoard->tileToPlace;
            while(!this->currentBoard->freePositions.empty())
            {
                // on recupere une position libre
                freePosition =  this->currentBoard->freePositions.top();
                this->currentBoard->freePositions.pop();
                // si la tileToPlace est placable a la position..
                if(this->tileCanBePlaced(t, freePosition))
                {
                    // on clone currentBoard et on y ajoute la tile
                    Board* child = new Board(this->currentBoard);
                    child->grid[freePosition] = child->tiles[child->tileToPlace];
                    child->tileToPlace++;
                    // on l'ajoute à la stack
                    this->stack->push(child);
                } 
            }
        }
    }
}