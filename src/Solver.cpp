#include "Solver.h"

Solver::Solver(const std::string& instanceFileName)
{
    // on ouvre le fichier correspondant (si il existe)

    // on intialise this->currentBoard avec les données du fichier
}

Solver::~Solver()
{
    // on désalloue la stack complète
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

}