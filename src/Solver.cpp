#include "Solver.h"

#include <fstream>
#include <iostream>
#include <memory>

Solver::Solver(const std::string& instanceFileName)
{
    std::ifstream file(instanceFileName);
    unsigned nbOfTiles;
    file >> this->width;
    file >> this->height;
    nbOfTiles = this->width * this->height;
    std::vector<std::shared_ptr<Tile>> tiles;
    std::vector<std::shared_ptr<Tile>> grid;
    for(int i = 0 ; i < nbOfTiles ; ++i)
    {
        tiles.push_back(std::make_shared<Tile>());
        grid.push_back(std::shared_ptr<Tile>());
        file >> tiles[i]->left;
        file >> tiles[i]->up;
        file >> tiles[i]->right;
        file >> tiles[i]->down;
    }
    this->currentBoard = std::make_shared<Board>(tiles);
    this->currentBoard->grid = grid;
    file.close();
}

Solver::~Solver()
{
    // if(this->currentBoard != nullptr)
    // {
    //         delete this->currentBoard;
    //         this->currentBoard = nullptr;
    // }

    // // on désalloue la stack complète
    // while(!this->stack.empty())
    // {
    //     if(this->stack.top() != nullptr)
    //     {
    //         delete this->stack.top();
    //         this->stack.pop();
    //     }
    // }
}

//solve the problem and return the first board configuration found
bool Solver::solve()
{
    // je push dans la stack le plateau non rempli
    this->stack.push(this->currentBoard);

    // tant que la stack n'est pas vide..
    int compteur = 1;   //debug
    while(!this->stack.empty())
    {
        // on traite la pile
        // while(this->stack.top() == nullptr)
        //     this->stack.pop();
        this->currentBoard = this->stack.top();
        this->stack.pop();

        std::cout<<"debug loop iteration "<<compteur<<std::endl;
        this->printBoard();


        // si currentBoard est solution, on arrete la
        if(this->boardIsSolved())
        {
            // std::cout<<"total nb of boards : "<<nbOfInstances<<std::endl;//debug
            return true;
        }
        else
        {
            std::cout<<"board isnt solved"<<std::endl;
            // on push dans la stack les différents scénarios possibles (boards)
            for(int i = 0 ; i < this->currentBoard->tiles.size() ; ++i)
            {
                std::cout<<"i="<<i<<std::endl;
                // si la tileToPlace est placable a la position..
                if(this->tileCanBePlaced(this->currentBoard->tileToPlace, i))
                {
                    std::cout<<"tile can be placed"<<std::endl;//debug
                    // on clone currentBoard et on y ajoute la tile (et son parent)
                    std::shared_ptr<Board> child = std::make_shared<Board>(*this->currentBoard);
                    child->grid[i] = child->tiles[child->tileToPlace];
                    child->tileToPlace++;
                    child->addParent(this->currentBoard);
                    // on l'ajoute à la stack
                    this->stack.push(child);

                    std::cout<<"child pushed in stack :"<<std::endl;
                    this->printBoard(child.get());
                    std::cout<<"tile to place : "<<child->tileToPlace<<std::endl;
                    //std::cout<<"";//debug gdb break
                }
                // sinon, c'est une dead end
                else
                {
                    // std::cout<<"ca sent la mort"<<std::endl;
                    // // désallouer récursivement boards inutiles
                    // std::shared_ptr<Board> tmp;
                    // std::shared_ptr<Board> parent = this->currentBoard->parent;
                    // this->currentBoard.reset();//
                    // // while(parent != nullptr || parent.get()->nbOfChildren == 1)
                    // // {
                    // //     parent = tmp;
                    // //     parent = tmp.get()->parent;
                    // //     tmp.reset();
                    // // }
                    // std::cout<<"il sort ou pas"<<std::endl;
                }
            }
        }
        // std::cout<<"current board :"<<std::endl;
        // this->printBoard();
        std::cout<<"fin loop iteration "<<compteur<<std::endl<<std::endl;
        ++compteur;
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
    Tile* t = this->currentBoard->tiles[tileIndex].get();

    // si l'emplacement est déjà pris => pas possible
    if(this->currentBoard->grid[gridIndex] != nullptr)
        return false;

    // check left tile
    if(gridIndex % this->width != 0)
        if(this->currentBoard->grid[gridIndex - 1] != nullptr)
            if(t->left != this->currentBoard->grid[gridIndex - 1]->right)
                return false;

    // check top tile
    if(gridIndex >= this->width)
        if(this->currentBoard->grid[gridIndex - this->width] != nullptr)
            if(t->up != this->currentBoard->grid[gridIndex - this->width]->down)
                return false;

    // check right tile
    if(gridIndex % this->width != this->width - 1)
        if(this->currentBoard->grid[gridIndex + 1] != nullptr)
            if(t->right != this->currentBoard->grid[gridIndex + 1]->left)
                return false;

    // check bottom tile
    if(gridIndex < (this->height - 1) * this->width)
        if(this->currentBoard->grid[gridIndex + this->width] != nullptr)
            if(t->down != this->currentBoard->grid[gridIndex + this->width]->up)
                return false;

    return true;
}

void Solver::printBoard(Board* board)
{
    // no argument specified => use this->currentBoard
    if(board == nullptr)
        board = this->currentBoard.get();
    unsigned nbOfTiles = board->tiles.size();
    for(int i = 0 ; i < nbOfTiles ; ++i)
    {
        Tile* t = board->grid[i].get();
        std::cout<<"["<<i<<"] => ";
        if(t == nullptr)
            std::cout<<"<vide>"<<std::endl;
        else
            std::cout<<t->left<<";"<<t->up<<";"<<t->right<<";"<<t->down<<std::endl;
    } 
}