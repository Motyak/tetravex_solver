#include "Solver.h"

#include <fstream>
#include <memory>
#include <iostream>
#include <future>
#include <chrono>

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
    this->tiles = tiles;

    this->currentBoard = std::make_shared<Board>(&this->tiles, &this->width, &this->height);
    this->currentBoard->grid = grid;
    file.close();
}

bool Solver::solve(std::future<void>& fo) { this->solve(this->currentBoard, fo); }

bool Solver::solve(std::shared_ptr<Board>& cur, std::future<void>& fo)
{
    this->stack.push(cur);
    while(!this->stack.empty() && fo.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
    {
        cur = this->stack.top();
        this->stack.pop();

        if(cur->isSolved())
            return true;
        else
        {
            for(int i = 0 ; i < cur->tiles->size() ; ++i)
            {
                if(cur->tileCanBePlaced(i))
                {
                    std::shared_ptr<Board> child = std::make_shared<Board>(*cur);
                    child->grid[i] = (*child->tiles)[child->tileToPlace];
                    child->tileToPlace++;
                    this->stack.push(child);
                }
            }
        }
    }
    return false;
}

void Solver::printBoard() { this->printBoard(this->currentBoard.get()); }

void Solver::printBoard(Board* board)
{
    unsigned nbOfTiles = board->tiles->size();
    for(int i = 0 ; i < nbOfTiles ; ++i)
    {
        auto& t = board->grid[i];
        std::cout<<"["<<i<<"] => ";
        if(t == nullptr)
            std::cout<<"<vide>"<<std::endl;
        else
            std::cout<<t->left<<";"<<t->up<<";"<<t->right<<";"<<t->down<<std::endl;
    } 
}

void Solver::cleanStack()
{
    while(!this->stack.empty())
        this->stack.pop();
}

std::shared_ptr<Board> Solver::getCurrentBoard()
{
    return this->currentBoard;
}