#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"

#include <stack>

class Solver
{
    Board* currentBoard;
    std::stack<Board*> stack;

    Solver(std::string instanceFileName);
    ~Solver();

  public:
    Board* solve();

  private:
	bool boardIsSolved();
	bool tileCanBePlaced(const Tile& t, unsigned i);
};
#endif